#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct
{
    unsigned int size;
    unsigned int max_size;
    int *data;
} Array_int;

Array_int* array_int_create(unsigned int max_size);
void array_int_free(Array_int* arr);
void array_int_print(Array_int* arr);
void array_int_print_detailed(Array_int* arr);
void array_int_resize(Array_int* arr, unsigned int new_max_size);
void array_int_append(Array_int* arr, int new_value);
void array_int_remove_unordered(Array_int* arr, unsigned int index);
void array_int_remove_ordered(Array_int* arr, unsigned int index);
void array_int_set(Array_int* arr, unsigned int index, int new_value);
int array_int_get(Array_int* arr, unsigned int index);


typedef struct
{
    unsigned int size;
    unsigned int max_size;
    float *data;
} Array_float;

Array_float* array_float_create(unsigned int max_size);
void array_float_free(Array_float* arr);
void array_float_print(Array_float* arr);
void array_float_print_detailed(Array_float* arr);
void array_float_resize(Array_float* arr, unsigned int new_max_size);
void array_float_append(Array_float* arr, float new_value);
void array_float_remove_unordered(Array_float* arr, unsigned int index);
void array_float_remove_ordered(Array_float* arr, unsigned int index);
void array_float_set(Array_float* arr, unsigned int index, float new_value);
float array_float_get(Array_float* arr, unsigned int index);