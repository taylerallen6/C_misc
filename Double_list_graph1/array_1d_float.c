#include <stdio.h>
#include <stdlib.h>


typedef struct
{
  float* data;
  int length; 
} Array_1d_float;


Array_1d_float* array_1d_float_create(int length)
{
  Array_1d_float* arr = malloc(sizeof(Array_1d_float));
  arr->length = length;
  arr->data = calloc(sizeof(float), arr->length);

  return arr;
}

void array_1d_float_free(Array_1d_float* arr)
{
  free(arr->data);
  free(arr);
}

void array_1d_float_assign_range(Array_1d_float* arr)
{
  for (int i = 0; i < arr->length; i++)
    arr->data[i] = (float)i;
}

void array_1d_float_assign_random(Array_1d_float* arr)
{
  float rand_value;

  for (int i = 0; i < arr->length; i++)
  {
    rand_value = (float)rand() / (float)RAND_MAX;
    arr->data[i] = rand_value;
  }
}

float array_1d_float_get(Array_1d_float* arr, int index)
{
  return arr->data[index];
}

void array_1d_float_set(Array_1d_float* arr, int index, float new_value)
{
  arr->data[index] = new_value;
}

void array_1d_float_resize(Array_1d_float* arr, int new_length)
{
  float* new_data;
  if (new_data = realloc(arr->data, sizeof(float) * new_length))
  {
    arr->data = new_data;
    arr->length = new_length;
  }
  else
    printf("ERROR: could now reallocate memory\n");
}

void array_1d_float_print(Array_1d_float* arr)
{
  printf("{ ");
  for (int i = 0; i < arr->length; i++)
  {
    printf("%.2f, ", arr->data[i]);
  }
  printf("}\n");
}


void array_1d_float_scalar_add(Array_1d_float* arr, float x)
{
  for (int i = 0; i < arr->length; i++)
    arr->data[i] += x;
}

void array_1d_float_scalar_subtract(Array_1d_float* arr, float x)
{
  for (int i = 0; i < arr->length; i++)
    arr->data[i] -= x;
}

void array_1d_float_scalar_multiply(Array_1d_float* arr, float x)
{
  for (int i = 0; i < arr->length; i++)
    arr->data[i] *= x;
}

void array_1d_float_scalar_divide(Array_1d_float* arr, float x)
{
  for (int i = 0; i < arr->length; i++)
    arr->data[i] /= x;
}

Array_1d_float* array_1d_float_vector_muliply(Array_1d_float* arr1, Array_1d_float* arr2)
{
  Array_1d_float* new_arr = array_1d_float_create(arr1->length);

  for (int i = 0; i < new_arr->length; i++)
    new_arr->data[i] = arr1->data[i] * arr2->data[i];

  return new_arr;
}

Array_1d_float* array_1d_float_vector_divide(Array_1d_float* arr1, Array_1d_float* arr2)
{
  Array_1d_float* new_arr = array_1d_float_create(arr1->length);

  for (int i = 0; i < new_arr->length; i++)
    new_arr->data[i] = arr1->data[i] / arr2->data[i];

  return new_arr;
}

float array_1d_float_sum(Array_1d_float* arr)
{
  float sum_value;

  for (int i = 0; i < arr->length; i++)
    sum_value += arr->data[i];

  return sum_value;
}



// int main()
// {
//   Array_1d_float* arr1 = array_1d_float_create(10);
//   array_1d_float_print(arr1);
  
//   printf("\n");

//   array_1d_float_assign_range(arr1);
//   array_1d_float_print(arr1);

//   printf("\n");

//   float data;
//   data = array_1d_float_get(arr1, 1);
//   printf("data: %.2f\n", data);

//   array_1d_float_set(arr1, 3, 666);

//   data = array_1d_float_get(arr1, 3);
//   printf("data: %.2f\n", data);
//   array_1d_float_print(arr1);

//   printf("\n");
//   array_1d_float_print(arr1);

//   array_1d_float_resize(arr1, 20);
//   array_1d_float_print(arr1);

//   printf("\n");

//   array_1d_float_assign_range(arr1);
//   array_1d_float_print(arr1);

//   array_1d_float_free(arr1);


//   return 0;
// }