#include <stdbool.h>
#include <limits.h>
#include "managed_array.h"


#define AVAILABLE (-1)
// #define AVAILABLE UINT_MAX

Managed_array* managed_array_create(int total_length)
{   
    Managed_array* managed_array = malloc(sizeof(Managed_array));

    managed_array->total_length = total_length;
    managed_array->current_length = 0;
    managed_array->num_used_slots = 0;

    managed_array->data = malloc(sizeof(int) * managed_array->total_length);
    for (int i = 0; i < managed_array->total_length; i++)
        managed_array->data[i] = AVAILABLE;

    managed_array->empty_slots = array_reverse_stack_create(managed_array->total_length);
    array_reverse_stack_assign_reverse_range(managed_array->empty_slots);

    return managed_array;
}

void managed_array_free(Managed_array* managed_array)
{
    array_reverse_stack_free(managed_array->empty_slots);
    free(managed_array->data);
    free(managed_array);
}

void managed_array_resize(Managed_array* managed_array, int new_total_length)
{
    managed_array->data = realloc(managed_array->data, sizeof(int) * new_total_length);
    for (int i = managed_array->total_length; i < new_total_length; i++)
        managed_array->data[i] = AVAILABLE;

    int increase_amount = new_total_length - managed_array->total_length;
    array_reverse_stack_increase_total_length_refill_reverse_range(managed_array->empty_slots, increase_amount);

    managed_array->total_length = new_total_length;
}

void managed_array_increase_size(Managed_array* managed_array, int increase_amount)
{   
    int new_total_length = managed_array->total_length + increase_amount;
    managed_array->data = realloc(managed_array->data, sizeof(int) * new_total_length);
    for (int i = managed_array->total_length; i < new_total_length; i++)
        managed_array->data[i] = AVAILABLE;

    array_reverse_stack_increase_total_length_refill_reverse_range(managed_array->empty_slots, increase_amount);

    managed_array->total_length = new_total_length;
}

bool managed_array_is_full(Managed_array* managed_array)
{
    bool is_full = false;
    
    if (managed_array->current_length == managed_array->total_length)
        is_full = true;
    
    return is_full;
}

bool managed_array_slot_is_available(Managed_array* managed_array, int index)
{
    return (managed_array->data[index] == AVAILABLE);
}

bool managed_array_insert(Managed_array* managed_array, int value)
{
    if (managed_array_is_full(managed_array))
    {
        printf("ERROR: array is full.\n");
        return false;
    }

    int index;
    if (array_reverse_stack_dequeue(managed_array->empty_slots, &index) == false)
    {
        printf("ERROR: empty_slots stack is empty.\n");
        return false;
    }

    if (index >= managed_array->num_used_slots)
        managed_array->num_used_slots = index+1;

    managed_array->data[index] = value;
    managed_array->current_length++;

    return true;
}

bool managed_array_insert_index(Managed_array* managed_array)
{
    if (managed_array_is_full(managed_array))
    {
        printf("ERROR: array is full.\n");
        return false;
    }

    int index;
    if (array_reverse_stack_dequeue(managed_array->empty_slots, &index) == false)
    {
        printf("ERROR: empty_slots stack is empty.\n");
        return false;
    }

    if (index >= managed_array->num_used_slots)
        managed_array->num_used_slots = index+1;

    managed_array->data[index] = index;
    managed_array->current_length++;

    return true;
}

bool managed_array_remove(Managed_array* managed_array, int* output, int index)
{
    if (index >= managed_array->total_length)
    {
        printf("ERROR: index larger than array size.\n");
        return false;
    }

    int value = managed_array->data[index];

    if (value == AVAILABLE)
    {
        printf("ERROR: slot already empty.\n");
        return false;
    }

    *output = value;
    managed_array->data[index] = AVAILABLE;
    if (array_reverse_stack_enqueue(managed_array->empty_slots, index) == false)
        return false;

    managed_array->current_length--;

    return true;
}

bool managed_array_remove_index(Managed_array* managed_array, int index)
{
    if (index >= managed_array->total_length)
    {
        printf("ERROR: index larger than array size.\n");
        return false;
    }

    int value = managed_array->data[index];

    if (value == AVAILABLE)
    {
        printf("ERROR: slot already empty.\n");
        return false;
    }

    managed_array->data[index] = AVAILABLE;
    if (array_reverse_stack_enqueue(managed_array->empty_slots, index) == false)
        return false;

    managed_array->current_length--;

    return true;
}

void managed_array_print(Managed_array* managed_array)
{
    for (int i = 0; i < managed_array->num_used_slots; i++)
    {
        if (managed_array->data[i] != AVAILABLE)
            printf("%d, ", managed_array->data[i]);
    }

    printf("\n");
}

void managed_array_print_all(Managed_array* managed_array)
{
    for (int i = 0; i < managed_array->total_length; i++)
        printf("%d, ", managed_array->data[i]);

    printf("\n");
}


int main()
{
    int num_slots = 10;

    Managed_array* marr = managed_array_create(num_slots);
    printf("stack: ");
    array_reverse_stack_print(marr->empty_slots);
    printf("marr: ");
    managed_array_print(marr);

    for (int i = 0; i < 8; i++)
    {
        printf("%d\n", i);
        managed_array_insert(marr, 666);

        printf("stack: ");
        array_reverse_stack_print(marr->empty_slots);
        printf("marr: ");
        managed_array_print(marr);
        managed_array_print_all(marr);
        printf("marr length: %d\n", marr->current_length);
        printf("marr num_used_slots: %d\n", marr->num_used_slots);
    }

    printf("\n");

    int index;
    int output;

    index = 9;
    managed_array_remove(marr, &output, index);
    printf("stack: ");
    array_reverse_stack_print(marr->empty_slots);
    printf("marr: ");
    managed_array_print(marr);
    managed_array_print_all(marr);
    printf("marr length: %d\n", marr->current_length);
    printf("marr num_used_slots: %d\n", marr->num_used_slots);

    index = 4;
    managed_array_remove(marr, &output, index);
    printf("stack: ");
    array_reverse_stack_print(marr->empty_slots);
    printf("marr: ");
    managed_array_print(marr);
    managed_array_print_all(marr);
    printf("marr length: %d\n", marr->current_length);
    printf("marr num_used_slots: %d\n", marr->num_used_slots);

    index = 2;
    managed_array_remove(marr, &output, index);
    printf("stack: ");
    array_reverse_stack_print(marr->empty_slots);
    printf("marr: ");
    managed_array_print(marr);
    managed_array_print_all(marr);
    printf("marr length: %d\n", marr->current_length);
    printf("marr num_used_slots: %d\n", marr->num_used_slots);

    index = 7;
    managed_array_remove(marr, &output, index);
    printf("stack: ");
    array_reverse_stack_print(marr->empty_slots);
    printf("marr: ");
    managed_array_print(marr);
    managed_array_print_all(marr);
    printf("marr length: %d\n", marr->current_length);
    printf("marr num_used_slots: %d\n", marr->num_used_slots);

    index = 8;
    managed_array_remove(marr, &output, index);
    printf("stack: ");
    array_reverse_stack_print(marr->empty_slots);
    printf("marr: ");
    managed_array_print(marr);
    managed_array_print_all(marr);
    printf("marr length: %d\n", marr->current_length);
    printf("marr num_used_slots: %d\n", marr->num_used_slots);

    printf("\n");
    

    managed_array_insert(marr, 44);
    printf("stack: ");
    array_reverse_stack_print(marr->empty_slots);
    printf("marr: ");
    managed_array_print(marr);
    managed_array_print_all(marr);
    printf("marr length: %d\n", marr->current_length);
    printf("marr num_used_slots: %d\n", marr->num_used_slots);

    managed_array_insert(marr, 44);
    printf("stack: ");
    array_reverse_stack_print(marr->empty_slots);
    printf("marr: ");
    managed_array_print(marr);
    managed_array_print_all(marr);
    printf("marr length: %d\n", marr->current_length);
    printf("marr num_used_slots: %d\n", marr->num_used_slots);

    printf("\n");

    
    managed_array_remove(marr, &output, 4);
    printf("stack: ");
    array_reverse_stack_print(marr->empty_slots);
    printf("marr: ");
    managed_array_print(marr);
    managed_array_print_all(marr);
    printf("marr length: %d\n", marr->current_length);
    printf("marr num_used_slots: %d\n", marr->num_used_slots);

    printf("\n");


    managed_array_increase_size(marr, 5);
    printf("stack: ");
    array_reverse_stack_print(marr->empty_slots);
    printf("marr: ");
    managed_array_print(marr);
    managed_array_print_all(marr);
    printf("marr length: %d\n", marr->current_length);
    printf("marr num_used_slots: %d\n", marr->num_used_slots);

    printf("\n");

    for (int i = 0; i < 9; i++)
    {
        managed_array_insert(marr, 333);
        printf("stack: ");
        array_reverse_stack_print(marr->empty_slots);
        printf("marr: ");
        managed_array_print(marr);
        managed_array_print_all(marr);
        printf("marr length: %d\n", marr->current_length);
        printf("marr num_used_slots: %d\n", marr->num_used_slots);
    }


    managed_array_free(marr);

    return 0;
}