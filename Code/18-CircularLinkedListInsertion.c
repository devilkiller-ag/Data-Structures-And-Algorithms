/*
Author: Ashmit JaiSarita Gupta
Topic: Insertion in Circular Linked List
Date Created: 27-10-2021
*/
/*
Notes / Theory: 

*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // Self-Referencing Pointer
};

void displayFrom(struct Node *start) // O(n)
{
    struct Node *ptr = start;
    do // Initially both the pointers start and next points to same node initially. To ignore this case we use do-while loop.
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    printf("\n");
}

struct Node *insertAtBegining(struct Node *start, int element) // Insertion before given head. After insertion, inserted element will become new head
{
    struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
    (*insert).data = element;

    //Method 1 - O(n)
    insert->next = start;
    struct Node *ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    //At this point, ptr points to the last node of CLL
    ptr->next = insert;
    return insert;
}

struct Node *insertAtEnd(struct Node *start, int element) // Insertion before given head. After Insertion, head remains same.
{
    struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
    (*insert).data = element;

    //Method 1 - O(n)
    insert->next = start;
    struct Node *ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    //At this point, ptr points to the last node of CLL
    ptr->next = insert;
    return start;
}

struct Node *insertAfterNode(struct Node *start, int element, struct Node *previousNode)
{
    struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
    (*insert).data = element;
    //Method 1 - O(1)
    insert->next = previousNode->next;
    previousNode->next = insert;
    return start;
}

struct Node *insertAfterElementOccuringFirst(struct Node *start, int element, int previousElement)
{
    struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
    (*insert).data = element;
    //Method 1 - O(n)
    struct Node *ptr = start;
    while (ptr->data != previousElement && ptr->next != start)
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

struct Node *insertAtIndex(struct Node *start, int element, int index)
{
    struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
    insert->data = element;
    struct Node *ptr = start;
    int counter = 0;
    while (counter != index - 1)
    {
        ptr = ptr->next;
        counter++;
    }
    //At this point, ptr points to the node before the node at given of CLL
    insert->next = ptr->next;
    ptr->next = insert;
    return start;
}

int main()
{
    // Allocate memory for nodes in the circular linked list in Heap
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node4 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node5 = (struct Node *)malloc(sizeof(struct Node));

    node1->data = 1;
    // Link node1 and node2
    node1->next = node2;

    node2->data = 2;
    // Link node2 and node3
    node2->next = node3;

    node3->data = 3;
    // Link node3 and node4
    node3->next = node4;

    node4->data = 4;
    // Link node4 and node5
    node4->next = node5;

    node5->data = 5;
    // Link node5 and node1 to make the linked list circular
    node5->next = node1;

    printf("Original Circular Linked List...\n");
    displayFrom(node1);
    // displayFrom(node3);

    node1 = insertAtBegining(node1, 0); // Insertion before given head. After insertion, inserted element will become new head
    printf("Circular Linked List After insertion at begining...\n");
    displayFrom(node1);

    node1 = insertAtEnd(node1, 6); // Insertion before given head. After Insertion, head remains same.
    printf("Circular Linked List After insertion at end...\n");
    displayFrom(node1);

    node1 = insertAfterNode(node1, 34, node3);
    printf("Circular Linked List After insertion after Node...\n");
    displayFrom(node1);

    node1 = insertAfterElementOccuringFirst(node1, 99, 4);
    printf("Circular Linked List After insertion after element...\n");
    displayFrom(node1);

    node1 = insertAtIndex(node1, 123, 4);
    printf("Circular Linked List After insertion at index %d...\n", 4);
    displayFrom(node1);
    return 0;
}