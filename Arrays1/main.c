#include <stdio.h>
#include <stdlib.h>
// #include "array_1d.h"
#include "array_2d.h"


int main()
{
  Array_2d* arr1 = array_2d_create(3,5);
  array_2d_print(arr1);
  printf("\n");

  array_2d_assign_range(arr1);
  array_2d_print(arr1);
  printf("\n");

  array_2d_scalar_add(arr1, 4.0);
  array_2d_print(arr1);
  printf("\n");

  array_2d_scalar_subtract(arr1, 3.0);
  array_2d_print(arr1);
  printf("\n");

  array_2d_scalar_multiply(arr1, 5.0);
  array_2d_print(arr1);
  printf("\n");

  array_2d_scalar_divide(arr1, 3.0);
  array_2d_print(arr1);
  printf("\n");

  array_2d_assign_random(arr1);
  array_2d_print(arr1);
  printf("\n");

  Array_1d* arr_1d_1 = array_2d_row_get(arr1, 2);
  Array_1d* arr_1d_2 = array_2d_column_get(arr1, 4);

  array_1d_print(arr_1d_1);
  array_1d_print(arr_1d_2);
  printf("\n");

  array_1d_free(arr_1d_1);
  array_1d_free(arr_1d_2);


  Array_2d* arr2 = array_2d_create(3,5);
  array_2d_assign_random(arr2);

  Array_2d* arr3 = array_2d_vector_muliply(arr1, arr2);

  printf("Matrix Multiply:\n");
  printf("array 1:\n");
  array_2d_print(arr1);
  printf("\n");
  printf("array 2:\n");
  array_2d_print(arr2);
  printf("\n");
  printf("results:\n");
  array_2d_print(arr3);


  printf("\n");
  array_2d_assign_random(arr2);

  arr3 = array_2d_vector_divide(arr1, arr2);

  printf("Matrix Divide:\n");
  printf("array 1:\n");
  array_2d_print(arr1);
  printf("\n");
  printf("array 2:\n");
  array_2d_print(arr2);
  printf("\n");
  printf("results:\n");
  array_2d_print(arr3);

  printf("\n");

  array_2d_assign_range(arr1);
  float sum = array_2d_sum(arr1);
  printf("sum: %f\n", sum);

  printf("\n");

  array_2d_reshape(arr1, 5,3);
  array_2d_print(arr1);

  printf("\n");

  Array_1d* arr_1d = array_1d_create(5);
  array_1d_assign_random(arr_1d);
  array_1d_print(arr_1d);

  float arr_1d_sum = array_1d_sum(arr_1d);
  printf("sum: %.2f\n", arr_1d_sum);


  array_1d_free(arr_1d);
  array_2d_free(arr1);
  array_2d_free(arr2);
  array_2d_free(arr3);


  return 0;
}