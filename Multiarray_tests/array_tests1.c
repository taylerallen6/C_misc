#include <stdio.h>
#include <stdlib.h>

void array_print(int* array, int array_length)
{
  for (int i=0; i<array_length; i++)
  {
    printf("%d, ", array[i]);
  }
  printf("\n");

  return;
}

void array_create(int* array, int array_length)
{
  for (int i=0; i<array_length; i++)
  {
    array[i] = i+1;
  }

  return;
}

int* array_create2(int array_length)
{
  int* array;

  for (int i=0; i<array_length; i++)
  {
    array[i] = i+1;
  }

  return array;
}

int* array_allocate(int array_length)
{
  // printf("%d", sizeof(int));
  int* array = malloc(sizeof(int) * array_length);

  for (int i=0; i<array_length; i++)
  {
    array[i] = i*2;
  }

  return array;
}

int* array_update(int* array, int array_length)
{
  for (int i=0; i<array_length; i++)
  {
    array[i] = array[i] * 2;
  }

  return array;
}

int main()
{
  printf("howdy\n");

  int array[] = {1, 2, 3, 4, 5};
  printf("array: ");
  array_print(array, 5);

  int array1_length = 5;
  int array1[array1_length];
  array_create(array1, array1_length);
  printf("array1: ");
  array_print(array1, array1_length);

  int array2_length = 5;
  int* array2 = array_create2(array2_length);
  printf("array2: ");
  array_print(array2, array2_length);

  int array3_length = 5;
  int* array3 = array_allocate(array3_length);
  printf("array3: ");
  array_print(array3, array3_length);

  array3 = array_update(array3, array3_length);
  printf("array3 updated: ");
  array_print(array3, array3_length);

  // unallocated array call, nothing at memory address
  free(array3);
  printf("array3 unallocated: ");
  array_print(array3, array3_length);

  free(array2);
  printf("array2 unallocated: ");
  array_print(array2, array2_length);

  return 0;
}

