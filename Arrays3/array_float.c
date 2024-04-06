#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrays3.h"


Array_float* array_float_create(unsigned int allocate_size)
{
    Array_float* arr = malloc(sizeof(Array_float) + sizeof(float) * (allocate_size - 1));
    if (!arr)
    {
        printf("ERROR: Failed to create array\n");
        exit(1);
    }
    arr->allocated_size = allocate_size;
    arr->size = 0;

    return arr;
}

void array_float_free(Array_float* arr)
{
    free(arr);
}

void array_float_print(Array_float* arr)
{
    printf("size: %d\n", arr->size);
    printf("allocated size: %d\n", arr->allocated_size);

    printf("data actual   : ");
    for (unsigned int i = 0; i < arr->size; i++)
    {
        printf("%.3f, ", arr->data[i]);
    }
    printf("\n");

    printf("data allocated: ");
    for (unsigned int i = 0; i < arr->allocated_size; i++)
    {
        printf("%.3f, ", arr->data[i]);
    }
    printf("\n");
}

void array_float_resize(Array_float** arr, unsigned int new_allocate_size)
{
    Array_float* new_arr = realloc(*arr, sizeof(Array_float) + sizeof(float) * (new_allocate_size - 1));
    if (!new_arr)
    {
        printf("ERROR: Failed to resize array\n");
        exit(1);
    }

    new_arr->allocated_size = new_allocate_size;
    *arr = new_arr;
}

void array_float_append(Array_float** arr, float new_value)
{
    if ((*arr)->size == (*arr)->allocated_size)
    {
        unsigned int new_size = (*arr)->allocated_size + 10;
        array_float_resize(&(*arr), new_size);
    }

    (*arr)->data[(*arr)->size] = new_value;
    (*arr)->size++;
}

void array_float_remove_unordered(Array_float** arr, unsigned int index)
{
    (*arr)->size--;
    (*arr)->data[index] = (*arr)->data[(*arr)->size];

    if ((*arr)->allocated_size - (*arr)->size == 20)
    {
        unsigned int new_size = (*arr)->allocated_size - 10;
        array_float_resize(&(*arr), new_size);
    }
}

void array_float_remove_ordered(Array_float** arr, unsigned int index)
{
    for (unsigned int i = index; i < (*arr)->size - 1; i++)
    {
        (*arr)->data[i] = (*arr)->data[i+1];
    }

    (*arr)->size--;

    if ((*arr)->allocated_size - (*arr)->size == 20)
    {
        unsigned int new_size = (*arr)->allocated_size - 10;
        array_float_resize(&(*arr), new_size);
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