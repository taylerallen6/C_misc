#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct
{
    int* data;
    int total_length;
    int current_length;
} Array_stack;


Array_stack* array_stack_create(int total_length)
{
    Array_stack* new_stack = malloc(sizeof(Array_stack));
    new_stack->total_length = total_length;
    new_stack->data = calloc(sizeof(float), new_stack->total_length);

    new_stack->current_length = 0;

    return new_stack;
}

void array_stack_free(Array_stack* stack)
{
    free(stack->data);
    free(stack);
}

bool array_stack_is_full(Array_stack* stack)
{
    bool is_stack_full = false;
    
    if (stack->current_length == stack->total_length)
        is_stack_full = true;
    
    return (is_stack_full);
}

bool array_stack_is_empty(Array_stack* stack)
{
    bool is_stack_empty = false;
    
    if (stack->current_length == 0)
        is_stack_empty = true;
    
    return (is_stack_empty);
}

bool array_stack_enqueue(Array_stack* stack, int value)
{
    stack->data[stack->current_length] = value;
    stack->current_length++;
    
    return true;
}

int array_stack_dequeue(Array_stack* stack)
{
    if (stack->current_length == 0)
        return 0;

    stack->current_length--;
    int result = stack->data[stack->current_length];

    return result;
}

void array_stack_assign_range(Array_stack* stack)
{
    for (int i = 0; i < stack->total_length; i++)
        array_stack_enqueue(stack, i);
}

void array_stack_assign_reverse_range(Array_stack* stack)
{
    for (int i = stack->total_length-1; i >= 0; i--)
        array_stack_enqueue(stack, i);
}

void array_stack_print(Array_stack* stack)
{
    for (int i = 0; i < stack->current_length; i++)
    {
        printf("%d, ", stack->data[i]);
    }
    printf("\n");
}

void array_stack_increase_total_length(Array_stack* stack, int increase_amount)
{
    stack->total_length += increase_amount;
    stack->data = realloc(stack->data, sizeof(float) * stack->total_length);
}


// int main()
// {
//     Array_stack* stack1 = array_stack_create(10);

//     // for (int i = 0; i < 10; i++)
//     // {
//     //     array_stack_enqueue(stack1, i);
//     //     array_stack_print(stack1);
//     //     printf("is_full: %d\n", array_stack_is_full(stack1));
//     // }
//     // printf("\n");

//     // array_stack_assign_range(stack1);
//     array_stack_assign_reverse_range(stack1);

//     array_stack_print(stack1);
//     printf("\n");

//     // int result;
//     // int current_length = stack1->current_length;
//     // for (int i = 0; i < current_length; i++)
//     // {
//     //     result = array_stack_dequeue(stack1);
//     //     printf("%d\n", result);

//     //     array_stack_print(stack1);
//     //     printf("\n");
//     // }
    
//     // array_stack_print(stack1);
//     // printf("\n");

//     printf("total_length: %d\n", stack1->total_length);

//     array_stack_increase_total_length(stack1, 5);
//     // array_stack_print(stack1);

//     printf("total_length: %d\n", stack1->total_length);

//     array_stack_free(stack1);


//     return 0;
// }