/*
Author: Ashmit JaiSarita Gupta
Topic: Queue Implementation Using Array
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
};

int isEmpty(struct Queue *q)
{
    if (q->frontIndex == q->rearIndex)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Queue *q)
{
    if (q->rearIndex == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty!\n");
        return;
    }
    int i = 0;
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
        printf("Enqueue failed! Queue is Full!\n");
        return;
    }
    q->arr[++q->rearIndex] = element;
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Deque Failed! Queue is Empty!\n");
        return -1;
    }
    int deq = q->arr[q->frontIndex++ + 1];
    return deq;
}

int main()
{

    // ------------------> Method 1 -------------------->

    struct Queue *que = (struct Queue *)malloc(sizeof(struct Queue));
    que->size = 10;
    que->frontIndex = -1;
    que->rearIndex = -1;
    que->arr = (int *)malloc(que->size * sizeof(int));

    display(que);
    enqueue(que, 34);
    display(que);
    enqueue(que, 54);
    display(que);
    enqueue(que, 74);
    display(que);

    int deq1 = dequeue(que);
    printf("Dequeued %d.\n", deq1);
    display(que);
    int deq2 = dequeue(que);
    printf("Dequeued %d.\n", deq2);
    display(que);
    int deq3 = dequeue(que);
    printf("Dequeued %d.\n", deq3);
    display(que);

    // // ------------------> Method 2 -------------------->

    // struct Queue que2;
    // que2.size = 20;
    // que2.frontIndex = -1;
    // que2.rearIndex = -1;
    // que2.arr = (int *)malloc(que2.size * sizeof(int));

    // display(&que2);
    // enqueue(&que2, 3434);
    // display(&que2);
    // enqueue(&que2, 3454);
    // display(&que2);
    // enqueue(&que2, 3474);
    // display(&que2);

    // int deq21 = dequeue(&que2);
    // printf("Dequeued %d.\n", deq21);
    // display(&que2);
    // int deq22 = dequeue(&que2);
    // printf("Dequeued %d.\n", deq22);
    // display(&que2);
    // int deq23 = dequeue(&que2);
    // printf("Dequeued %d.\n", deq23);
    // display(&que2);

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