/*
Author: Ashmit JaiSarita Gupta
Topic: Insertion in a linked list
Date Created: 25-10-2021
*/
/*
Notes / Theory: 

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // Self-referencing Structure
};

void linkedListTraversalFrom(struct Node *ptr) // O(n)
{
    // Display the linked list from ptr
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node *insertAtBeginning(struct Node *head, int element) // O(1)
{
    struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
    insert->data = element;
    insert->next = head;
    return insert;
}

struct Node *insertAtEnd(struct Node *head, int element) // O(n)
{
    struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
    insert->data = element;
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = insert;
    insert->next = NULL;
    return head;
}

struct Node *insertAtIndex(struct Node *head, int element, int index) // O(n)
{
    struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
    insert->data = element;
    struct Node *ptr = head;
    int counter = 0;

    while (counter != index - 1)
    {
        ptr = ptr->next;
        counter++;
    }
    insert->next = ptr->next;
    ptr->next = insert;
    return head;
}

struct Node *insertAfter(struct Node *head, struct Node *previousNode, int element) // O(1)
{
    struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
    insert->data = element;
    insert->next = previousNode->next;
    previousNode->next = insert;
    return head;
}

struct Node *insertAfterElementOccuringFirst(struct Node *start, int element, int previousElement)
{
    struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
    (*insert).data = element;
    //Method 1 - O(n)
    struct Node *ptr = start;
    while (ptr->data != previousElement && ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->data == previousElement)
    {
        //At this point, ptr points to the node containing previousElement of CLL
        insert->next = ptr->next;
        ptr->next = insert;
    }
    else
    {
        //At this point, ptr points to the last node of CLL
        printf("Element after which new element was to be inserted is Not Found in the CLL!\n");
    }
    return start;
}

main()
{
    // Allocate memory for nodes in the linked list in Heap
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 8;
    // Link first and second nodes
    head->next = second;

    second->data = 9;
    // Link second and third nodes
    second->next = third;

    third->data = 11;
    // Link third and fourth nodes
    third->next = fourth;

    fourth->data = 7;
    // Link fourth and fifth nodes
    fourth->next = fifth;

    fifth->data = 8;
    //terminate the linked list at fifth nodes
    fifth->next = NULL;

    printf("Original linked list...\n");
    linkedListTraversalFrom(head);

    head = insertAtBeginning(head, 23);
    printf("Linked list after insertion at the beginning...\n");
    linkedListTraversalFrom(head);

    head = insertAtIndex(head, 83, 1); // Will not work for index = 0 ,i.e, insertion at begining
    printf("Linked list after insertion at index %d...\n", 1);
    linkedListTraversalFrom(head);

    head = insertAfter(head, second, 59);
    printf("Linked list after insertion after the element %d...\n", second->data);
    linkedListTraversalFrom(head);

    head = insertAfterElementOccuringFirst(head, 99, 113);
    printf("Circular Linked List After insertion after element...\n");
    linkedListTraversalFrom(head);

    head = insertAtEnd(head, 576);
    printf("Linked list after insertion at the end...\n");
    linkedListTraversalFrom(head);
    return 0;
}