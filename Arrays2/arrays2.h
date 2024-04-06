#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    float* data;
    int length; 
} Array_1d;

Array_1d* array_1d_create(int length);
void array_1d_assign_range(Array_1d* arr);
void array_1d_assign_random(Array_1d* arr);
float array_1d_get(Array_1d* arr, int index);
void array_1d_set(Array_1d* arr, int index, float new_value);
void array_1d_resize(Array_1d* arr, int new_length);
void array_1d_print(Array_1d* arr);
void array_1d_free(Array_1d* arr);

void array_1d_scalar_add(Array_1d* arr, float x);
void array_1d_scalar_subtract(Array_1d* arr, float x);
void array_1d_scalar_multiply(Array_1d* arr, float x);
void array_1d_scalar_divide(Array_1d* arr, float x);
Array_1d* array_1d_vector_muliply(Array_1d* arr1, Array_1d* arr2);
Array_1d* array_1d_vector_divide(Array_1d* arr1, Array_1d* arr2);
float array_1d_sum(Array_1d* arr);


typedef struct
{
    float** data;
    int dim1;
    int dim2;
    int length; 
} Array_2d;

Array_2d* array_2d_create(int dim1, int dim2);
void array_2d_free(Array_2d* arr);
void array_2d_increase_dim1(Array_2d* arr, int num_new_rows);
void array_2d_increase_dim2(Array_2d* arr, int num_new_columns);
void array_2d_assign_range(Array_2d* arr);
void array_2d_assign_random(Array_2d* arr);
void array_2d_print(Array_2d* arr);

void array_2d_scalar_add(Array_2d* arr, float x);
void array_2d_scalar_subtract(Array_2d* arr, float x);
void array_2d_scalar_multiply(Array_2d* arr, float x);
void array_2d_scalar_divide(Array_2d* arr, float x);
Array_2d* array_2d_vector_muliply(Array_2d* arr1, Array_2d* arr2);
Array_2d* array_2d_vector_divide(Array_2d* arr1, Array_2d* arr2);
float array_2d_sum(Array_2d* arr);