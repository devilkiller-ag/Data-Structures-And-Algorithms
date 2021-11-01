/*
Author: Ashmit JaiSarita Gupta
Topic: Deleting a node from Linked List Data Structure
Date Created: 26-10-2021
*/
/*
Notes / Theory: 

*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // Self-referencing Pointer
};

void displayFrom(struct Node *ptr) // Display the linked list from ptr
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node *deleteFromBegining(struct Node *first) // O(1)
{
    struct Node *elementToBeDeleted = first;
    first = first->next;
    free(elementToBeDeleted);
    return first;
}

struct Node *deleteAtIndex(struct Node *first, int index) // O(n)
{
    // // Method 1
    // int counter = 0;
    // struct Node *ptr = first;
    // while (counter != index - 1)
    // {
    //     ptr = ptr->next;
    //     counter++;
    // }
    // struct Node *delete = ptr->next;
    // ptr->next = delete->next;
    // free(delete);
    // return first;

    // Method 2
    struct Node *p = first;
    struct Node *q = first->next;
    int i;
    for (i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return first;
}

struct Node *deleteFromEnd(struct Node *first) // O(n)
{
    // // Method 1
    // struct Node *ptr = first;
    // while ((ptr->next)->next != NULL)
    // {
    //     ptr = ptr->next;
    // }
    // // printf("%d \n", ptr->data);
    // struct Node *delete = ptr->next;
    // ptr->next = NULL;
    // free(ptr->next);
    // return first;

    // method 2
    struct Node *p = first;
    struct Node *q = first->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return first;
}

struct Node *deleteElementOccuringFirst(struct Node *first, int elementData) // O(n)
{
    // // Method 1
    // struct Node *ptr = first;
    // while ((ptr->next)->data != elementData && (ptr->next)->next != NULL)
    // {
    //     ptr = ptr->next;
    // }
    // if ((ptr->next)->data == elementData)
    // {
    //     struct Node *delete = ptr->next;
    //     ptr->next = delete->next;
    //     free(delete);
    // }
    // else
    // {
    //     printf("Element Not Found...\m");
    // }
    // return first;

    // Method 2
    struct Node *p = first;
    struct Node *q = first->next;
    while (q->data != elementData && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == elementData)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("Element Not Found...\n");
    }
    return first;
}

int main()
{
    // Allocate memory for nodes in the linked list in Heap
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *sixth = (struct Node *)malloc(sizeof(struct Node));

    first->data = 1;
    // Link first and second nodes
    first->next = second;

    second->data = 2;
    // Link second and third nodes
    second->next = third;

    third->data = 3;
    // Link third and fourth nodes
    third->next = fourth;

    (*fourth).data = 4;
    // Link fourth and fifth nodes
    (*fourth).next = fifth;

    (*fifth).data = 5;
    // Link fifth and sixth nodes
    (*fifth).next = sixth;

    (*sixth).data = 6;
    // Terminate the linked list at the sixth node
    (*sixth).next = NULL;

    printf("Original linked list...\n");
    displayFrom(first);

    first = deleteFromBegining(first);
    printf("Linked List after deletion from the begining...\n");
    displayFrom(first);

    first = deleteFromEnd(first);
    printf("Linked List after deletion from end...\n");
    displayFrom(first);

    first = deleteAtIndex(first, 2);
    printf("Linked List after deletion from the index %d...\n", 2);
    displayFrom(first);

    first = deleteElementOccuringFirst(first, 3);
    printf("Linked List after deletion of %d...\n", 3);
    displayFrom(first);

    return 0;
}
