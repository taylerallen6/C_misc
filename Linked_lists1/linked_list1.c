#include <stdio.h>
#include <stdlib.h>


struct node
{
    float value;
    struct node* next_node;
};
typedef struct node Node;

typedef struct
{
    int length;
    Node* head;
    Node* tail;
} Linked_list;


Node* node_create(float value)
{
    Node* new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next_node = NULL;

    return new_node;
}

Linked_list* linked_list_create()
{
    Linked_list* new_list = malloc(sizeof(Linked_list));
    new_list->length = 1;
    Node* new_node = node_create(666);
    new_list->head = new_node;
    new_list->tail = new_node;

    return new_list;
}

void linked_list_insert_head(Linked_list* list, float value)
{
    Node* node1 = node_create(value);
    node1->next_node = list->head;
    list->head = node1;
    list->length++;
}

void linked_list_insert_tail(Linked_list* list, float value)
{
    Node* node1 = node_create(value);
    list->tail->next_node = node1;
    list->tail = node1;
    list->length++;
}

void linked_list_print(Linked_list* list)
{
    Node* temp_node = list->head;
    for (int i = 0; i < list->length; i++)
    {
        printf("%.2f, ", temp_node->value);
        temp_node = temp_node->next_node;
    }
    printf("\n");
}

void linked_list_free(Linked_list* list)
{
    Node* temp_node = list->head;
    for (int i = 0; i < list->length; i++)
    {
        Node* node_for_deletion = temp_node;
        temp_node = temp_node->next_node;

        free(node_for_deletion);
    }
    
    free(list);
}


int main()
{
    Linked_list* list1 = linked_list_create();

    // Node* node1 = node_create(1);
    // node1->next_node = list1->head;
    // list1->head = node1;

    // Node* node2 = node_create(2);
    // node2->next_node = node1;
    // list1->head = node2;

    // Node* node3 = node_create(3);
    // node3->next_node = node2;
    // list1->head = node3;

    // linked_list_print(list1->head);

    // for (int i = 0; i < 10; i++)
    // {
    //     linked_list_insert_head(list1, (float)i);
    // }
    
    // linked_list_print(list1);

    for (int i = 0; i < 10; i++)
    {
        linked_list_insert_tail(list1, (float)i);
    }
    
    linked_list_print(list1);

    linked_list_free(list1);


    return 0;
}