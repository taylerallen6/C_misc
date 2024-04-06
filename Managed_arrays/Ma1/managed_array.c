#include "managed_array.h"


#define AVAILABLE (-1)

void array_print(int* arr, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d, ", arr[i]);
    
    printf("\n");
}

int main()
{
    int num_slots = 10;

    int arr[num_slots];

    for (int i = 0; i < num_slots; i++)
        arr[i] = AVAILABLE;

    array_print(arr, num_slots);

    Array_reverse_stack* stack1 = array_reverse_stack_create(num_slots);
    array_reverse_stack_assign_reverse_range(stack1);
    array_reverse_stack_print(stack1);
    printf("\n");

    int index;
    for (int i = 0; i < num_slots; i++)
    {
        array_reverse_stack_dequeue(stack1, &index);
        printf("index: %d\n", index);

        printf("stack: ");
        array_reverse_stack_print(stack1);

        arr[index] = 666;
        printf("arr: ");
        array_print(arr, num_slots);
        
        // printf("\n");
    }

    printf("\n");

    index = 4;
    arr[index] = AVAILABLE;
    array_reverse_stack_enqueue(stack1, index);
    printf("stack: ");
    array_reverse_stack_print(stack1);
    printf("arr: ");
    array_print(arr, num_slots);

    index = 2;
    arr[index] = AVAILABLE;
    array_reverse_stack_enqueue(stack1, index);
    printf("stack: ");
    array_reverse_stack_print(stack1);
    printf("arr: ");
    array_print(arr, num_slots);

    index = 7;
    arr[index] = AVAILABLE;
    array_reverse_stack_enqueue(stack1, index);
    printf("stack: ");
    array_reverse_stack_print(stack1);
    printf("arr: ");
    array_print(arr, num_slots);

    printf("\n");

    array_reverse_stack_dequeue(stack1, &index);
    printf("index: %d\n", index);
    printf("stack: ");
    array_reverse_stack_print(stack1);
    arr[index] = 44;
    printf("arr: ");
    array_print(arr, num_slots);

    array_reverse_stack_dequeue(stack1, &index);
    printf("index: %d\n", index);
    printf("stack: ");
    array_reverse_stack_print(stack1);
    arr[index] = 44;
    printf("arr: ");
    array_print(arr, num_slots);

    
    // array_reverse_stack_print(stack1);
    // printf("\n");

    array_reverse_stack_free(stack1);


    return 0;
}