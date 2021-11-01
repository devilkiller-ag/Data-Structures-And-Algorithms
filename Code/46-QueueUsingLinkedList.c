/*
Author: Ashmit JaiSarita Gupta
Topic: Queue Implementation Using Linked List
Date Created: 30-10-2021
*/
/*
Notes / Theory: 

*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int *FrontPtr, *RearPtr;
    int data;
    struct Node *next;
};

int isEmpty(struct Node *n)
{
    if (n->FrontPtr == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        // printf("Queue Overflow! The Heap Memory is Full :(\n");
        return 1;
    }
    return 0;
}

void enqueue(struct Node *head, int element)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue Overflow! The Heap Memory is Full :(\n");
    }
    else
    {
        n->data = element;
        n->next = null;
        head = n;
    }
}

int main()
{
    struct Node *frontNode = (struct Node *)malloc(sizeof(struct Node));
    frontNode->FrontPtr = frontNode->RearPtr = NULL;
    return 0;
}