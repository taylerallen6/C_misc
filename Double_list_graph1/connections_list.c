#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_list1.h"
#include "array_1d_float.h"
#include "array_reverse_stack1.h"


typedef struct
{
    Array_list* memory_ids;
    Array_1d_float* memory_weights;
} Connections_list;


Connections_list* connections_list_create(int max_length)
{
    Connections_list* new_list = malloc(sizeof(Connections_list));

    new_list->memory_ids = array_list_create(max_length);
    new_list->memory_weights = array_1d_float_create(max_length);
    
    return new_list;
}

void connections_list_free(Connections_list* list)
{
    array_list_free(list->memory_ids);
    array_1d_float_free(list->memory_weights);
    free(list);
}

void connections_list_append(Connections_list* list, int memory_id, float memory_weight)
{
    for (int i = 0; i < list->memory_ids->max_length; i++)
    {
        if (list->memory_ids[i] == -1)
        {
            array_list_append(list->memory_ids, i, memory_id);
            list->memory_weights[i] = memory_weight;
            break;
        }
    }
    
}

void connections_list_remove(Array_list* list, int index)
{
    list->data[index] = AVAILABLE;
    list->current_length--;
    list->num_wasted_slots++;
}

void array_list_print(Array_list* list)
{
    for (int i = 0; i < list->last_item_index; i++)
    {
        if (list->data[i] != AVAILABLE)
            printf("%d, ", list->data[i]);
    }

    printf("\n");
}

void array_list_print_all(Array_list* list)
{
    for (int i = 0; i < list->max_length; i++)
        printf("%d, ", list->data[i]);
    
    printf("\n");
}


int main(void)
{
    Array_list* list1 = array_list_create(10);
    Array_reverse_stack* available_slot_stack1 = array_reverse_stack_create(list1->max_length);
    array_reverse_stack_assign_reverse_range(available_slot_stack1);

    array_list_print_all(list1);
    array_list_print(list1);
    printf("stack: ");
    array_reverse_stack_print(available_slot_stack1);
    printf("current_length: %d\n", list1->current_length);
    printf("last_item_index: %d\n", list1->last_item_index);
    printf("\n");

    int index;

    for (int i = 0; i < 8; i++)
    {   
        index = array_reverse_stack_dequeue(available_slot_stack1);
        array_list_append(list1, index, i);
    }

    array_list_print_all(list1);
    array_list_print(list1);
    printf("stack: ");
    array_reverse_stack_print(available_slot_stack1);
    printf("current_length: %d\n", list1->current_length);
    printf("last_item_index: %d\n", list1->last_item_index);
    printf("\n");

    index = 2;
    array_list_remove(list1, index);
    array_reverse_stack_enqueue(available_slot_stack1, index);
    index = 6;
    array_list_remove(list1, index);
    array_reverse_stack_enqueue(available_slot_stack1, index);
    index = 1;
    array_list_remove(list1, index);
    array_reverse_stack_enqueue(available_slot_stack1, index);

    array_list_print_all(list1);
    array_list_print(list1);
    printf("stack: ");
    array_reverse_stack_print(available_slot_stack1);
    printf("current_length: %d\n", list1->current_length);
    printf("last_item_index: %d\n", list1->last_item_index);
    printf("\n");

    index = array_reverse_stack_dequeue(available_slot_stack1);
    array_list_append(list1, index, 1001);
    
    array_list_print_all(list1);
    array_list_print(list1);
    printf("stack: ");
    array_reverse_stack_print(available_slot_stack1);
    printf("current_length: %d\n", list1->current_length);
    printf("last_item_index: %d\n", list1->last_item_index);
    printf("\n");

    index = array_reverse_stack_dequeue(available_slot_stack1);
    array_list_append(list1, index, 1002);
    
    array_list_print_all(list1);
    array_list_print(list1);
    printf("stack: ");
    array_reverse_stack_print(available_slot_stack1);
    printf("current_length: %d\n", list1->current_length);
    printf("last_item_index: %d\n", list1->last_item_index);
    printf("\n");

    index = array_reverse_stack_dequeue(available_slot_stack1);
    array_list_append(list1, index, 1003);
    
    array_list_print_all(list1);
    array_list_print(list1);
    printf("stack: ");
    array_reverse_stack_print(available_slot_stack1);
    printf("current_length: %d\n", list1->current_length);
    printf("last_item_index: %d\n", list1->last_item_index);
    printf("\n");

    index = array_reverse_stack_dequeue(available_slot_stack1);
    array_list_append(list1, index, 1004);
    
    array_list_print_all(list1);
    array_list_print(list1);
    printf("stack: ");
    array_reverse_stack_print(available_slot_stack1);
    printf("current_length: %d\n", list1->current_length);
    printf("last_item_index: %d\n", list1->last_item_index);
    printf("\n");


    array_list_free(list1);
    array_reverse_stack_free(available_slot_stack1);
    
    return 0;
}