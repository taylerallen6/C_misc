#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrays4.h"


Array_int* array_int_create(unsigned int max_size)
{
    Array_int* arr = malloc(sizeof(Array_int));
    if (!arr)
    {
        printf("ERROR: Failed to create array\n");
        exit(1);
    }
    arr->max_size = max_size;
    arr->size = 0;

    arr->data = malloc(sizeof(int) * max_size);

    return arr;
}

void array_int_free(Array_int* arr)
{
    free(arr->data);
    free(arr);
}

void array_int_print(Array_int* arr)
{
    printf("{ ");
    for (unsigned int i = 0; i < arr->size; i++)
    {
        printf("%d, ", arr->data[i]);
    }
    printf("}\n");
}

void array_int_print_detailed(Array_int* arr)
{
    printf("data     : { ");
    for (unsigned int i = 0; i < arr->size; i++)
    {
        printf("%d, ", arr->data[i]);
    }
    printf("}\n");

    printf("data full: { ");
    for (unsigned int i = 0; i < arr->max_size; i++)
    {
        printf("%d, ", arr->data[i]);
    }
    printf("}\n");

    printf("size: %d\n", arr->size);
    printf("max size: %d\n", arr->max_size);
}

void array_int_resize(Array_int* arr, unsigned int new_max_size)
{
    arr->data = realloc(arr->data, sizeof(int) * new_max_size);
    if (!arr->data)
    {
        printf("ERROR: Failed to resize array\n");
        exit(1);
    }

    arr->max_size = new_max_size;
}

void array_int_append(Array_int* arr, int new_value)
{
    if (arr->size == arr->max_size)
    {
        unsigned int new_size = arr->max_size + 10;
        array_int_resize(arr, new_size);
    }

    arr->data[arr->size] = new_value;
    arr->size++;
}

void array_int_remove_unordered(Array_int* arr, unsigned int index)
{
    arr->size--;
    arr->data[index] = arr->data[arr->size];

    if (arr->max_size - arr->size == 20)
    {
        unsigned int new_size = arr->max_size - 10;
        array_int_resize(arr, new_size);
    }
}

void array_int_remove_ordered(Array_int* arr, unsigned int index)
{
    for (unsigned int i = index; i < arr->size - 1; i++)
    {
        arr->data[i] = arr->data[i+1];
    }

    arr->size--;

    if (arr->max_size - arr->size == 20)
    {
        unsigned int new_size = arr->max_size - 10;
        array_int_resize(arr, new_size);
    }
}

void array_int_set(Array_int* arr, unsigned int index, int new_value)
{
    if (index >= arr->size)
    {
        printf("ERROR: index not within current array size.\n");
        exit(1);
    }

    arr->data[index] = new_value;
}

int array_int_get(Array_int* arr, unsigned int index)
{
    if (index >= arr->size)
    {
        printf("ERROR: index not within current array size.\n");
        exit(1);
    }

    return arr->data[index];
}