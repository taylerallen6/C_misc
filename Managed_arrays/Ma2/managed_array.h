#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* array_reverse_stack */
typedef struct
{
    int* data;
    int total_length;
    int current_length;
    int head;
} Array_reverse_stack;

Array_reverse_stack* array_reverse_stack_create(int total_length);
void array_reverse_stack_free(Array_reverse_stack* stack);
bool array_reverse_stack_is_full(Array_reverse_stack* stack);
bool array_reverse_stack_is_empty(Array_reverse_stack* stack);
bool array_reverse_stack_enqueue(Array_reverse_stack* stack, int value);
bool array_reverse_stack_dequeue(Array_reverse_stack* stack, int* output);
void array_reverse_stack_assign_range(Array_reverse_stack* stack);
void array_reverse_stack_assign_reverse_range(Array_reverse_stack* stack);
void array_reverse_stack_print(Array_reverse_stack* stack);
void array_reverse_stack_increase_total_length(Array_reverse_stack* stack, int increase_amount);
void array_reverse_stack_increase_total_length_refill_reverse_range(Array_reverse_stack* stack, int increase_amount);


/* managed_array */
typedef struct
{
    int* data;
    Array_reverse_stack* empty_slots;
    int total_length;
    int current_length;
    int num_used_slots;
} Managed_array;

Managed_array* managed_array_create(int total_length);
void managed_array_free(Managed_array* managed_array);
void managed_array_resize(Managed_array* managed_array, int new_total_length);
void managed_array_increase_size(Managed_array* managed_array, int increase_amount);
bool managed_array_is_full(Managed_array* managed_array);
bool managed_array_slot_is_available(Managed_array* managed_array, int index);
bool managed_array_insert(Managed_array* managed_array, int value);
bool managed_array_insert_index(Managed_array* managed_array);
bool managed_array_remove(Managed_array* managed_array, int* output, int index);
bool managed_array_remove_index(Managed_array* managed_array, int index);
void managed_array_print(Managed_array* managed_array);
void managed_array_print_all(Managed_array* managed_array);