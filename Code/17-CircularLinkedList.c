/*
Author: Ashmit JaiSarita Gupta
Topic: Circular Linked List Creation and Traversal
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
    struct Node *next; // Self referencing pointer
};

void displayFrom(struct Node *start)
{
    struct Node *ptr = start;
    // // Method 1
    // while (ptr->next != start) // prints one element less (node before start)
    // {
    //     printf("%d ", ptr->data);
    //     ptr = ptr->next;
    // }
    // printf("%d ", ptr->data); // printing the node before start
    // printf("\n");

    // // Method 2
    // do // prints one element less (node before start)
    // {
    //     printf("%d ", ptr->data);
    //     ptr = ptr->next;
    // } while (ptr->next != start);
    // printf("%d ", ptr->data); // printing the node before start
    // printf("\n");

    // Method 3 - better
    do // Initially both the pointers start and next points to same node initially. To ignore this case we use do-while loop.
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    printf("\n");
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
    (*node4).next = node5;

    (*node5).data = 5;
    // Link node5 and node1 to make it circualar
    node5->next = node1;

    printf("Original Circular Linked List...\n");
    // displayFrom(node1);
    displayFrom(node3);

    return 0;
}