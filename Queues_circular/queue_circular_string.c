#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "queue_circular_string.h"


Queue_circular_string* queue_circular_string_create(int max_length, int max_string_length)
{
    Queue_circular_string* new_queue = malloc(sizeof(Queue_circular_string));
    new_queue->max_length = max_length;
    new_queue->data = calloc(sizeof(char*), new_queue->max_length);

    new_queue->max_string_length = max_string_length;

    for (int i = 0; i < new_queue->max_length; i++)
    {
        new_queue->data[i] = malloc(sizeof(char) * new_queue->max_string_length);
        // *(new_queue->data[i]) = '\0';
        strcpy(new_queue->data[i], "-1");
    }

    new_queue->current_length = 0;
    new_queue->front = 0;
    new_queue->back = 0;

    return new_queue;
}

void queue_circular_string_free(Queue_circular_string* queue)
{
    for (int i = 0; i < queue->max_length; i++)
        free(queue->data[i]);

    free(queue->data);
    free(queue);
}

bool queue_circular_string_max_length_reached(Queue_circular_string* queue)
{
    bool is_queue_full = false;
    
    if (queue->front + queue->current_length == queue->max_length)
        is_queue_full = true;
    
    return (is_queue_full);
}

bool queue_circular_string_is_full(Queue_circular_string* queue)
{
    bool is_queue_full = false;
    
    if (queue->current_length == queue->max_length)
        is_queue_full = true;
    
    return (is_queue_full);
}

bool queue_circular_string_is_empty(Queue_circular_string* queue)
{
    bool is_queue_empty = false;
    
    if (queue->current_length == 0)
        is_queue_empty = true;
    
    return (is_queue_empty);
}

bool queue_circular_string_dequeue(Queue_circular_string* queue, char* output)
{
    if (queue_circular_string_is_empty(queue))
    {
        printf("Queue empty \n");
        return false;
    }

    strcpy(output, queue->data[queue->front]);
    strcpy(queue->data[queue->front], "-1");

    queue->front = (queue->front + 1) % queue->max_length;
    queue->current_length--;

    return true;
}

bool queue_circular_string_enqueue(Queue_circular_string* queue, char* value)
{
    if (queue_circular_string_is_full(queue))
    {
        char dequeued_value[queue->max_string_length];
        queue_circular_string_dequeue(queue, dequeued_value);
        printf("dequeued_value: %s\n", dequeued_value);
        // free(dequeued_value);
    }

    strcpy(queue->data[queue->back], value);
    queue->current_length++;
    queue->back = (queue->back + 1) % queue->max_length;

    return true;
}

void queue_circular_string_print(Queue_circular_string* queue)
{
    for (int i = queue->front; i < queue->front + queue->current_length; i++)
    {
        int queue_i = i % queue->max_length;
        printf("%s, ", queue->data[queue_i]);
    }
    printf("\n");
}

void queue_circular_string_print_full_array(Queue_circular_string* queue)
{
    for (int i = 0; i < queue->max_length; i++)
    {
        printf("%s, ", queue->data[i]);
    }
    printf("\n");
}


int main(void)
{
    Queue_circular_string* queue1 = queue_circular_string_create(5, 10);

    for (int i = 0; i < 18; i++)
    {
        /* generate random string */
        // srand(time(NULL)); // define a seed for the random number generator
        int num_random_chars = 5;
        char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEHGHIJKLMNOPQRSTUVWXYZ1234567890";
        char random_string[num_random_chars+1];

        int i2 = 0;
        int num_allowed_chars = sizeof(allowed_chars) - 1;
        for (int j = 0; j < num_random_chars; j++) {
            i2 = rand() % num_allowed_chars;
            random_string[j] = allowed_chars[i2];
        }
        random_string[num_random_chars] = '\0';
        printf("random_string: %s\n", random_string);


        queue_circular_string_enqueue(queue1, random_string);
        printf("queue: ");
        queue_circular_string_print(queue1);

        printf("queue all: ");
        queue_circular_string_print_full_array(queue1);
    }

    printf("\n");
    printf("\n");

    printf("queue: ");
    queue_circular_string_print(queue1);
    printf("queue all: ");
    queue_circular_string_print_full_array(queue1);
    printf("\n");

    char result[10];
    int current_length = queue1->current_length;
    for (int i = 0; i < current_length; i++)
    {
        queue_circular_string_dequeue(queue1, result);
        printf("dequed_value: %s\n", result);

        printf("queue: ");
        queue_circular_string_print(queue1);
        printf("queue all: ");
        queue_circular_string_print_full_array(queue1);
        printf("\n");
    }
    
    queue_circular_string_print(queue1);


    queue_circular_string_free(queue1);

    return 0;
}