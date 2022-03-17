#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/* List node */
typedef struct ListNode
{
    void *data;
    struct ListNode *next;

} ListNode;

/* head node */
typedef struct
{
    ListNode *head;

} LinkedList;

/* insert the data through this */
typedef void (*funcPtr)(void *data);

/*LinkedList *createLinkedList();*/
LinkedList *createLinkedList();
void insertFirst(LinkedList *list, void *data);
void *removeFirst(LinkedList *list);
void freeData(void *data);
void freeLinkedList(LinkedList *list, void (*fp)(void *));

#endif