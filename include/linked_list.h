#include <stdlib.h>
#include <assert.h>

typedef struct LinkedList {
    void* data;
    struct LinkedList* next;
} LinkedList;

typedef void (*void_function_data)(void*);

LinkedList* linked_list_create(void* data){
    LinkedList* list = malloc(sizeof(LinkedList));
    list->data = data;
    list->next = NULL;
    return list;
}

LinkedList* linked_list_append(LinkedList* list, LinkedList* tail) {
    if (list==NULL) return tail;
    if (list->next == NULL) {
        list->next = tail;
        return tail;
    }
    return linked_list_append(list->next, tail);
}

void linked_list_traverse_forward(LinkedList* list, void_function_data function) {
    if(list == NULL) return;
    if (function) function(list->data);
    linked_list_traverse_forward(list->next, function);
}

void linked_list_traverse_backward(LinkedList* list, void_function_data function) {
    if(list == NULL) return;
    linked_list_traverse_backward(list->next, function);
    if (function) function(list->data);
}

void linked_list_destroy(LinkedList* list)
{
    if(list == NULL) return;
    LinkedList* next = list->next;
    free(list);
    linked_list_destroy(next);
}

typedef struct DoubleLinkedList {
    void* data;
    struct DoubleLinkedList* prev;
    struct DoubleLinkedList* next;
} DoubleLinkedList;

DoubleLinkedList* double_linked_list_create(void* data){
    DoubleLinkedList* list = malloc(sizeof(DoubleLinkedList));
    list->data = data;
    list->next = NULL;
    list->prev = NULL;
    return list;
}

DoubleLinkedList* double_linked_list_append(DoubleLinkedList* list, DoubleLinkedList* tail) {
    if (list==NULL) return tail;
    if (list->next == NULL) {
        list->next = tail;
        tail->prev = list;
        return tail;
    }
    return double_linked_list_append(list->next, tail);
}

void double_linked_list_traverse_forward(DoubleLinkedList* list, void_function_data function) {
    if(list == NULL) return;
    if (function) function(list->data);
    double_linked_list_traverse_forward(list->next, function);
}

void double_linked_list_traverse_backward(DoubleLinkedList* list, void_function_data function) {
    if(list == NULL) return;
    if (function) function(list->data);
    double_linked_list_traverse_backward(list->prev, function);
}

void double_linked_list_destroy(LinkedList* list)
{
    if(list == NULL) return;
    LinkedList* next = list->next;
    free(list);
    double_linked_list_destroy(next);
}