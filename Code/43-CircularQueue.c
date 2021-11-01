/*
Author: Ashmit JaiSarita Gupta
Topic: Circular Queue Implementation Using Array
Date Created: 29-10-2021
*/
/*
Notes / Theory: 

*/
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int frontIndex;
    int rearIndex;
    int *arr;
    //frontIndex is always empty in circular queue and both frontIndex and Rear Index are initally at index 0. Since we can't store any element at the frontIndex & it is assigned to 0 initially (and not -1) so we can only store size - 1 elements in queue.
};

int isEmpty(struct Queue *q)
{
    if (q->rearIndex == q->frontIndex)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Queue *q)
{
    if ((q->rearIndex + 1) % q->size == q->frontIndex)
    {
        return 1;
    }
    return 0;
}

void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("The Circular Queue is Empty!\n");
        return;
    }
    int i;
    printf("Displaying Circular Queue...\n");
    for (i = q->frontIndex + 1; i <= q->rearIndex; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void enqueue(struct Queue *q, int element)
{
    if (isFull(q))
    {
        printf("Enqueue Failed! Circular Queue is Full.\n");
        return;
    }
    q->rearIndex = (q->rearIndex + 1) % q->size; // Circular Incrementation
    q->arr[q->rearIndex] = element;
    printf("Enqued Element: %d\n", element);
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Dequeue Failed! Circular Queue is Empty.\n");
        return -1;
    }
    q->frontIndex = (q->frontIndex + 1) % q->size;
    int deq = q->arr[q->frontIndex];
    return deq;
}

int main()
{

    struct Queue *que = (struct Queue *)malloc(sizeof(struct Queue));
    que->size = 3;
    que->frontIndex = 0; //<---------------- Note The Change-----------------
    // frontIndex and rearIndex are set 0 to make circular increamentation possible.
    que->rearIndex = 0; //<---------------- Note The Change-----------------
    que->arr = (int *)malloc(que->size * sizeof(int));

    enqueue(que, 12);
    display(que);
    enqueue(que, 15);
    display(que);
    enqueue(que, 2);
    display(que);

    printf("Dequeuing element: %d\n", dequeue(que));
    display(que);
    printf("Dequeuing element: %d\n", dequeue(que));
    display(que);
    printf("Dequeuing element: %d\n", dequeue(que));
    display(que);

    enqueue(que, 87);
    enqueue(que, 93);
    enqueue(que, 22);
    display(que);

    if (isEmpty(que))
    {
        printf("Queue is Empty.\n");
    }
    if (isFull(que))
    {
        printf("Queue is Full.\n");
    }

    return 0;
}