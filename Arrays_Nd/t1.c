#include <stdio.h>
#include <stdlib.h>


// 
// may have memory leak with dims array.
// actually i think i fixed it..
// 


typedef struct
{
  int* data;
  int num_dimensions;
  int* dims;
  int length; 
} Array_nd;

Array_nd array_nd_create(int num_dimensions, int* dims)
{
  Array_nd arr;

  arr.num_dimensions = num_dimensions;
  arr.dims = malloc(sizeof(int) * num_dimensions);

  arr.length = 1;
  for (int i = 0; i < num_dimensions; i++)
  {
    arr.length *= dims[i];
    arr.dims[i] = dims[i];
  }
  
  arr.data = calloc(sizeof(int), arr.length);

  return arr;
}

void array_nd_assign_range(Array_nd arr)
{
  for (int i = 0; i < arr.length; i++)
    arr.data[i] = i;
}

int array_nd_get(Array_nd arr, int* indices)
{
  // int real_index = (index1 * dim2) + index2;
  // int real_index = (index1 * dim2 * dim3) + (index2 * dim3) + i3;
  // int real_index = (index1 * dim2 * dim3 * dim4) + (index2 * dim3 * dim4) + (index3 * dim4) + index4;

  int real_index = 0;
  int dims_multiple = 1;

  for (int i = arr.num_dimensions-1; i >= 0; i--)
  { 
    int index = indices[i];
    real_index += index * dims_multiple;

    if (i != 0)
    {
      int dim_value = arr.dims[i];
      dims_multiple *= dim_value;
    }
  }
  
  return arr.data[real_index];
}

void array_nd_set(Array_nd arr, int* indices, int new_value)
{
  int real_index = 0;
  int dims_multiple = 1;

  for (int i = arr.num_dimensions-1; i >= 0; i--)
  { 
    int index = indices[i];
    real_index += index * dims_multiple;

    if (i != 0)
    {
      int dim_value = arr.dims[i];
      dims_multiple *= dim_value;
    }
  }
  
  arr.data[real_index] = new_value;
}

Array_nd array_nd_reshape(Array_nd arr, int num_dimensions, int* dims)
{
  int temp_length = 1;
  for (int i = 0; i < num_dimensions; i++)
  {
    temp_length *= dims[i];
  }

  if (temp_length == arr.length)
  {
    int* new_dims;
    if (new_dims = realloc(arr.dims, sizeof(int) * num_dimensions))
    {
      arr.num_dimensions = num_dimensions;
      arr.dims = new_dims;

      for (int i = 0; i < num_dimensions; i++)
        arr.dims[i] = dims[i];
    }
    else
      printf("ERROR: could not reallocate memory\n");
  }
  else
    printf("ERROR: dimensions must match length %d\n", arr.length);

  return arr;
}

Array_nd array_nd_resize(Array_nd arr, int new_length)
{
  int* new_data;
  int* new_dims;
  if ((new_data = realloc(arr.data, sizeof(int) * new_length)) && (new_dims = realloc(arr.dims, sizeof(int))))
  {
    arr.data = new_data;
    arr.length = new_length;

    arr.num_dimensions = 1;
    arr.dims = new_dims;
    arr.dims[0] = new_length;
  }
  else
    printf("ERROR: could not reallocate memory\n");

  return arr;
}

void array_nd_print(Array_nd arr)
{
  printf("{\n");
  int count = 0;
  while (count < arr.length)
  {
    int dims_multiple = 1;
    for (int dim = 0; dim < arr.num_dimensions; dim++)
    { 
      int new_dim = arr.num_dimensions - dim - 1;
      dims_multiple *= arr.dims[new_dim];

      if (count != 0)
      {
        int modulo;
        modulo = count % dims_multiple;
        if (modulo == 0)
        {
          printf("\n");
        }
      }
    }

    printf("%d, ", arr.data[count]);

    count++;
  }

  printf("\n}");
  printf("\n");
}

void array_nd_free(Array_nd arr)
{
  free(arr.data);
  free(arr.dims);
}


int main()
{
  int dims[] = {4,10};
  Array_nd arr1 = array_nd_create(2, dims);
  // array_nd_print(arr1);
  
  // printf("\n---------------------------\n\n");

  array_nd_assign_range(arr1);
  array_nd_print(arr1);

  printf("\n");

  int dims2[] = {2,4,5};
  arr1 = array_nd_reshape(arr1, 3, dims2);
  array_nd_print(arr1);

  printf("\n");

  arr1 = array_nd_resize(arr1, 60);
  array_nd_assign_range(arr1);
  array_nd_print(arr1);

  printf("\n");

  int dims3[] = {2,3,10};
  arr1 = array_nd_reshape(arr1, 3, dims3);
  array_nd_print(arr1);

  // int data;
  // int indices[] = {0,2};
  // data = array_nd_get(arr1, indices);
  // printf("data: %d\n", data);

  // int indices2[] = {1,3};
  // array_nd_set(arr1, indices2, 666);

  // // int data;
  // int indices3[] = {1,3};
  // data = array_nd_get(arr1, indices3);
  // printf("data: %d\n", data);

  // printf("\n");

  // array_nd_print(arr1);

  // printf("dim1: %d\n", arr1.dim1);
  // printf("dim2: %d\n", arr1.dim2);
  // arr1 = array_nd_reshape(arr1, 4, 5);
  // printf("dim1: %d\n", arr1.dim1);
  // printf("dim2: %d\n", arr1.dim2);

  // printf("\n");
  // array_nd_print(arr1);

  // arr1 = array_nd_reshape(arr1, 10, 2);
  // printf("\n");
  // array_nd_print(arr1);

  // arr1 = array_nd_resize(arr1, 30);
  // array_nd_print(arr1);

  // printf("\n");

  // arr1 = array_nd_reshape(arr1, 6, 5);
  // array_nd_print(arr1);

  // printf("\n");

  // array_nd_assign_range(arr1);
  // array_nd_print(arr1);

  array_nd_free(arr1);


  return 0;
}