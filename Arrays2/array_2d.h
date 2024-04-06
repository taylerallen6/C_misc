#include <stdio.h>
#include <stdlib.h>


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