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
    Connection* connections_array1[3];

    Connection* new_connection = connection_create("h24r", 10);
    connections_array1[0] = new_connection;
    new_connection = connection_create("wkrugf", 235);
    connections_array1[1] = new_connection;
    new_connection = connection_create("874gf", 20);
    connections_array1[2] = new_connection;

    for (int i = 0; i < 3; i++)
    {
        connection_print(connections_array1[i]);
    }
    
    

    /* write csv string */
    char csv_string[100] = "";
    char temp_csv_string[100];
    for (int i = 0; i < 3; i++)
    {
        temp_csv_string[100];
        sprintf(temp_csv_string, "%s,%d\n", connections_array1[i]->id, connections_array1[i]->weight);
        strcat(csv_string, temp_csv_string);
    }
    printf("csv_string: %s", csv_string);
    printf("\n");



    /* read csv string */
    Connection* connections_array2[3];

    char deliminator[] = "\n";

    char* str_token = strtok(csv_string, deliminator);
    int i = 0;
    while (str_token != NULL)
    {
        char id[10];
        int weight;
        sscanf(str_token, "%[^,],%d\n", id, &weight);
        Connection* connection2 = connection_create(id, weight);
        connections_array2[i] = connection2;

        str_token = strtok(NULL, deliminator);
        i++;
    }
    
    for (int i = 0; i < 3; i++)
        connection_print(connections_array2[i]);


    for (int i = 0; i < 3; i++)
    {
        free(connections_array1[i]);
        free(connections_array2[i]);
    }

    return 0;
}