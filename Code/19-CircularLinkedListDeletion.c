/*
Author: Ashmit JaiSarita Gupta
Topic: Deletion In Circular Linked List
Date Created: 27-10-2021
*/
/*
Notes / Theory: 

*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; //Self Referencing Structure
};

void displayFrom(struct Node *start) // O(n)
{
    struct Node *ptr = start;
    do // Initially both the pointers start and next points to same node initially. To ignore this case we use do-while loop.
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    printf("\n");
}

struct Node *deletefromBegining(struct Node *start) // O(n)
{
    struct Node *p = start;
    struct Node *q = start->next;
    while (q->next != start)
    {
        q = q->next;
    }
    // At this instance, q points to last element
    start = start->next;
    q->next = start;
    free(p);
    return start;
}

struct Node *deleteFromEnd(struct Node *start) // O(n)
{
    struct Node *p = start;
    struct Node *q = start->next;
    while (q->next != start)
    {
        p = p->next;
        q = q->next;
    }
    // At this instance, q points to last element and p points to second last element of CLL
    p->next = start;
    free(q);
    return start;
}

struct Node *deleteElementOccuringFirst(struct Node *start, int element) //O(n)
{
    struct Node *p = start;
    struct Node *q = start->next;
    while (q->data != element)
    {
        p = p->next;
        q = q->next;
    }
    // At this instance, q points to the element node to be deleted and p points to node before element node to be deleted of CLL
    p->next = q->next;
    free(q);
    return start;
}

struct Node *deleteAtIndex(struct Node *start, int index) //O(n)
{
    struct Node *p = start;
    struct Node *q = start->next;
    int counter = 1;
    while (counter != index)
    {
        p = p->next;
        q = q->next;
        counter++;
    }
    p->next = q->next;
    free(q);
    return start;
}

int main()
{
    // Allocate memory for nodes in the circular linked list in Heap
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node4 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node5 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node6 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node7 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node8 = (struct Node *)malloc(sizeof(struct Node));

    node1->data = 1;
    // Link node1 and node2
    node1->next = node2;

    node2->data = 2;
    // Link node2 and node3
    node2->next = node3;

    node3->data = 3;
    // Link node3 and node4
    node3->next = node4;

    node4->data = 4;
    // Link node4 and node5
    node4->next = node5;

    node5->data = 5;
    // Link node5 and node6
    node5->next = node6;

    node6->data = 6;
    // Link node6 and node7
    node6->next = node7;

    node7->data = 7;
    // link node7 and node8
    node7->next = node8;

    node8->data = 8;
    // Link node8 and node1 to make linked list circular.
    node8->next = node1;

    printf("Original Circular Linked List...\n");
    displayFrom(node1);

    node1 = deletefromBegining(node1);
    printf("Linked List after deletion from the begining...\n");
    displayFrom(node1);

    node1 = deleteFromEnd(node1);
    printf("Linked List after deletion from the end...\n");
    displayFrom(node1);

    node1 = deleteElementOccuringFirst(node1, 5);
    printf("Linked List after deletion of element...\n");
    displayFrom(node1);

    node1 = deleteAtIndex(node1, 3);
    printf("Linked List after deletion of element at index...\n");
    displayFrom(node1);

    return 0;
}