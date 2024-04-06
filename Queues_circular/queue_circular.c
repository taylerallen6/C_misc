#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue_circular.h"


Queue_circular* queue_circular_create(int max_length)
{
    Queue_circular* new_queue = malloc(sizeof(Queue_circular));
    new_queue->max_length = max_length;
    new_queue->data = calloc(sizeof(int), new_queue->max_length);

    new_queue->current_length = 0;
    new_queue->front = 0;
    new_queue->back = 0;

    return new_queue;
}

void queue_circular_free(Queue_circular* queue)
{
    free(queue->data);
    free(queue);
}

bool queue_circular_max_length_reached(Queue_circular* queue)
{
    bool is_queue_full = false;
    
    if (queue->front + queue->current_length == queue->max_length)
        is_queue_full = true;
    
    return (is_queue_full);
}

bool queue_circular_is_full(Queue_circular* queue)
{
    bool is_queue_full = false;
    
    if (queue->current_length == queue->max_length)
        is_queue_full = true;
    
    return (is_queue_full);
}

bool queue_circular_is_empty(Queue_circular* queue)
{
    bool is_queue_empty = false;
    
    if (queue->current_length == 0)
        is_queue_empty = true;
    
    return (is_queue_empty);
}

bool queue_circular_dequeue(Queue_circular* queue, int* output)
{
    if (queue_circular_is_empty(queue))
    {
        printf("Queue empty \n");
        return false;
    }

    (*output) = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->max_length;
    queue->current_length--;

    return true;
}

bool queue_circular_enqueue(Queue_circular* queue, int value)
{
    if (queue_circular_is_full(queue))
    {
        int dequeued_value;
        queue_circular_dequeue(queue, &dequeued_value);
        // printf("dequeued_value: %d\n", dequeued_value);
    }

    queue->data[queue->back] = value;
    queue->current_length++;
    queue->back = (queue->back + 1) % queue->max_length;

    return true;
}

void queue_circular_print(Queue_circular* queue)
{
    for (int i = queue->front; i < queue->front + queue->current_length; i++)
    {
        int queue_i = i % queue->max_length;
        // if (queue_i >= queue->max_length)
        //     queue_i -= queue->max_length;

        printf("%d, ", queue->data[queue_i]);
    }
    printf("\n");
}

void queue_circular_print_full_array(Queue_circular* queue)
{
    for (int i = 0; i < queue->max_length; i++)
    {
        printf("%d, ", queue->data[i]);
    }
    printf("\n");
}


int main(void)
{
    Queue_circular* queue1 = queue_circular_create(5);

    for (int i = 0; i < 20; i++)
    {
        queue_circular_enqueue(queue1, i);
        printf("queue: ");
        queue_circular_print(queue1);

        printf("queue all: ");
        queue_circular_print_full_array(queue1);
    }

    printf("\n");
    printf("\n");

    printf("queue: ");
    queue_circular_print(queue1);
    printf("\n");

    int result;
    int current_length = queue1->current_length;
    for (int i = 0; i < current_length; i++)
    {
        queue_circular_dequeue(queue1, &result);
        printf("dequed_value: %d\n", result);

        printf("queue: ");
        queue_circular_print(queue1);
        printf("\n");
    }
    
    queue_circular_print(queue1);


    queue_circular_free(queue1);

    return 0;
}