// Implementing merge sort.

#include <iostream>
using namespace std;

void mergeSort(int[], int, int);
void merge(int[], int, int, int);

int main()
{
    int array[] = {12, 35, 66, 7, 4, 4, 2, 4, 2, 5, 5, 7, 0, 6765, 4, 9};
    int length = sizeof(array) / sizeof(int);

    cout << "Array before merge sort : [ ";
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]" << endl;

    mergeSort(array, 0, length - 1);

    cout << "Array after merge sort : [ ";
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}