#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hiredis/hiredis.h>


typedef struct
{
    char id[10];
    int weight; 
} Connection;

typedef struct
{
  Connection** data;
  int total_size;
  int current_size;
} Connections_array;


Connection* connection_create(char* id, int weight)
{
    Connection* new_connection = malloc(sizeof(Connection));
    strcpy(new_connection->id, id);
    new_connection->weight = weight;

    return new_connection;
}

void connection_free(Connection* connection)
{
  free(connection);
}

void connection_print(Connection* connection)
{
    printf("connection id: %s\n", connection->id);
    printf("connection weight: %d\n", connection->weight);
}


Connections_array* connections_array_create(int total_size)
{
  Connections_array* arr = malloc(sizeof(Connections_array));
  arr->total_size = total_size;
  arr->current_size = 0;
  arr->data = malloc(sizeof(Connection) * arr->total_size);

  return arr;
}

void connections_array_free(Connections_array* connections_array)
{
    for (int i = 0; i < connections_array->current_size; i++)
        free(connections_array->data[i]);
    
    free(connections_array->data);
    free(connections_array);
}

void connections_array_print(Connections_array* connections_array)
{
    for (int i = 0; i < connections_array->current_size; i++)
        connection_print(connections_array->data[i]);
}


char* connections_array_serialize(Connections_array* connections_array)
{
    /* write csv string */
    char* csv_string = malloc(sizeof(char) * 50 * connections_array->current_size);
    *csv_string = '\0';
    char* temp_csv_string = malloc(sizeof(char) * 50);

    sprintf(temp_csv_string, "%d\n", connections_array->current_size);
    strcat(csv_string, temp_csv_string);

    for (int i = 0; i < connections_array->current_size; i++)
    {
        sprintf(temp_csv_string, "%s,%d\n", connections_array->data[i]->id, connections_array->data[i]->weight);
        strcat(csv_string, temp_csv_string);
    }

    return csv_string;
}

Connections_array* connections_array_deserialize(char* csv_string)
{
    /* read csv string */
    char deliminator[] = "\n";

    char* str_token = strtok(csv_string, deliminator);
    int expected_array_size;
    sscanf(str_token, "%d\n", &expected_array_size);
    Connections_array* new_connections_array = connections_array_create(expected_array_size);
    str_token = strtok(NULL, deliminator);

    while (str_token != NULL)
    {
        char id[10];
        int weight;
        sscanf(str_token, "%[^,],%d\n", id, &weight);
        Connection* new_connection = connection_create(id, weight);
        new_connections_array->data[new_connections_array->current_size] = new_connection;
        new_connections_array->current_size++;

        str_token = strtok(NULL, deliminator);
    }

    if (expected_array_size != new_connections_array->current_size)
        printf("ERROR: array size not as expected.");

    return new_connections_array;
}


int main()
{
    /* create redis db connection */
    redisReply *reply;
    redisContext *c;

    c = redisConnect("127.0.0.1", 6379);
    if (c->err) {
        printf("error: %s\n", c->errstr);
        return 1;
    }


    /* create connections array for memory */
    Connections_array* connections_array1 = connections_array_create(10);

    Connection* new_connection;
    new_connection = connection_create("h24r", 10);
    connections_array1->data[0] = new_connection;
    connections_array1->current_size++;
    new_connection = connection_create("wkrugf", 235);
    connections_array1->data[1] = new_connection;
    connections_array1->current_size++;
    new_connection = connection_create("874gf", 20);
    connections_array1->data[2] = new_connection;
    connections_array1->current_size++;
    new_connection = connection_create("3fjg", 482);
    connections_array1->data[3] = new_connection;
    connections_array1->current_size++;

    connections_array_print(connections_array1);
    printf("\n");
    

    /* serialize connections array */
    char* csv_string = connections_array_serialize(connections_array1);
    printf("csv_string: %s", csv_string);
    printf("\n");

    /* store connections array in redis as memory */
    reply = redisCommand(c, "SET %s %s", "memory:4h35wrb", csv_string);
    printf("RESPONSE: %s\n", reply->str);
    freeReplyObject(reply);
    printf("\n");

    /* get memory back from redis */
    reply = redisCommand(c, "GET %s", "memory:4h35wrb");
    char new_csv_string[strlen(reply->str)];
    strcpy(new_csv_string, reply->str);
    freeReplyObject(reply);

    printf("new_csv_string: %s\n", new_csv_string);

    /* deserialize connections array */
    Connections_array* connections_array2 = connections_array_deserialize(new_csv_string);
    connections_array_print(connections_array2);


    connections_array_free(connections_array1);
    free(csv_string);
    connections_array_free(connections_array2);

    return 0;
}