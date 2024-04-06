#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrays4.h"


Array_float* array_float_create(unsigned int max_size)
{
    Array_float* arr = malloc(sizeof(Array_float));
    if (!arr)
    {
        printf("ERROR: Failed to create array\n");
        exit(1);
    }
    arr->max_size = max_size;
    arr->size = 0;

    arr->data = malloc(sizeof(float) * max_size);

    return arr;
}

void array_float_free(Array_float* arr)
{
    free(arr->data);
    free(arr);
}

void array_float_print(Array_float* arr)
{
    printf("{ ");
    for (unsigned int i = 0; i < arr->size; i++)
    {
        printf("%.3f, ", arr->data[i]);
    }
    printf("}\n");
}

void array_float_print_detailed(Array_float* arr)
{
    printf("data     : { ");
    for (unsigned int i = 0; i < arr->size; i++)
    {
        printf("%.3f, ", arr->data[i]);
    }
    printf("}\n");

    printf("data full: { ");
    for (unsigned int i = 0; i < arr->max_size; i++)
    {
        printf("%.3f, ", arr->data[i]);
    }
    printf("}\n");

    printf("size: %d\n", arr->size);
    printf("max size: %d\n", arr->max_size);
}

void array_float_resize(Array_float* arr, unsigned int new_max_size)
{
    arr->data = realloc(arr->data, sizeof(float) * new_max_size);
    if (!arr->data)
    {
        printf("ERROR: Failed to resize array\n");
        exit(1);
    }

    arr->max_size = new_max_size;
}

void array_float_append(Array_float* arr, float new_value)
{
    if (arr->size == arr->max_size)
    {
        unsigned int new_size = arr->max_size + 10;
        array_float_resize(arr, new_size);
    }

    arr->data[arr->size] = new_value;
    arr->size++;
}

void array_float_remove_unordered(Array_float* arr, unsigned int index)
{
    arr->size--;
    arr->data[index] = arr->data[arr->size];

    if (arr->max_size - arr->size == 20)
    {
        unsigned int new_size = arr->max_size - 10;
        array_float_resize(arr, new_size);
    }
}

void array_float_remove_ordered(Array_float* arr, unsigned int index)
{
    for (unsigned int i = index; i < arr->size - 1; i++)
    {
        arr->data[i] = arr->data[i+1];
    }

    arr->size--;

    if (arr->max_size - arr->size == 20)
    {
        unsigned int new_size = arr->max_size - 10;
        array_float_resize(arr, new_size);
    }
}

void array_float_set(Array_float* arr, unsigned int index, float new_value)
{
    if (index >= arr->size)
    {
        printf("ERROR: index not within current array size.\n");
        exit(1);
    }

    arr->data[index] = new_value;
}

float array_float_get(Array_float* arr, unsigned int index)
{
    if (index >= arr->size)
    {
        printf("ERROR: index not within current array size.\n");
        exit(1);
    }

    return arr->data[index];
}