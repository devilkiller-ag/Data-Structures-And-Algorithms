/*
Author: Ashmit JaiSarita Gupta
Topic: Code for Array ADT Implementation
Date Created: 21-10-2021
*/
/*
Notes / Theory: 

*/
#include <stdio.h>
#include <stdlib.h>

struct myArray // Custom Array Abstract Data Type(ADT) // this structure is only asigning memory of 4 bytes each for variables: total_size, used_size, ptr. Here memory for our custom dynamic array is not asigned and it will be crated in createArray(...) by malloc
{
    int total_size;
    int used_size;
    int *ptr; // Will Point to first memory block of our array which will be asigned by createArray(...) in the heap memory
};

void createArray(struct myArray *structPtr, int tsize, int usize) // taking address of structure to further access the structure using * operator or -> operator
{
    // this function is working same as that constructors do in object oriented programming languages like C++ and Java

    // accessing variables of structure using * operator and assigning values to them
    // (*structPtr).total_size = tsize;
    // (*structPtr).used_size = usize;
    // (*structPtr).ptr = (int *)malloc(tsize * sizeof(int)); // crated an array of size = tsize and assigned the address of its first memory block to ptr (pointer variable) of our custom array (ptr stores the address of first element/memory block of array)

    // accessing variables of structure using -> operator and assigning values to them
    structPtr->total_size = tsize;
    structPtr->used_size = usize;
    structPtr->ptr = (int *)malloc(tsize * sizeof(int)); // crated an array in the heap memory of size = tsize and assigned the address of its first memory block/element to ptr (pointer variable) of our custom array (ptr stores the address of first element/memory block of array) 
    //We are storing our memory for array in heap insted of in stack as memory asigned in stack for array is destroyed once createArray(...) func is returned but memory assigned in heap memory remains their until not freed manually.
}

void showArray(struct myArray *structPtr)
{
    int i;
    for (i = 0; i < structPtr->used_size; i++)
    {
        printf("The value at index %d is: ", i + 1);
        printf("%d\n", *(structPtr->ptr + i)); // *(structPtr->ptr + i) is same as (structPtr->ptr)[i]
    }
}

void setValue(struct myArray *structPtr)
{
    int i, value;
    for (i = 0; i < structPtr->used_size; i++)
    {
        printf("Enter Element at index %d: ", i + 1);
        scanf("%d", &value);
        (structPtr->ptr)[i] = value; // *(structPtr->ptr + i) is same as (structPtr->ptr)[i]
    }
}

int main()
{
    struct myArray marks;       // creating instance of structure
    createArray(&marks, 10, 2); // Sending Address of structure to fuction using & operator and perform the specified task on our custom array
    printf("We are running setValue() now...\n");
    setValue(&marks);          // Sending Address of structure to fuction using & operator and perform the specified task on our custom array
    printf("We are running showArray() now...\n");
    showArray(&marks);          // Sending Address of structure to fuction using & operator and perform the specified task on our custom array
    return 0;
}