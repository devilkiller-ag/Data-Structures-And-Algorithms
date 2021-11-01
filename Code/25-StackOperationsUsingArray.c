/*
Author: Ashmit JaiSarita Gupta
Topic: Stack Operations While Implementing Using Arrays
Date Created: 27-10-2021
*/
/*
Notes / Theory: 

*/
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    //LIFO
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *s) //O(1)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack *s) //O(1)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

void display(struct Stack *s) // O(1)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        int i = 0;
        printf("Displaying Stack...\n");
        for (i = 0; i <= s->top; i++)
        {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

void push(struct Stack *s, int element) //O(1)
{
    if (isFull(s))
    {
        printf("Push() Failed! Stack Overflow (Stack is Full).\n");
    }
    else
    {
        // // Method 1
        // s->top++;
        // s->arr[s->top] = element;

        // Method 2
        s->arr[++s->top] = element;

        printf("Push() Successfull. Pushed %d...\n", element);
        // printf("Element: %d Top:  %d\n", s->arr[s->top], s->top);
    }
}

int pop(struct Stack *s) // O(1)
{
    if (isEmpty(s))
    {
        printf("Pop() failed! Stack Underflow (Stack is Empty).\n");
        return -1;
    }
    else
    {
        // // Method 1
        // s->arr[s->top] = element;
        // s->top--;

        // Method 2
        int popElement = s->arr[s->top--];
        printf("Pop() Successfull. Poped %d...\n", popElement);
        return popElement;
    }
}

int peek(struct Stack *sp, int i) // O(1)
{
    int arrayInd = sp->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
    }
}

int stackTop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("sackTop() failed! Stack Underflow (Stack is Empty).\n");
        return -1;
    }
    else
    {
        int topElement = s->arr[s->top];
        return topElement;
    }
}

int stackBottom(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("StackBottom() failed! Stack Underflow (Stack is Empty).\n");
        return -1;
    }
    else
    {
        int bottomElement = s->arr[0];
        return bottomElement;
    }
}

int main()
{
    // struct Stack sptr; // This creates an stack structure. We can pass stack stucture to function as Call By Value
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));

    struct Stack *sptr; // This creates an pointer to stack structure. We can pass stack stucture to function as Call By Reference. EASY!!!!!
    sptr->size = 10;
    sptr->top = -1;
    sptr->arr = (int *)malloc(sptr->size * sizeof(int));
    printf("Stack has been created successfully!\n");
    printf("isFull: %d\n", isFull(sptr));
    printf("isEmpty: %d\n", isEmpty(sptr));

    display(sptr);

    push(sptr, 1);
    display(sptr);
    push(sptr, 2);
    display(sptr);
    push(sptr, 3);
    display(sptr);
    push(sptr, 4);
    display(sptr);
    push(sptr, 5);
    display(sptr);

    pop(sptr);
    display(sptr);
    pop(sptr);
    display(sptr);
    // pop(sptr);
    // display(sptr);
    // pop(sptr);
    // display(sptr);
    // pop(sptr);
    // display(sptr);
    // pop(sptr);
    // display(sptr);

    // // Printing values from the stack
    // for (int j = 1; j <= sptr->top + 1; j++)
    // {
    //     printf("The Peeked value at position %d is %d\n", j, peek(sptr, j));
    // }

    printf("stackTop: %d \n", stackTop(sptr));
    printf("Bottom most: %d \n", stackBottom(sptr));

    return 0;
}