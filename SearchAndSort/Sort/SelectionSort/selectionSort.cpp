// Implementing selection sort.

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n);

int main()
{
    int array[] = {12, 35, 66, 7, 4, 4, 2, 4, 2, 5, 5, 7, 0, 6765, 4, 9};
    int length = sizeof(array) / sizeof(int);
    cout << "Array before selection sort : [ ";
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]" << endl;
    selectionSort(array, length);
    cout << "Array after selection sort : [ ";
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}

void selectionSort(int arr[], int n)
{
    int minId;
    for (int i = 0; i < n - 1; i++)
    {
        minId = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minId])
                minId = j;
        }

        if (minId != i)
        {
            swap(arr[minId], arr[i]);
        }
    }
}