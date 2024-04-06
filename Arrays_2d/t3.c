#include <stdio.h>
#include <stdlib.h>


typedef struct
{
  float* data;
  int dim1;
  int dim2;
  int length; 
} Array_2d;

Array_2d array_2d_create(int dim1, int dim2)
{
  Array_2d arr;
  arr.length = dim1 * dim2;
  arr.dim1 = dim1;
  arr.dim2 = dim2;

  arr.data = calloc(sizeof(float), arr.length);

  return arr;
}

void array_2d_assign_range(Array_2d arr)
{
  for (int i = 0; i < arr.length; i++)
    arr.data[i] = (float)i;
}

void array_2d_assign_random(Array_2d arr)
{
  float rand_value;

  for (int i = 0; i < arr.length; i++)
  {
    rand_value = (float)rand() / (float)RAND_MAX;
    arr.data[i] = rand_value;
  }
}

float array_2d_get(Array_2d arr, int index1, int index2)
{
  int real_index = (index1 * arr.dim2) + index2;

  return arr.data[real_index];
}

void array_2d_set(Array_2d arr, int index1, int index2, float new_value)
{
  int real_index = (index1 * arr.dim2) + index2;
  arr.data[real_index] = new_value;
}

Array_2d array_2d_reshape(Array_2d arr, int new_dim1, int new_dim2)
{
  if ((new_dim1 * new_dim2) == arr.length)
  {
    arr.dim1 = new_dim1;
    arr.dim2 = new_dim2;
  }
  else
    printf("ERROR: cannot use those dimensions for array of length %d\n", arr.length);

  return arr;
}

Array_2d array_2d_resize(Array_2d arr, int new_length)
{
  float* new_data;
  if (new_data = realloc(arr.data, sizeof(float) * new_length))
  {
    arr.data = new_data;
    arr.length = new_length;
    arr.dim1 = 1;
    arr.dim2 = new_length;
  }
  else
  {
    printf("ERROR: could not reallocate memory\n");
  }

  return arr;
}

void array_2d_row_get(Array_2d arr, int row)
{
  Array_2d new_arr = array_2d_create(1, arr.dim2);
  int start_index = row * arr.dim2;

  for (int i = 0; i < arr.dim2; i++)
  {
    int real_index = i + start_index;
    new_arr.data[i] = arr.data[real_index];
  }

  return new_arr;
}

void array_2d_column_get(Array_2d arr, int column)
{
  Array_2d new_arr = array_2d_create(1, arr.dim1);
  int start_index = column;

  for (int i = 0; i < arr.dim1; i++)
  {
    int real_index = start_index + (i * arr.dim2);
    new_arr.data[i] = arr.data[real_index];
  }

  return new_arr;
}

void array_2d_print(Array_2d arr)
{
  for (int i1 = 0; i1 < arr.dim1; i1++)
  {
    printf("{ ");
    for (int i2 = 0; i2 < arr.dim2; i2++)
    {
      int index = (i1 * arr.dim2) + i2;
      printf("%.2f, ", arr.data[index]);
    }
    printf("}\n");
  }
}

void array_2d_free(Array_2d arr)
{
  free(arr.data);
}


void array_2d_scalar_add(Array_2d arr, float x)
{
  for (int i = 0; i < arr.length; i++)
    arr.data[i] += x;
}

void array_2d_scalar_subtract(Array_2d arr, float x)
{
  for (int i = 0; i < arr.length; i++)
    arr.data[i] -= x;
}

void array_2d_scalar_multiply(Array_2d arr, float x)
{
  for (int i = 0; i < arr.length; i++)
    arr.data[i] *= x;
}

void array_2d_scalar_divide(Array_2d arr, float x)
{
  for (int i = 0; i < arr.length; i++)
    arr.data[i] /= x;
}

Array_2d array_2d_vector_muliply(Array_2d arr1, Array_2d arr2)
{
  Array_2d new_arr = array_2d_create(arr1.dim1, arr1.dim2);

  for (int i = 0; i < new_arr.length; i++)
    new_arr.data[i] = arr1.data[i] * arr2.data[i];

  return new_arr;
}

Array_2d array_2d_vector_divide(Array_2d arr1, Array_2d arr2)
{
  Array_2d new_arr = array_2d_create(arr1.dim1, arr1.dim2);

  for (int i = 0; i < new_arr.length; i++)
    new_arr.data[i] = arr1.data[i] / arr2.data[i];

  return new_arr;
}

float array_2d_sum(Array_2d arr)
{
  float sum_value;

  for (int i = 0; i < arr.length; i++)
    sum_value += arr.data[i];

  return sum_value;
}


int main()
{
  Array_2d arr1 = array_2d_create(3,5);
  array_2d_print(arr1);
  printf("\n");

  array_2d_assign_range(arr1);
  array_2d_print(arr1);
  printf("\n");

  // array_2d_scalar_add(arr1, 4.0);
  // array_2d_print(arr1);
  // printf("\n");

  // array_2d_scalar_subtract(arr1, 3.0);
  // array_2d_print(arr1);
  // printf("\n");

  // array_2d_scalar_multiply(arr1, 5.0);
  // array_2d_print(arr1);
  // printf("\n");

  // array_2d_scalar_divide(arr1, 3.0);
  // array_2d_print(arr1);
  // printf("\n");

  array_2d_assign_random(arr1);
  array_2d_print(arr1);
  printf("\n");

  // array_2d_row_get(arr1, 2);
  // array_2d_column_get(arr1, 4);

  // Array_2d arr2 = array_2d_create(3,5);
  // array_2d_assign_random(arr2);

  // Array_2d arr3 = array_2d_vector_muliply(arr1, arr2);

  // printf("Matrix Multiply:\n");
  // printf("array 1:\n");
  // array_2d_print(arr1);
  // printf("\n");
  // printf("array 2:\n");
  // array_2d_print(arr2);
  // printf("\n");
  // printf("results:\n");
  // array_2d_print(arr3);


  // printf("\n");
  // array_2d_assign_random(arr2);

  // arr3 = array_2d_vector_divide(arr1, arr2);

  // printf("Matrix Divide:\n");
  // printf("array 1:\n");
  // array_2d_print(arr1);
  // printf("\n");
  // printf("array 2:\n");
  // array_2d_print(arr2);
  // printf("\n");
  // printf("results:\n");
  // array_2d_print(arr3);

  // printf("\n");
  // printf("\n");

  // array_2d_assign_range(arr1);
  // float sum = array_2d_sum(arr1);
  // printf("%f\n", sum);


  array_2d_free(arr1);
  // array_2d_free(arr2);
  // array_2d_free(arr3);


  return 0;
}