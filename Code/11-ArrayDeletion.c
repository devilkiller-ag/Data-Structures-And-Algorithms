/*
Author: Ashmit JaiSarita Gupta
Topic: Array Deletion
Date Created: 25-10-2021
*/
/*
Notes / Theory: 

*/
#include <stdio.h>

void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indDelete(int arr[], int size, int index)
{
    int i;
    if (size == 0)
    {
        return -1;
    }
    for (i = index-1; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = NULL;
    return 1;
}

int main()
{
    int arr[100] = {1, 2, 12, 18, 8};
    int size = 5, index = 3; // counting size and index from 1 for user
    display(arr, size);
    int del = indDelete(arr, size, index); // Capacity = 100
    if (del == -1)
    {
        printf("Deletion failed! Array is empty.\n");
    }
    else
    {
        printf("Deletion Successful!\n");
        size--;
        display(arr, size);
    }
    return 0;
}