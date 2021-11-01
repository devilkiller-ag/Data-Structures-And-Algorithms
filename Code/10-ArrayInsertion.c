/*
Author: Ashmit JaiSarita Gupta
Topic: Array insertion
Date Created: 25-10-2021
*/
/*
Notes / Theory: 

*/
#include <stdio.h>

void display(int arr[], int n)
{
    int i;
    // Traversal
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indnsertion(int arr[], int size, int element, int capacity, int index)
{
    int i, temp;
    if (size >= capacity)
    {
        return -1; // insertion was not successful
    }
    for (i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5;
    display(arr, size);
    int element = 45, index = 3;
    int ins = indnsertion(arr, size, element, 100, index); // capacity = 100
    if (ins == -1)
    {
        printf("Insertion failed! Array if already full.\n");
    }
    else
    {
        printf("Insertion Successful!\n");
        size++;
        display(arr, size);
    }
    return 0;
}