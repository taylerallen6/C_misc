#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct
{
    int* data;
    int max_length;
    int current_length;
    int front;
    int back;
} Queue_circular;

Queue_circular* queue_circular_create(int max_length);
void queue_circular_free(Queue_circular* queue);
bool queue_circular_max_length_reached(Queue_circular* queue);
bool queue_circular_is_full(Queue_circular* queue);
bool queue_circular_is_empty(Queue_circular* queue);
bool queue_circular_dequeue(Queue_circular* queue, int* output);
bool queue_circular_enqueue(Queue_circular* queue, int value);
void queue_circular_print(Queue_circular* queue);
void queue_circular_print_full_array(Queue_circular* queue);