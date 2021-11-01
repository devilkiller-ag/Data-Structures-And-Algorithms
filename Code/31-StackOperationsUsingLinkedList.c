/*
Author: Ashmit JaiSarita Gupta
Topic: Stack Operations Implementation Using Linked List
Date Created: 28-10-2021
*/
/*
Notes / Theory: 

*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int isEmpty() // O(1)
{
    if (top == NULL)
    {
        // printf("Stack is Empty.\n");
        return 1;
    }
    return 0;
}

int isFull() // O(1)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        // printf("Stack Overflow! Heap Memmory is Full.\n");
        return 1;
    }
    return 0;
}

void display() // O(n)
{
    printf("Displaying Stack...\n");
    struct Node *n = top;
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

void push(int element) // O(1)
{
    struct Node *pushed = (struct Node *)malloc(sizeof(struct Node));
    pushed->data = element;
    pushed->next = top;
    top = pushed;
}

void pop() // O(1)
{
    struct Node *n = top;
    top = top->next;
    printf("Popped: %d\n", n->data);
    free(n);
}

void stackTop() // O(1)
{
    int topMostElement = top->data;
    printf("The top most element is: %d\n", topMostElement);
}

void stackBottom() // O(n)
{
    int bottomMostElement;
    struct Node *n = top;
    while (n->next != NULL)
    {
        n = n->next;
    }
    bottomMostElement = n->data;
    printf("The bottom most element is: %d\n", bottomMostElement);
}

void peek(int position) // O(n)
{
    struct Node *n = top;
    int counter = 1, peekedElement;
    while (counter != position && n != NULL)
    {
        n = n->next;
        counter++;
    }
    // if (counter == position)
    if (n != NULL)
    {
        peekedElement = n->data;
        printf("The peeked element is: %d\n", peekedElement);
    }
    else
    {
        printf("Invalid Input Postion!\n");
    }
}

int main()
{
    printf("isEmpty(): %d\n", isEmpty());
    printf("isFull(): %d\n", isFull());

    push(45);
    display();
    push(55);
    display();
    push(65);
    display();
    push(75);
    display();
    push(85);
    display();

    pop();
    display();
    pop();
    display();

    stackTop();
    stackBottom();

    peek(1);
    peek(2);
    peek(3);
    peek(6);

    return 0;
}