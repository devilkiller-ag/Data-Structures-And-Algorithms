/*
Author: Ashmit JaiSarita Gupta
Topic: Doubly Linked List
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
    struct Node *previous;
    struct Node *next;
};

void displayFromForward(struct Node *start)
{
    struct Node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void displayFromBackward(struct Node *end)
{
   struct Node *ptr = end;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->previous;
    }
    printf("\n");
}

int main()
{
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node4 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node5 = (struct Node *)malloc(sizeof(struct Node));

    node1->data = 1;
    node1->previous = NULL;
    node1->next = node2;

    node2->data = 2;
    node2->previous = node1;
    node2->next = node3;

    node3->data = 3;
    node3->previous = node2;
    node3->next = node4;

    node4->data = 4;
    node4->previous = node3;
    node4->next = node5;

    node5->data = 5;
    node5->previous = node4;
    node5->next = NULL;

    printf("Original Doubly linked list printed in forward direction...\n");
    displayFromForward(node1);

    printf("Original Doubly linked list printed in backward direction...\n");
    displayFromBackward(node5);

    return 0;
}