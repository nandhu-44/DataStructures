#include <iostream>
using namespace std;

void merge(int array[], int left, int mid, int right);
void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void merge(int array[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            array[k] = leftArr[i];
            i++;
        }
        else
        {
            array[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = rightArr[j];
        j++;
        k++;
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void getArray(int array[], int n)
{
    std::cout << "Enter elements of the array : ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }
}

int main()
{
    int n;
    std::cout << "Enter size of array: ";
    std::cin >> n;
    int array[n];
    getArray(array, n);
    mergeSort(array, 0, n - 1);
    printArray(array, n);
    return 0;
}

/**
 * ___Output___
 * Enter size of array: 8
 * Enter elements of the array : 623 82 534 137 -733 28 363 8
 * -733 8 28 82 137 363 534 623
*/