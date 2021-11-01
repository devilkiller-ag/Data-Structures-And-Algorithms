/*
Author: Ashmit JaiSarita Gupta
Topic: Stack Implementation Using Linked List: (Pop Method 1 and 2) - 1
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

int isEmpty(struct Node *top)
{
    if (top == NULL) // if top pointer stores no address
    {
        return 1;
    }
    return 0;
}

int isFULL(struct Node *top)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        // printf("Stack Overflow! Heap Memory is Full.\n");
        return 1;
    }
    return 0;
}

void display(struct Node *top)
{
    // if (isEmpty(top))
    // {
    //     printf("Stack Underflow!\n");
    //     return;
    // }
    printf("Displaying Stack...\n");
    struct Node *ptr = top;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node *push(struct Node *top, int element) // O(1)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (isFULL(top))
    {
        printf("Stack Overflow! Heap Memory is Full.\n");
        return top;
    }
    n->data = element;
    n->next = top;
    top = n;
    return top;
}

struct Node *pop1(struct Node *top) // O(1)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow!\n");
        return top;
    }
    struct Node *p = top;
    top = top->next;
    printf("The Popped Element is: %d\n", p->data);
    free(p);
    return top;
}

int pop2(struct Node **top) // O(1) // **top = *(*top) = pointer of top pointer 
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node *p = *top;
    *top = (*top)->next;
    int popped = p->data;
    // printf("The Popped Element is: %d\n", popped);
    free(p);
    return popped;
}

int main()
{
    struct Node *top = NULL;

    top = push(top, 56);
    display(top);
    top = push(top, 45);
    display(top);
    top = push(top, 76);
    display(top);
    top = push(top, 98);
    display(top);
    top = push(top, 938);
    display(top);
    top = push(top, 298);
    display(top);

    // For Method 1 Popper
    top = pop1(top); // sending top pointer
    display(top);
    top = pop1(top); // sending top pointer
    display(top);

    // For Method 2 Popper
    int element1 = pop2(&top); // sending address of top pointer
    printf("The Popped Element is: %d\n", element1);
    display(top);
    int element2 = pop2(&top); // sending address of top pointer
    printf("The Popped Element is: %d\n", element2);
    display(top);

    return 0;
}