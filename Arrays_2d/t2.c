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
    printf("ERROR: could now reallocate memory\n");
  }

  return arr;
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


int main()
{
  Array_2d arr1 = array_2d_create(2,10);
  array_2d_print(arr1);
  
  printf("\n");

  array_2d_assign_range(arr1);
  array_2d_print(arr1);

  printf("\n");

  float data;
  data = array_2d_get(arr1, 1,3);
  printf("data: %.2f\n", data);

  array_2d_set(arr1, 1,3, 666);

  data = array_2d_get(arr1, 1,3);
  printf("data: %.2f\n", data);
  array_2d_print(arr1);

  printf("\n");

  printf("dim1: %d\n", arr1.dim1);
  printf("dim2: %d\n", arr1.dim2);
  arr1 = array_2d_reshape(arr1, 4, 5);
  printf("dim1: %d\n", arr1.dim1);
  printf("dim2: %d\n", arr1.dim2);

  printf("\n");
  array_2d_print(arr1);

  arr1 = array_2d_reshape(arr1, 10, 2);
  printf("\n");
  array_2d_print(arr1);

  arr1 = array_2d_resize(arr1, 30);
  array_2d_print(arr1);

  printf("\n");

  arr1 = array_2d_reshape(arr1, 6, 5);
  array_2d_print(arr1);

  printf("\n");

  array_2d_assign_range(arr1);
  array_2d_print(arr1);

  array_2d_free(arr1);


  return 0;
}