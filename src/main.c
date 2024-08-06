#include <stdio.h>

#include "linked_list.h"

void print_data(void* data) {
    printf("Data: %d\n", *(int*)data);
}

void destroy_data(void* data) {
    printf("Destroy: %d\n", *(int*)data);
}

int main(int argc, char** argv) {
    int numArray[] = {1, 3 ,4 ,5 ,6, 7};
    LinkedList* head = linked_list_create(&numArray[0]);
    LinkedList* tail = head;
    assert(*(int*)tail->data == numArray[0]);

    tail = linked_list_append(head, linked_list_create(&numArray[1]));
    assert(*(int*)tail->data == numArray[1]);
    tail = linked_list_append(head, linked_list_create(&numArray[2]));
    assert(*(int*)tail->data == numArray[2]);
    tail = linked_list_append(head, linked_list_create(&numArray[3]));
    assert(*(int*)tail->data == numArray[3]);
    tail = linked_list_append(head, linked_list_create(&numArray[4]));
    assert(*(int*)tail->data == numArray[4]);
    tail = linked_list_append(head, linked_list_create(&numArray[5]));
    assert(*(int*)tail->data == numArray[5]);

    linked_list_traverse_forward(head, print_data);
    linked_list_traverse_backward(head, destroy_data);

    linked_list_destroy(head);
    
    return 0;
}