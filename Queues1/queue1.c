#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node
{
    float value;
    struct Node* next_node;
} Node;

typedef struct
{
    int length;
    Node* head;
    Node* tail;
} Queue;


Queue* queue_create()
{
    Queue* new_queue = malloc(sizeof(Queue));
    new_queue->length = 0;
    new_queue->head = NULL;
    new_queue->tail = NULL;

    return new_queue;
}

void queue_free(Queue* queue)
{
    Node* temp_node = queue->head;
    for (int i = 0; i < queue->length; i++)
    {
        Node* node_for_deletion = temp_node;
        temp_node = temp_node->next_node;

        free(node_for_deletion);
    }
    
    free(queue);
}

bool enqueue(Queue* queue, float value)
{
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) return false;

    new_node->value = value;
    new_node->next_node = NULL;

    if (queue->length == 0)
        queue->head = new_node;
    else
        queue->tail->next_node = new_node;
    
    queue->tail = new_node;

    queue->length++;
    
    return true;
}

int dequeue(Queue* queue)
{
    if (queue->head == NULL) return 0;
    
    Node* temp = queue->head;

    int result = temp->value;
    queue->head = queue->head->next_node;
    if (queue->head == NULL)
        queue->tail = NULL;
    
    free(temp);

    queue->length--;
    
    return result;
}

void queue_print(Queue* queue)
{
    Node* temp_node = queue->head;
    for (int i = 0; i < queue->length; i++)
    {
        printf("%.2f, ", temp_node->value);
        temp_node = temp_node->next_node;
    }
    printf("\n");
}


int main()
{
    Queue* queue1 = queue_create();

    for (int i = 0; i < 10; i++)
    {
        enqueue(queue1, (float)i);
    }

    queue_print(queue1);
    printf("\n");

    int result;
    for (int i = 0; i < 6; i++)
    {
        result = dequeue(queue1);
        printf("%d\n", result);

        queue_print(queue1);
        printf("\n");
    }
    
    queue_print(queue1);

    queue_free(queue1);


    return 0;
}