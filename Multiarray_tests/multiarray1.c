#include <stdio.h>
#include <stdlib.h>


void array_2d(int dim1, int dim2)
{
  int array_length = dim1 * dim2;

  int* array = malloc(sizeof(int) * array_length);
  for (int i=0; i< array_length; i++)
    array[i] = i;

  for (int i=0; i< array_length; i++)
    printf("%d, ", array[i]);
  
  printf("\n\n");

  for (int i1 = 0; i1 < dim1; i1++)
  {
    printf("{ ");
    for (int i2 = 0; i2 < dim2; i2++)
    {
      int index = (i1 * dim2) + i2;
      printf("%d, ", array[index]);
    }
    printf("}\n");
  }

  free(array);
}

void array_3d(int dim1, int dim2, int dim3)
{
  int array_length = dim1 * dim2 * dim3;

  int* array = malloc(sizeof(int) * array_length);
  for (int i=0; i< array_length; i++)
    array[i] = i;

  for (int i=0; i< array_length; i++)
    printf("%d, ", array[i]);
  
  printf("\n\n");

  for (int i1 = 0; i1 < dim1; i1++)
  {
    printf("{\n");
    for (int i2 = 0; i2 < dim2; i2++)
    {
      printf("{ ");
      for (int i3 = 0; i3 < dim3; i3++)
      {
        int index = (i1 * dim2 * dim3) + (i2 * dim3) + i3;
        printf("%d, ", array[index]);
      }
      printf("}\n");
    }
    printf("}\n");
  }

  free(array);
}


int main()
{
  printf("This is a string\n");
  int arr1_dim1 = 3;

  int arr1[arr1_dim1];
  // arr1 = {1,2,3};
  for (int i=0; i< 3; i++)
    printf("%d, ", arr1[i]);

  printf("\n\n");

  array_2d(3, 5);

  printf("\n\n");

  array_3d(2, 3, 5);

  printf("\n\n");

  int arr[3][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}};

  for (int i1=0; i1<3; i1++)
  {
    printf("{ ");
    for (int i2=0; i2<5; i2++)
    {
      printf("%d ", arr[i1][i2]);
    }
    printf("}\n");
  }

  return 0;
}