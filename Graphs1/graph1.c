#include <stdio.h>
#include <stdlib.h>
#include "array_stack1.h"
#include "array_list1.h"
#include "../Arrays1/array_2d.h"


typedef struct
{
    int num_node_slots;
    int num_nodes;

    Array_list* node_list;
    Array_stack* available_slot_stack;
    Array_2d* arr;
} Graph;


Graph* graph_create(int num_node_slots)
{
    Graph* graph = malloc(sizeof(Graph));

    graph->num_node_slots = num_node_slots;
    graph->num_nodes = 0;

    graph->node_list = array_list_create(num_node_slots);
    graph->available_slot_stack = array_stack_create(graph->node_list->max_length);
    array_stack_assign_reverse_range(graph->available_slot_stack);

    graph->arr = array_2d_create(num_node_slots, num_node_slots);

    return graph;
}

void graph_free(Graph* graph)
{
    array_list_free(graph->node_list);
    array_stack_free(graph->available_slot_stack);
    array_2d_free(graph->arr);
    free(graph);
}

void graph_node_add(Graph* graph, int memory_id)
{
    array_list_append(graph->node_list, graph->available_slot_stack, memory_id);

    graph->num_nodes++;
}

void graph_node_remove(Graph* graph, int memory_id)
{
    array_list_remove(graph->node_list, graph->available_slot_stack, memory_id);

    graph->num_nodes++;
}

float graph_row_sum(Graph* graph, int row)
{
    float sum_value = 0;

    int row_multiplier = graph->arr->dim2 * row;

    for (int i = 0; i < graph->node_list->last_item_index; i++)
    {
        if (graph->node_list->data[i] == -1)
            continue;
        
        int graph_index = row_multiplier + i;
        sum_value += graph->arr->data[graph_index];
    }
    
    return sum_value;
}


int main()
{
    Graph* graph1 = graph_create(10);
    array_2d_assign_range(graph1->arr);
    array_2d_print(graph1->arr);
    printf("\n");

    array_list_print_all(graph1->node_list);
    array_list_print(graph1->node_list);
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        graph_node_add(graph1, 1);
    }

    graph_node_remove(graph1, 2);
    graph_node_remove(graph1, 3);
    
    graph_node_add(graph1, 1);
    // graph_node_add(graph1, 1);
    // graph_node_add(graph1, 1);

    array_list_print_all(graph1->node_list);
    array_list_print(graph1->node_list);
    printf("\n");

    array_2d_set(graph1->arr, 2, 3, 666);
    array_2d_print(graph1->arr);
    printf("\n");

    float sum = graph_row_sum(graph1, 1);
    printf("%.2f", sum);

    //   Array_1d arr_1d_1 = graph_row_get(graph1, 2);
    //   Array_1d arr_1d_2 = graph_column_get(graph1, 4);

    //   array_1d_print(arr_1d_1);
    //   array_1d_print(arr_1d_2);
    //   printf("\n");

    //   array_1d_free(arr_1d_1);
    //   array_1d_free(arr_1d_2);

    //   Array_1d arr_1d = array_1d_create(5);
    //   array_1d_assign_random(arr_1d);
    //   array_1d_print(arr_1d);


    graph_free(graph1);


    return 0;
}