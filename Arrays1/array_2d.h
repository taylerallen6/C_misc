#include "array_1d.h"


typedef struct
{
  float* data;
  int dim1;
  int dim2;
  int length; 
} Array_2d;

Array_2d* array_2d_create(int dim1, int dim2);
void array_2d_assign_range(Array_2d* arr);
void array_2d_assign_random(Array_2d* arr);
float array_2d_get(Array_2d* arr, int index1, int index2);
void array_2d_set(Array_2d* arr, int index1, int index2, float new_value);
void array_2d_reshape(Array_2d* arr, int new_dim1, int new_dim2);
void array_2d_resize(Array_2d* arr, int new_length);
Array_1d* array_2d_row_get(Array_2d* arr, int row);
Array_1d* array_2d_column_get(Array_2d* arr, int column);

void array_2d_print(Array_2d* arr);
void array_2d_free(Array_2d* arr);

void array_2d_scalar_add(Array_2d* arr, float x);
void array_2d_scalar_subtract(Array_2d* arr, float x);
void array_2d_scalar_multiply(Array_2d* arr, float x);
void array_2d_scalar_divide(Array_2d* arr, float x);
Array_2d* array_2d_vector_muliply(Array_2d* arr1, Array_2d* arr2);
Array_2d* array_2d_vector_divide(Array_2d* arr1, Array_2d* arr2);
float array_2d_sum(Array_2d* arr);