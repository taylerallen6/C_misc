#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_reverse_stack1.h"


#define AVAILABLE (float)(-1)


typedef struct
{
    float* data;
    int max_length;
    int current_length;
    int last_item_index;
    int num_wasted_slots;
} Array_list_float;


Array_list_float* array_list_float_create(int max_length);
void array_list_float_free(Array_list_float* list);
void array_list_float_append(Array_list_float* list, int index, float value);
void array_list_float_remove(Array_list_float* list, int index);
void array_list_float_print(Array_list_float* list);
void array_list_float_print_all(Array_list_float* list);