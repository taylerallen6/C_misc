#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <hiredis/hiredis.h>


typedef struct
{
    char id[10];
    int weight;
    int order_position;
} Memory_connection;

typedef struct
{
  Memory_connection** data;
  int total_size;
  int current_size;
} Memory_connections;

Memory_connection* memory_connection_create(char* id, int weight, int order_position);
void memory_connection_free(Memory_connection* memory_connection);
void memory_connection_print(Memory_connection* memory_connection);

Memory_connections* memory_connections_create(int total_size);
void memory_connections_free(Memory_connections* memory_connections);
void memory_connections_print(Memory_connections* memory_connections);

char* memory_connections_serialize(Memory_connections* memory_connections);
Memory_connections* memory_connections_deserialize(char* csv_string);