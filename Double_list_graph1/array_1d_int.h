
typedef struct
{
  int* data;
  int length; 
} Array_1d_int;



Array_1d_int* array_1d_int_create(int length);
void array_1d_int_free(Array_1d_int* arr);
void array_1d_int_assign_range(Array_1d_int* arr);
void array_1d_int_assign_random(Array_1d_int* arr);
int array_1d_int_get(Array_1d_int* arr, int index);
void array_1d_int_set(Array_1d_int* arr, int index, int new_value);
void array_1d_int_resize(Array_1d_int* arr, int new_length);
void array_1d_int_print(Array_1d_int* arr);

void array_1d_int_scalar_add(Array_1d_int* arr, int x);
void array_1d_int_scalar_subtract(Array_1d_int* arr, int x);
void array_1d_int_scalar_multiply(Array_1d_int* arr, int x);
void array_1d_int_scalar_divide(Array_1d_int* arr, int x);
Array_1d_int* array_1d_int_vector_muliply(Array_1d_int* arr1, Array_1d_int* arr2);
Array_1d_int* array_1d_int_vector_divide(Array_1d_int* arr1, Array_1d_int* arr2);
int array_1d_int_sum(Array_1d_int* arr);