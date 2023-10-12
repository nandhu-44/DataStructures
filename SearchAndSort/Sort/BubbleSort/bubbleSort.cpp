// Implementing bubble sort.

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n);

int main()
{
    int array[] = {12, 35, 66, 7, 4, 4, 2, 4, 2, 5, 5, 7, 0, 6765, 4, 9};
    int length = sizeof(array) / sizeof(int);
    cout << "Array before bubble sort : [ ";
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]" << endl;
    bubbleSort(array, length);
    cout << "Array after bubble sort : [ ";
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}