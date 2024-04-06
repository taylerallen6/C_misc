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


Array_list_float* array_list_float_create(int max_length)
{
    Array_list_float* new_list = malloc(sizeof(Array_list_float));

    new_list->max_length = max_length;
    new_list->data = malloc(sizeof(float) * new_list->max_length);

    new_list->current_length = 0;
    new_list->last_item_index = 0;
    new_list->num_wasted_slots = 0;

    for (int i = 0; i < new_list->max_length; i++)
        new_list->data[i] = AVAILABLE;
    
    return new_list;
}

void array_list_float_free(Array_list_float* list)
{
    free(list->data);
    free(list);
}

void array_list_float_append(Array_list_float* list, int index, float value)
{
    if (list->num_wasted_slots == 0)
        list->last_item_index++;
    
    list->data[index] = value;
    list->current_length++;

    if (list->num_wasted_slots != 0)
        list->num_wasted_slots--;
}

void array_list_float_remove(Array_list_float* list, int index)
{
    list->data[index] = AVAILABLE;
    list->current_length--;
    list->num_wasted_slots++;
}

void array_list_float_print(Array_list_float* list)
{
    for (int i = 0; i < list->last_item_index; i++)
    {
        if (list->data[i] != AVAILABLE)
            printf("%.1f, ", list->data[i]);
    }

    printf("\n");
}

void array_list_float_print_all(Array_list_float* list)
{
    for (int i = 0; i < list->max_length; i++)
        printf("%.1f, ", list->data[i]);
    
    printf("\n");
}


// int main(void)
// {
//     Array_list_float* list1 = array_list_float_create(10);
//     Array_reverse_stack* available_slot_stack1 = array_reverse_stack_create(list1->max_length);
//     array_reverse_stack_assign_reverse_range(available_slot_stack1);

//     array_list_float_print_all(list1);
//     array_list_float_print(list1);
//     printf("stack: ");
//     array_reverse_stack_print(available_slot_stack1);
//     printf("current_length: %d\n", list1->current_length);
//     printf("last_item_index: %d\n", list1->last_item_index);
//     printf("\n");

//     int index;

//     for (float i = 0; i < 8; i++)
//     {   
//         index = array_reverse_stack_dequeue(available_slot_stack1);
//         array_list_float_append(list1, index, i);
//     }

//     array_list_float_print_all(list1);
//     array_list_float_print(list1);
//     printf("stack: ");
//     array_reverse_stack_print(available_slot_stack1);
//     printf("current_length: %d\n", list1->current_length);
//     printf("last_item_index: %d\n", list1->last_item_index);
//     printf("\n");

//     index = 2;
//     array_list_float_remove(list1, index);
//     array_reverse_stack_enqueue(available_slot_stack1, index);
//     index = 6;
//     array_list_float_remove(list1, index);
//     array_reverse_stack_enqueue(available_slot_stack1, index);
//     index = 1;
//     array_list_float_remove(list1, index);
//     array_reverse_stack_enqueue(available_slot_stack1, index);

//     array_list_float_print_all(list1);
//     array_list_float_print(list1);
//     printf("stack: ");
//     array_reverse_stack_print(available_slot_stack1);
//     printf("current_length: %d\n", list1->current_length);
//     printf("last_item_index: %d\n", list1->last_item_index);
//     printf("\n");

//     index = array_reverse_stack_dequeue(available_slot_stack1);
//     array_list_float_append(list1, index, 1001.0);
    
//     array_list_float_print_all(list1);
//     array_list_float_print(list1);
//     printf("stack: ");
//     array_reverse_stack_print(available_slot_stack1);
//     printf("current_length: %d\n", list1->current_length);
//     printf("last_item_index: %d\n", list1->last_item_index);
//     printf("\n");

//     index = array_reverse_stack_dequeue(available_slot_stack1);
//     array_list_float_append(list1, index, 1002.0);
    
//     array_list_float_print_all(list1);
//     array_list_float_print(list1);
//     printf("stack: ");
//     array_reverse_stack_print(available_slot_stack1);
//     printf("current_length: %d\n", list1->current_length);
//     printf("last_item_index: %d\n", list1->last_item_index);
//     printf("\n");

//     index = array_reverse_stack_dequeue(available_slot_stack1);
//     array_list_float_append(list1, index, 1003.0);
    
//     array_list_float_print_all(list1);
//     array_list_float_print(list1);
//     printf("stack: ");
//     array_reverse_stack_print(available_slot_stack1);
//     printf("current_length: %d\n", list1->current_length);
//     printf("last_item_index: %d\n", list1->last_item_index);
//     printf("\n");

//     index = array_reverse_stack_dequeue(available_slot_stack1);
//     array_list_float_append(list1, index, 1004.0);
    
//     array_list_float_print_all(list1);
//     array_list_float_print(list1);
//     printf("stack: ");
//     array_reverse_stack_print(available_slot_stack1);
//     printf("current_length: %d\n", list1->current_length);
//     printf("last_item_index: %d\n", list1->last_item_index);
//     printf("\n");


//     array_list_float_free(list1);
//     array_reverse_stack_free(available_slot_stack1);
    
//     return 0;
// }