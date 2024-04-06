#include <stdio.h>
#include <stdlib.h>


typedef struct
{
  int* data;
  int length; 
} Array_1d_int;


Array_1d_int* array_1d_int_create(int length)
{
  Array_1d_int* arr = malloc(sizeof(Array_1d_int));
  arr->length = length;
  arr->data = calloc(sizeof(int), arr->length);

  return arr;
}

void array_1d_int_free(Array_1d_int* arr)
{
  free(arr->data);
  free(arr);
}

void array_1d_int_assign_range(Array_1d_int* arr)
{
  for (int i = 0; i < arr->length; i++)
    arr->data[i] = i;
}

int array_1d_int_get(Array_1d_int* arr, int index)
{
  return arr->data[index];
}

void array_1d_int_set(Array_1d_int* arr, int index, int new_value)
{
  arr->data[index] = new_value;
}

void array_1d_int_resize(Array_1d_int* arr, int new_length)
{
  int* new_data;
  if (new_data = realloc(arr->data, sizeof(int) * new_length))
  {
    arr->data = new_data;
    arr->length = new_length;
  }
  else
    printf("ERROR: could now reallocate memory\n");
}

void array_1d_int_print(Array_1d_int* arr)
{
  printf("{ ");
  for (int i = 0; i < arr->length; i++)
  {
    printf("%.2f, ", arr->data[i]);
  }
  printf("}\n");
}


void array_1d_int_scalar_add(Array_1d_int* arr, int x)
{
  for (int i = 0; i < arr->length; i++)
    arr->data[i] += x;
}

void array_1d_int_scalar_subtract(Array_1d_int* arr, int x)
{
  for (int i = 0; i < arr->length; i++)
    arr->data[i] -= x;
}

void array_1d_int_scalar_multiply(Array_1d_int* arr, int x)
{
  for (int i = 0; i < arr->length; i++)
    arr->data[i] *= x;
}

void array_1d_int_scalar_divide(Array_1d_int* arr, int x)
{
  for (int i = 0; i < arr->length; i++)
    arr->data[i] /= x;
}

Array_1d_int* array_1d_int_vector_muliply(Array_1d_int* arr1, Array_1d_int* arr2)
{
  Array_1d_int* new_arr = array_1d_int_create(arr1->length);

  for (int i = 0; i < new_arr->length; i++)
    new_arr->data[i] = arr1->data[i] * arr2->data[i];

  return new_arr;
}

Array_1d_int* array_1d_int_vector_divide(Array_1d_int* arr1, Array_1d_int* arr2)
{
  Array_1d_int* new_arr = array_1d_int_create(arr1->length);

  for (int i = 0; i < new_arr->length; i++)
    new_arr->data[i] = arr1->data[i] / arr2->data[i];

  return new_arr;
}

int array_1d_int_sum(Array_1d_int* arr)
{
  int sum_value;

  for (int i = 0; i < arr->length; i++)
    sum_value += arr->data[i];

  return sum_value;
}



// int main()
// {
//   Array_1d_int* arr1 = array_1d_int_create(10);
//   array_1d_int_print(arr1);
  
//   printf("\n");

//   array_1d_int_assign_range(arr1);
//   array_1d_int_print(arr1);

//   printf("\n");

//   int data;
//   data = array_1d_int_get(arr1, 1);
//   printf("data: %.2f\n", data);

//   array_1d_int_set(arr1, 3, 666);

//   data = array_1d_int_get(arr1, 3);
//   printf("data: %.2f\n", data);
//   array_1d_int_print(arr1);

//   printf("\n");
//   array_1d_int_print(arr1);

//   array_1d_int_resize(arr1, 20);
//   array_1d_int_print(arr1);

//   printf("\n");

//   array_1d_int_assign_range(arr1);
//   array_1d_int_print(arr1);

//   array_1d_int_free(arr1);


//   return 0;
// }