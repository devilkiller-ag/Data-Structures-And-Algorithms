/*
Author: Ashmit JaiSarita Gupta
Topic: Code for Array ADT Implementation
Date Created: 21-10-2021
*/
/*
Understanding the snippet below:-
First, we will define a structure. You can use a class and its methods in C++, but in C, a structure is used to define customized data types.
Keep the blueprint we made in the last tutorial by your side. Define the structure elements, integer variables total_size and used_size, and an integer pointer to point at the address of the first element.
We are now ready with our customized data type. Let’s define some functions, which will feature
Creating an array of this data type, 
Printing the contents of this array,
Setting values in this array.
Create a void function createArray by passing the address of a struct data type a, and integers tSize and uSize. We can very easily assign this tSize and uSize given from the main, to the total_size and used_size of the struct myArray a by either of the methods defined below.

    (*a).total_size = tSize; 
                or 
    a->total_size = tSize;
Code Snippet 1: Syntax for assigning structure elements to structure pointers.

Similarly, assign the integer pointer ptr, the address of the reserved memory location using malloc. Do use the header file <stdlib.h> for using malloc.

    a->ptr = (int *)malloc(tSize * sizeof(int));

Code Snippet 2: Using malloc

4. We will now create a show function to display all the elements of the struct myArray. We will simply pass the address of the struct myArray a. To print all the elements, we will traverse through the whole struct and print each struct element till the iterator reaches the last element. We will use a→used_size to define the loop size. Use (a→ptr)[i] to access each element.

5. We will now create a setVal function to set values to this struct myArray a and pass the address of the same. Use scanf to assign values to each element via (a→ptr)[i] .

    #include<stdio.h>
    #include<stdlib.h>
    
    struct myArray
    {
        int total_size;
        int used_size;
        int *ptr;
    };
    
    void createArray(struct myArray * a, int tSize, int uSize){
        // (*a).total_size = tSize;
        // (*a).used_size = uSize;
        // (*a).ptr = (int *)malloc(tSize * sizeof(int));
    
        a->total_size = tSize;
        a->used_size = uSize;
        a->ptr = (int *)malloc(tSize * sizeof(int));
    }
    
    void show(struct myArray *a){
        for (int i = 0; i < a->used_size; i++)
        {
            printf("%d\n", (a->ptr)[i]);
        }
    }
    
    void setVal(struct myArray *a){
        int n;
        for (int i = 0; i < a->used_size; i++)
        {
            printf("Enter element %d", i);
            scanf("%d", &n);
            (a->ptr)[i] = n;
        }
        
    }
    
    int main(){
        struct myArray marks;
        createArray(&marks, 10, 2);
        printf("We are running setVal now\n");
        setVal(&marks);
    
        printf("We are running show now\n");
        show(&marks);
    
        return 0;
    }
Code Snippet 3: A program to implement the ADT array

So, these were the basic methods we could define for this struct. We’ll check if these work by running it. We’ll call the createArray, and setVal functions first to create an array of size 2, and assign some values to it. And then call the show function to see if it works.

    Output of the above program:
    Enter element 0 : 12
    Enter element 1 : 13
    We are running show now
    12
    13
PS D:\MyData\Business\code playground\Ds & Algo with Notes\Code>

 
And this was implementing the myArray ADT.
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
    createArray(&marks, 10, 2); // Sending Address of structure to fuction using & operator and perform the specified task on content our custom array using dereferencing operator
    printf("We are running setValue() now...\n");
    setValue(&marks);          // Sending Address of structure to fuction using & operator and perform the specified task on content our custom array using dereferencing operator
    printf("We are running showArray() now...\n");
    showArray(&marks);          // Sending Address of structure to fuction using & operator and perform the specified task on content our custom array using dereferencing operator
    return 0;
}