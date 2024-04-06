#include <stdio.h>
#include <stdlib.h>


typedef struct
{
  int* data;
  int num_dimensions;
  int* dims;
  int length; 
} Array;

Array array_create(int num_dimensions, int* dims)
{
  Array arr;

  arr.length = 1;
  for (int i = 0; i < num_dimensions; i++)
  {
    arr.length *= dims[i];
  }
  // printf("%d, ", arr.length);
  arr.num_dimensions = num_dimensions;
  arr.dims = dims;
  arr.data = calloc(sizeof(int), arr.length);

  return arr;
}

void array_assign_range(Array arr)
{
  for (int i = 0; i < arr.length; i++)
    arr.data[i] = i;
}

int array_get(Array arr, int* indices)
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

void array_set(Array arr, int* indices, int new_value)
{
  // int real_index = (index1 * arr.dim2) + index2;
  // arr.data[real_index] = new_value;

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

// Array array_reshape(Array arr, int new_dim1, int new_dim2)
// {
//   if ((new_dim1 * new_dim2) == arr.length)
//   {
//     arr.dim1 = new_dim1;
//     arr.dim2 = new_dim2;
//   }
//   else
//     printf("ERROR: cannot use those dimensions for array of length %d\n", arr.length);

//   return arr;
// }

// Array array_resize(Array arr, int new_length)
// {
//   int* new_data;
//   if (new_data = realloc(arr.data, sizeof(int) * new_length))
//   {
//     arr.data = new_data;
//     arr.length = new_length;
//     arr.dim1 = 1;
//     arr.dim2 = new_length;
//   }
//   else
//   {
//     printf("ERROR: could now reallocate memory\n");
//   }

//   return arr;
// }

void array_print(Array arr)
{
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

  printf("\n");
}

void array_free(Array arr)
{
  free(arr.data);
}


int main()
{
  int dims[] = {2,2,3,5};
  Array arr1 = array_create(4, dims);
  // array_print(arr1);
  
  // printf("\n---------------------------\n\n");

  array_assign_range(arr1);
  array_print(arr1);

  printf("\n");

  // int data;
  // int indices[] = {0,2};
  // data = array_get(arr1, indices);
  // printf("data: %d\n", data);

  // int indices2[] = {1,3};
  // array_set(arr1, indices2, 666);

  // // int data;
  // int indices3[] = {1,3};
  // data = array_get(arr1, indices3);
  // printf("data: %d\n", data);

  // printf("\n");

  // array_print(arr1);

  // printf("dim1: %d\n", arr1.dim1);
  // printf("dim2: %d\n", arr1.dim2);
  // arr1 = array_reshape(arr1, 4, 5);
  // printf("dim1: %d\n", arr1.dim1);
  // printf("dim2: %d\n", arr1.dim2);

  // printf("\n");
  // array_print(arr1);

  // arr1 = array_reshape(arr1, 10, 2);
  // printf("\n");
  // array_print(arr1);

  // arr1 = array_resize(arr1, 30);
  // array_print(arr1);

  // printf("\n");

  // arr1 = array_reshape(arr1, 6, 5);
  // array_print(arr1);

  // printf("\n");

  // array_assign_range(arr1);
  // array_print(arr1);

  array_free(arr1);


  return 0;
}