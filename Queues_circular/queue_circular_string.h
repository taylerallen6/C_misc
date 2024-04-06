#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct
{
    char** data;
    int max_length;
    int current_length;
    int front;
    int back;
    int max_string_length;
} Queue_circular_string;

Queue_circular_string* queue_circular_string_create(int max_length, int max_string_length);
void queue_circular_string_free(Queue_circular_string* queue);
bool queue_circular_string_max_length_reached(Queue_circular_string* queue);
bool queue_circular_string_is_full(Queue_circular_string* queue);
bool queue_circular_string_is_empty(Queue_circular_string* queue);
bool queue_circular_string_dequeue(Queue_circular_string* queue, char* output);
bool queue_circular_string_enqueue(Queue_circular_string* queue, char* value);
void queue_circular_string_print(Queue_circular_string* queue);
void queue_circular_string_print_full_array(Queue_circular_string* queue);