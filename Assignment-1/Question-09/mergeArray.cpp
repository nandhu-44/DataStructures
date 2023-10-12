// Write a program to merge two sorted arrays of the same size to get a resultant array which is sorted in the reverse order. Analyse the time complexity of your algorithm

#include <iostream>
using namespace std;

void readArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int *mergeArrays(int arr1[], int arr2[], int size)
{
    int *mergedArray = new int[size * 2];
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        mergedArray[k] = arr1[i];
        mergedArray[k + size] = arr2[i];
        k++;
    }
    for (int i = 0; i < size * 2; i++)
    {
        for (int j = i + 1; j < size * 2; j++)
        {
            if (mergedArray[j] > mergedArray[i]) // Sorting in reverse order
            {
                int temp = mergedArray[i];
                mergedArray[i] = mergedArray[j];
                mergedArray[j] = temp;
            }
        }
    }
    return mergedArray;
}

int main()
{
    int size;
    cout << "Enter the size of the arrays: ";
    cin >> size;
    int arr1[size], arr2[size];
    cout << endl;
    cout << "Enter the elements of array 1" << endl;
    readArray(arr1, size);
    cout << endl;
    cout << "Enter the elements of array 2" << endl;
    readArray(arr2, size);
    cout << endl;
    cout << "Array 1: ";
    printArray(arr1, size);
    cout << endl;
    cout << "Array 2: ";
    printArray(arr2, size);
    cout << endl;
    int *mergedArray = mergeArrays(arr1, arr2, size);
    cout << endl;
    cout << "The merged and sorted array is: ";
    printArray(mergedArray, size * 2);
    cout << endl;
    delete[] mergedArray;
    return 0;
}

/**
 * ___Output___
Enter the size of the arrays: 4

Enter the elements of array 1
Enter element [1] : 1
Enter element [2] : 4
Enter element [3] : 7
Enter element [4] : 10

Enter the elements of array 2
Enter element [1] : 2
Enter element [2] : 3
Enter element [3] : 5
Enter element [4] : 6

Array 1: 1 4 7 10 
Array 2: 2 3 5 6 

The merged and sorted array is: 10 7 6 5 4 3 2 1
*/

// Time Complexity: O(n^2)