#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

void connection_print(Connection* connection)
{
    printf("connection id: %s\n", connection->id);
    printf("connection weight: %d\n", connection->weight);
}

void connection_free(Connection* connection)
{
  free(connection);
}

Connections_array* connections_array_create(int total_size)
{
  Connections_array* arr = malloc(sizeof(Connections_array));
  arr->total_size = total_size;
  arr->current_size = 0;
  arr->data = malloc(sizeof(Connection) * arr->total_size);

  return arr;
}

void connections_array_print(Connections_array* connections_array)
{
    for (int i = 0; i < connections_array->current_size; i++)
        connection_print(connections_array->data[i]);
}

void connections_array_free(Connections_array* connections_array)
{
    for (int i = 0; i < connections_array->current_size; i++)
        free(connections_array->data[i]);
    
    free(connections_array->data);
    free(connections_array);
}


int main()
{
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
    

    /* write csv string */
    char csv_string[1000] = "";
    char temp_csv_string[50];

    sprintf(temp_csv_string, "%d\n", connections_array1->current_size);
    strcat(csv_string, temp_csv_string);

    for (int i = 0; i < connections_array1->current_size; i++)
    {
        sprintf(temp_csv_string, "%s,%d\n", connections_array1->data[i]->id, connections_array1->data[i]->weight);
        strcat(csv_string, temp_csv_string);
    }
    printf("csv_string: %s", csv_string);
    printf("\n");



    /* read csv string */
    char deliminator[] = "\n";

    char* str_token = strtok(csv_string, deliminator);
    int expected_array_size;
    sscanf(str_token, "%d\n", &expected_array_size);
    Connections_array* connections_array2 = connections_array_create(expected_array_size);
    str_token = strtok(NULL, deliminator);

    while (str_token != NULL)
    {
        char id[10];
        int weight;
        sscanf(str_token, "%[^,],%d\n", id, &weight);
        Connection* connection2 = connection_create(id, weight);
        connections_array2->data[connections_array2->current_size] = connection2;
        connections_array2->current_size++;

        str_token = strtok(NULL, deliminator);
    }

    if (expected_array_size != connections_array2->current_size)
    {
        printf("ERROR: array size not as expected.");
        return 1;
    }
    
    connections_array_print(connections_array2);


    connections_array_free(connections_array1);
    connections_array_free(connections_array2);

    return 0;
}