#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char id[10];
    int weight; 
} Connection;

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

int main()
{
    Connection* connection1 = connection_create("h24r", 10);
    connection_print(connection1);

    Connection* connection2 = connection_create("ak82rg", 35);
    connection_print(connection2);

    return 0;
}