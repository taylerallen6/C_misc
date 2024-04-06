#include <stdio.h>
#include <stdlib.h>
#include "array_list1.h"
#include "array_list_float.h"


typedef struct
{
    Array_list** memory_ids;
    Array_list_float** memory_weights;
    int length; 
} Memory_connection_array;


Memory_connection_array* Memory_connection_array_create(int length)
{
    Memory_connection_array* arr = malloc(sizeof(Memory_connection_array));
    arr->length = length;
    arr->memory_ids = malloc(sizeof(Array_list*) * arr->length);
    arr->memory_weights = malloc(sizeof(Array_list_float*) * arr->length);

    for (int i = 0; i < arr->length; i++)
    {
        arr->memory_ids[i] = array_list_create(3);
        arr->memory_weights[i] = array_list_float_create(3);
    }

    return arr;
}

void memory_connection_array_free(Memory_connection_array* arr)
{
    for (int i = 0; i < arr->length; i++)
    {
        array_list_free(arr->memory_ids[i]);
        array_list_float_free(arr->memory_weights[i]);
    }

    free(arr->memory_ids);
    free(arr);
}

void memory_connection_array_resize(Memory_connection_array* arr, int new_length)
{
    float* new_memory_ids;
    if (new_memory_ids = realloc(arr->memory_ids, sizeof(float) * new_length))
    {
        arr->memory_ids = new_memory_ids;
        arr->length = new_length;
    }
    else
        printf("ERROR: could not reallocate memory\n");
}

void memory_connection_array_print(Memory_connection_array* arr)
{
    printf("{ ");
    for (int i = 0; i < arr->length; i++)
    {
        printf("%.2f, ", arr->memory_ids[i]);
    }
    printf("}\n");
}


int main()
{

    return 0;
}