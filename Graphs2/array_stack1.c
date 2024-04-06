#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct
{
    int* data;
    int length;
    int head;
} Array_stack;


Array_stack* array_stack_create(int total_length)
{
    Array_stack* new_stack = malloc(sizeof(Array_stack));
    new_stack->length = total_length;
    new_stack->data = calloc(sizeof(float), new_stack->length);

    new_stack->head = 0;

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
    
    if (stack->head == stack->length)
        is_stack_full = true;
    
    return (is_stack_full);
}

bool array_stack_is_empty(Array_stack* stack)
{
    bool is_stack_empty = false;
    
    if (stack->head == 0)
        is_stack_empty = true;
    
    return (is_stack_empty);
}

bool array_stack_enqueue(Array_stack* stack, int value)
{
    stack->data[stack->head] = value;
    stack->head++;
    
    return true;
}

int array_stack_dequeue(Array_stack* stack)
{
    if (stack->head == 0)
        return 0;

    stack->head--;
    int result = stack->data[stack->head];

    return result;
}

void array_stack_assign_range(Array_stack* stack)
{
    for (int i = 0; i < stack->length; i++)
        array_stack_enqueue(stack, i);
}

void array_stack_assign_reverse_range(Array_stack* stack)
{
    for (int i = stack->length-1; i >= 0; i--)
        array_stack_enqueue(stack, i);
}

void array_stack_print(Array_stack* stack)
{
    for (int i = 0; i < stack->head; i++)
    {
        printf("%d, ", stack->data[i]);
    }
    printf("\n");
}



// int main()
// {
//     Array_stack* stack1 = array_stack_create(10);

//     // for (int i = 0; i < 10; i++)
//     // {
//     //     array_stack_enqueue(stack1, i);
//     // }

//     // array_stack_assign_range(stack1);
//     array_stack_assign_reverse_range(stack1);

//     array_stack_print(stack1);
//     printf("\n");

//     int result;
//     int current_length = stack1->head;
//     for (int i = 0; i < current_length; i++)
//     {
//         result = array_stack_dequeue(stack1);
//         printf("%d\n", result);

//         array_stack_print(stack1);
//         printf("\n");
//     }
    
//     array_stack_print(stack1);

//     array_stack_free(stack1);


//     return 0;
// }