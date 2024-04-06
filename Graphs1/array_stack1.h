#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct
{
    int* data;
    int length;
    int head;
} Array_stack;


Array_stack* array_stack_create(int total_length);
void array_stack_free(Array_stack* stack);
bool array_stack_is_full(Array_stack* stack);
bool array_stack_is_empty(Array_stack* stack);
bool array_stack_enqueue(Array_stack* stack, int value);
int array_stack_dequeue(Array_stack* stack);
void array_stack_assign_range(Array_stack* stack);
void array_stack_assign_reverse_range(Array_stack* stack);
void array_stack_print(Array_stack* stack);