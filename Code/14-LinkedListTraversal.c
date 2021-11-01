/*
Author: Ashmit JaiSarita Gupta
Topic: Linked List Creation And Traversal
Date Created: 25-10-2021
*/
/*
Notes / Theory: 

*/

#include <stdio.h>
#include <stdlib.h>

// -> Operator means first dereference then apply dot operator.

struct Node
{
    int data;
    struct Node *next; // Self referencial pointer - A pointer which points to a stucture of same kind as that in which it is.
};

void linkedListTraversalFrom(struct Node *ptr) // Display the linked list from ptr
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    // Link first and second nodes
    head->next = second;

    second->data = 11;
    // Link second and third nodes
    second->next = third;

    third->data = 41;
    // Link third and fourth nodes
    third->next = fourth;

    fourth->data = 66;
    // Terminate the list at the third node
    fourth->next = NULL;

    // Display
    linkedListTraversalFrom(head);
    return 0;
}
