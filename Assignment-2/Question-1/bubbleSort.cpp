#include <iostream>

void bubbleSort(float array[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void printArray(float array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void getArray(float array[], int n)
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
    float array[n];
    getArray(array, n);
    bubbleSort(array, n);
    printArray(array, n);
    return 0;
}

/**
 *  ___Output___
 *  Enter size of array: 8
 *  Enter elements of the array : 623.43 82.412 534.612 137.6 -733.216 28.16 363.532 8.34423
 * -733.216 8.34423 28.16 82.412 137.6 363.532 534.612 623.43
 */