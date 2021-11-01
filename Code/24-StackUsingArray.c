/*
Author: Ashmit JaiSarita Gupta
Topic: Stacck Implementation Using Array
Date Created: 27-10-2021
*/
/*
Notes / Theory: 

*/
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // struct stack s; // This creates an stack structure. We can pass stack stucture to function as Call By Value
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));

    struct stack *s; // This creates an pointer to stack structure. We can pass stack stucture to function as Call By Reference. EASY!!!!!
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Check if stack is empty
    if (isEmpty(s))
    {
        printf("The stack is empty.\n");
    }
    else
    {
        printf("The stack is not empty.\n");
    }
    // Pushing an element manually
    s->arr[0] = 7;
    s->top++;

    // Check if stack is empty
    if (isEmpty(s))
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The stack is not empty");
    }
    return 0;
}
