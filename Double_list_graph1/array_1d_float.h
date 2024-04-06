
typedef struct
{
  float* data;
  int length; 
} Array_1d_float;



Array_1d_float* array_1d_float_create(int length);
void array_1d_float_free(Array_1d_float* arr);
void array_1d_float_assign_range(Array_1d_float* arr);
void array_1d_float_assign_random(Array_1d_float* arr);
float array_1d_float_get(Array_1d_float* arr, int index);
void array_1d_float_set(Array_1d_float* arr, int index, float new_value);
void array_1d_float_resize(Array_1d_float* arr, int new_length);
void array_1d_float_print(Array_1d_float* arr);

void array_1d_float_scalar_add(Array_1d_float* arr, float x);
void array_1d_float_scalar_subtract(Array_1d_float* arr, float x);
void array_1d_float_scalar_multiply(Array_1d_float* arr, float x);
void array_1d_float_scalar_divide(Array_1d_float* arr, float x);
Array_1d_float* array_1d_float_vector_muliply(Array_1d_float* arr1, Array_1d_float* arr2);
Array_1d_float* array_1d_float_vector_divide(Array_1d_float* arr1, Array_1d_float* arr2);
float array_1d_float_sum(Array_1d_float* arr);