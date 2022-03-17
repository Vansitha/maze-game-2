#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "undo.h"

LinkedList *createLinkedList()
{
    /* NAME: createLinkedList
       PURPOSE: Creates an empty linkedlist pointing to the head node
       IMPORTS: none
       EXPORTS: linkedlist (ll)
       ASSERTIONS:
           PRE: None
          POST: Creates empty linked list
    */
    LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList));
    ll->head = NULL;

    return ll;
}

void insertFirst(LinkedList *list, void *data)
{
    /* NAME: insertFirst
       PURPOSE: Inserts node at the head node of the linked list
       IMPORTS: linkedlist, data
       EXPORTS: None
       ASSERTIONS:
           PRE: Initialize empty linked list
           POST: Head points to new data entry
    */
    ListNode *newNode;
    newNode = (ListNode *)malloc(sizeof(ListNode));

    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void *removeFirst(LinkedList *list)
{
    /* NAME: removeFirst
       PURPOSE: Remove node from the head of the linked list
       IMPORTS: linkedlist
       EXPORTS: removed node (temp)
       ASSERTIONS:
           PRE: At least one node with data in the linked list
           POST: Points head to the next node down the list
    */
    void *temp = NULL;
    ListNode *node;

    node = list->head;
    temp = node->data;
    list->head = list->head->next;

    free(node);

    return temp;
}

void freeLinkedList(LinkedList *list, void (*fp)(void *))
{
    /* NAME: freeLinkedList
       PURPOSE: Free allocated memory for the linked list in heap memory
       IMPORTS: linkedlist, function pointer
       EXPORTS: None
       ASSERTIONS:
           PRE: Any operations with the linked list my be dealt with before function is called
           POST: Linked list does not exist in memory
    */
    ListNode *currNode;
    ListNode *nextNode;

    currNode = list->head;

    while (currNode != NULL)
    {
        nextNode = currNode->next;
        (*fp)(currNode->data);
        free(currNode);
        currNode = nextNode;
    }
}

void freeData(void *data)
{
    /* NAME: freeData
       PURPOSE: Special function to free the coordinate data stores in the linked list
                required for the undo feature
       IMPORTS: data
       EXPORTS: None
       ASSERTIONS:
           PRE: At least one node should contain coordinate data in linked list
           POST: Coordinate data cannot be used for futher operations
    */
    Coordinates *values;

    values = (Coordinates *)(data);
    free(values);
}