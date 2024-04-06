#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrays3.h"


Array_int* array_int_create(unsigned int allocate_size)
{
    Array_int* arr = malloc(sizeof(Array_int) + sizeof(int) * (allocate_size - 1));
    if (!arr)
    {
        printf("ERROR: Failed to create array\n");
        exit(1);
    }
    arr->allocated_size = allocate_size;
    arr->size = 0;

    return arr;
}

void array_int_free(Array_int* arr)
{
    free(arr);
}

void array_int_print(Array_int* arr)
{
    printf("size: %d\n", arr->size);
    printf("allocated size: %d\n", arr->allocated_size);

    printf("data actual   : ");
    for (unsigned int i = 0; i < arr->size; i++)
    {
        printf("%d, ", arr->data[i]);
    }
    printf("\n");

    printf("data allocated: ");
    for (unsigned int i = 0; i < arr->allocated_size; i++)
    {
        printf("%d, ", arr->data[i]);
    }
    printf("\n");
}

void array_int_resize(Array_int** arr, unsigned int new_allocate_size)
{
    Array_int* new_arr = realloc(*arr, sizeof(Array_int) + sizeof(int) * (new_allocate_size - 1));
    if (!new_arr)
    {
        printf("ERROR: Failed to resize array\n");
        exit(1);
    }

    new_arr->allocated_size = new_allocate_size;
    *arr = new_arr;
}

void array_int_append(Array_int** arr, int new_value)
{
    if ((*arr)->size == (*arr)->allocated_size)
    {
        unsigned int new_size = (*arr)->allocated_size + 10;
        array_int_resize(&(*arr), new_size);
    }

    (*arr)->data[(*arr)->size] = new_value;
    (*arr)->size++;
}

void array_int_remove_unordered(Array_int** arr, unsigned int index)
{
    (*arr)->size--;
    (*arr)->data[index] = (*arr)->data[(*arr)->size];

    if ((*arr)->allocated_size - (*arr)->size == 20)
    {
        unsigned int new_size = (*arr)->allocated_size - 10;
        array_int_resize(&(*arr), new_size);
    }
}

void array_int_remove_ordered(Array_int** arr, unsigned int index)
{
    for (unsigned int i = index; i < (*arr)->size - 1; i++)
    {
        (*arr)->data[i] = (*arr)->data[i+1];
    }

    (*arr)->size--;

    if ((*arr)->allocated_size - (*arr)->size == 20)
    {
        unsigned int new_size = (*arr)->allocated_size - 10;
        array_int_resize(&(*arr), new_size);
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