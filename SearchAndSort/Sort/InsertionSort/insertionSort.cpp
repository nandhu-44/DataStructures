// Implementing insertion sort.

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n);

int main()
{
    int array[] = {12, 35, 66, 7, 4, 4, 2, 4, 2, 5, 5, 7, 0, 6765, 4, 9};
    int length = sizeof(array) / sizeof(int);
    cout << "Array before insertion sort : [ ";
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]" << endl;
    insertionSort(array, length);
    cout << "Array after insertion sort : [ ";
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            j--;
        }
        // for (int j = i - 1; (j >= 0 && arr[j] > arr[j + 1]); j--)
        // {
        //     swap(arr[j], arr[j + 1]);
        // }
    }
}