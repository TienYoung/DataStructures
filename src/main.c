#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    void* data;
    struct LinkedList* next;
} LinkedList;

LinkedList* InsertLinkedList(LinkedList* head, void* data);
void PrintLinkedList(LinkedList* head);
void ClearLinkedList(LinkedList* head);

int main(int argc, char** argv) {
    int numArray[] = {1, 3 ,4 ,5 ,6, 7};
    LinkedList* list = NULL;
    list =  InsertLinkedList(list, &numArray[0]);
    // list =  InsertLinkedList(list, &numArray[1]);
    // list =  InsertLinkedList(list, &numArray[2]);
    // list =  InsertLinkedList(list, &numArray[3]);
    // list =  InsertLinkedList(list, &numArray[4]);
    PrintLinkedList(list);
    ClearLinkedList(list);
    return 0;
}

LinkedList* InsertLinkedList(LinkedList* head, void* data)
{
    if (head)
    {
        return InsertLinkedList(head->next, data);
    }
    else
    {
        head = malloc(sizeof(LinkedList));
        head->data = data;
        return head;
    }
}

void PrintLinkedList(LinkedList* head)
{
    if (head == NULL) return;

    printf("Data: %d\n", *(int*)head->data);
    PrintLinkedList(head->next);
}

void ClearLinkedList(LinkedList* head)
{
    if(head == NULL) return;

    LinkedList* next = head->next;
    free(head);
    ClearLinkedList(next);
}