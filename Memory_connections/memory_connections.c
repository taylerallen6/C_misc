#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <hiredis/hiredis.h>
#include "memory_connections.h"


Memory_connection* memory_connection_create(char* id, int weight, int order_position)
{
    Memory_connection* new_memory_connection = malloc(sizeof(Memory_connection));
    strcpy(new_memory_connection->id, id);
    new_memory_connection->weight = weight;
    new_memory_connection->order_position = order_position;

    return new_memory_connection;
}

void memory_connection_free(Memory_connection* memory_connection)
{
  free(memory_connection);
}

void memory_connection_print(Memory_connection* memory_connection)
{
    printf("memory_connection id: %s\n", memory_connection->id);
    printf("memory_connection weight: %d\n", memory_connection->weight);
    printf("memory_connection order_position: %d\n", memory_connection->order_position);
}


Memory_connections* memory_connections_create(int total_size)
{
  Memory_connections* arr = malloc(sizeof(Memory_connections));
  arr->total_size = total_size;
  arr->current_size = 0;
  arr->data = malloc(sizeof(Memory_connection) * arr->total_size);

  return arr;
}

void memory_connections_free(Memory_connections* memory_connections)
{
    for (int i = 0; i < memory_connections->current_size; i++)
        free(memory_connections->data[i]);
    
    free(memory_connections->data);
    free(memory_connections);
}

void memory_connections_print(Memory_connections* memory_connections)
{
    for (int i = 0; i < memory_connections->current_size; i++)
        memory_connection_print(memory_connections->data[i]);
}


char* memory_connections_serialize(Memory_connections* memory_connections)
{
    /* write csv string */
    char* csv_string = malloc(sizeof(char) * 50 * memory_connections->current_size);
    *csv_string = '\0';
    char* temp_csv_string = malloc(sizeof(char) * 50);

    sprintf(temp_csv_string, "%d\n", memory_connections->current_size);
    strcat(csv_string, temp_csv_string);

    for (int i = 0; i < memory_connections->current_size; i++)
    {
        sprintf(temp_csv_string, "%s,%d,%d\n", memory_connections->data[i]->id, memory_connections->data[i]->weight, memory_connections->data[i]->order_position);
        strcat(csv_string, temp_csv_string);
    }

    return csv_string;
}

Memory_connections* memory_connections_deserialize(char* csv_string)
{
    /* read csv string */
    char deliminator[] = "\n";

    char* str_token = strtok(csv_string, deliminator);
    int expected_array_size;
    sscanf(str_token, "%d\n", &expected_array_size);
    Memory_connections* new_memory_connections = memory_connections_create(expected_array_size);
    str_token = strtok(NULL, deliminator);

    while (str_token != NULL)
    {
        char id[10];
        int weight;
        int order_position;
        sscanf(str_token, "%[^,],%d,%d\n", id, &weight, &order_position);
        Memory_connection* new_memory_connection = memory_connection_create(id, weight, order_position);
        new_memory_connections->data[new_memory_connections->current_size] = new_memory_connection;
        new_memory_connections->current_size++;

        str_token = strtok(NULL, deliminator);
    }

    if (expected_array_size != new_memory_connections->current_size)
        printf("ERROR: array size not as expected.");

    return new_memory_connections;
}

char* memory_connections_store_redis(redisContext *redis_connection, Memory_connections* memory_connections)
{
    /* generate memory_id */
    srand(time(NULL)); // define a seed for the random number generator
    int num_random_chars = 10;
    char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEHGHIJKLMNOPQRSTUVWXYZ1234567890";
    char random_string[num_random_chars+1];

    int i2 = 0;
    int num_allowed_chars = sizeof(allowed_chars) - 1;
    for (int i = 0; i < num_random_chars; i++) {
        i2 = rand() % num_allowed_chars;
        random_string[i] = allowed_chars[i2];
    }
    random_string[num_random_chars] = '\0';
    // printf("random_string: %s\n", random_string);

    char* memory_id = malloc(sizeof(char) * 20);
    strcpy(memory_id, "memory:");
    strcat(memory_id, random_string);
    // printf("memory_id: %s\n", memory_id);


    /* serialize memory_connections array */
    char* csv_string = memory_connections_serialize(memory_connections);
    printf("csv_string: %s", csv_string);
    // printf("\n");


    /* store memory_connections array in redis as memory */
    redisReply *reply;
    reply = redisCommand(redis_connection, "SET %s %s", memory_id, csv_string);
    // printf("RESPONSE: %s\n", reply->str);
    freeReplyObject(reply);
    // printf("\n");

    free(csv_string);

    return memory_id;
}

Memory_connections* memory_connections_get_redis(redisContext *redis_connection, char* memory_id)
{
    /* get memory back from redis */
    redisReply *reply;
    reply = redisCommand(redis_connection, "GET %s", memory_id);
    char new_csv_string[strlen(reply->str)];
    strcpy(new_csv_string, reply->str);
    freeReplyObject(reply);

    printf("new_csv_string: %s\n", new_csv_string);

    /* deserialize memory_connections array */
    Memory_connections* new_memory_connections = memory_connections_deserialize(new_csv_string);

    return new_memory_connections;
}


int main()
{
    /* create redis db connection */
    redisReply *reply;
    redisContext *redis_connection;

    redis_connection = redisConnect("127.0.0.1", 6379);
    if (redis_connection->err) {
        printf("error: %s\n", redis_connection->errstr);
        return 1;
    }


    /* create memory_connections array for memory */
    Memory_connections* memory_connections1 = memory_connections_create(10);

    Memory_connection* new_memory_connection;
    new_memory_connection = memory_connection_create("h24r", 10, 0);
    memory_connections1->data[0] = new_memory_connection;
    memory_connections1->current_size++;
    new_memory_connection = memory_connection_create("wkrugf", 235, 2);
    memory_connections1->data[1] = new_memory_connection;
    memory_connections1->current_size++;
    new_memory_connection = memory_connection_create("874gf", 20, 1);
    memory_connections1->data[2] = new_memory_connection;
    memory_connections1->current_size++;
    new_memory_connection = memory_connection_create("3fjg", 482, -1);
    memory_connections1->data[3] = new_memory_connection;
    memory_connections1->current_size++;

    memory_connections_print(memory_connections1);
    printf("\n");


    /* store memory connections */
    char* memory_id = memory_connections_store_redis(redis_connection, memory_connections1);
    printf("memory_id: %s\n", memory_id);
    printf("\n");


    /* get memory connections */
    Memory_connections* memory_connections2 = memory_connections_get_redis(redis_connection, memory_id);
    memory_connections_print(memory_connections2);


    memory_connections_free(memory_connections1);
    free(memory_id);
    memory_connections_free(memory_connections2);

    return 0;
}