/*
Author: Ashmit JaiSarita Gupta
Topic: Linear And Binary Search
Date Created: 25-10-2021
*/
/*
Notes / Theory: 

*/
#include <stdio.h>

// int linearSearchRecursive(int arr[], int size, int searchElement, int i)
// {
//     int pos = -1;
//     if (i > size-1)
//     {
//         return pos;
//     }
//     else
//     {
//         if (arr[i] == searchElement)
//         {
//             pos = i + 1;
//             return pos;
//         }
//         return linearSearchRecursive(arr, size, searchElement, i+1);
//     }
// }

int linearSearchIterative(int arr[], int size, int searchElement)
{
    int i, pos = -1;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == searchElement)
        {
            pos = i + 1;
            return pos;
        }
    }
    return pos;
}

int binarySearchRecursive(int arr[], int searchElement, int low, int high)
{
    int pos = -1, mid;
    if (low == high)
    {
        if (arr[low] == searchElement)
        {
            pos = low + 1;
            return pos;
        }
        return pos;
    }
    else
    {
        mid = (low + high) / 2;
        if (arr[mid] == searchElement)
        {
            pos = mid + 1;
            return pos;
        }
        else if (arr[mid] > searchElement)
        {
            high = mid - 1;
            return binarySearchRecursive(arr, searchElement, low, high);
        }
        else // if (arr[mid]<searchElement)
        {
            low = mid + 1;
            return binarySearchRecursive(arr, searchElement, low, high);
        }
    }
}

int binarySearchIterative(int arr[], int size, int searchElement)
{
    int i, low = 0, mid, high = size - 1, pos = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == searchElement)
        {
            pos = mid + 1;
            return pos;
        }
        else if (arr[mid] > searchElement)
        {
            high = mid - 1;
        }
        else // if (arr[mid]<searchElement)
        {
            low = mid + 1;
        }
    }
    return pos;
}

int main()
{
    // // For Linear Search Recursive Method - for any array(sorted / unsorted)
    // int arrLR[7] = {1, 2, 93, 4, 34, 45, 323};
    // int sizeLR = sizeof(arrLR) / sizeof(int);
    // int searchIndexLR = linearSearchRecursive(arrLR, 34, 0, sizeLR);
    // if (searchIndexLR == -1)
    // {
    //     printf("Element Not Found.\n");
    // }
    // else
    // {
    //     printf("Element found at position %d.\n", searchIndexLR);
    // }

    // For Linear Search Iterative Method - for any array(sorted / unsorted)
    int arrLI[5] = {1, 2, 67, 34, 5};
    int sizeLI = sizeof(arrLI)/sizeof(int);
    int searchIndexLI = linearSearchIterative(arrLI, sizeLI, 34);
    if (searchIndexLI == -1)
    {
        printf("Element Not Found.\n");
    }
    else
    {
        printf("Element found at position %d.\n", searchIndexLI);
    }

    // For Binary Search Recursive Method - Only for Sorted Arrays
    int arrBR[6] = {1, 2, 3, 4, 34, 45};
    int sizeBR = sizeof(arrBR) / sizeof(int);
    int searchIndexBR = binarySearchRecursive(arrBR, 34, 0, sizeBR);
    if (searchIndexBR == -1)
    {
        printf("Element Not Found.\n");
    }
    else
    {
        printf("Element found at position %d.\n", searchIndexBR);
    }

    // For Binary Search Iterative Method - Only for Sorted Arrays
    int arrBI[6] = {1, 23, 25, 34, 45};
    int sizeBI = sizeof(arrBI) / sizeof(int);
    int searchIndexBI = binarySearchIterative(arrBI, sizeBI, 25);
    if (searchIndexBI == -1)
    {
        printf("Element Not Found.\n");
    }
    else
    {
        printf("Element found at position %d.\n", searchIndexBI);
    }
    return 0;
}