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

    /* write csv string */
    char csv_string[100];
    sprintf(csv_string, "%s, %d\n", connection1->id, connection1->weight);

    printf("csv_string: %s", csv_string);
    printf("\n");


    /* read csv string */
    // char csv_string[] = "hi3uf, 58\n";

    char id[10];
    int weight;
    sscanf(csv_string, "%[^,], %d\n", id, &weight);

    printf("%s\n", id);
    printf("%d\n", weight);
    printf("\n");

    Connection* connection2 = connection_create(id, weight);
    connection_print(connection2);


    return 0;
}