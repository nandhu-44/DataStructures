#include <iostream>

void selectionSort(std::string array[], int n)
{
    int minId;
    for (int i = 0; i < n - 1; i++)
    {
        minId = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[minId])
            {
                minId = j;
            }
        }
        if (minId != i)
        {
            std::swap(array[i], array[minId]);
        }
    }
}

void printArray(std::string array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void getArray(std::string array[], int n)
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
    std::string array[n];
    getArray(array, n);
    selectionSort(array, n);
    printArray(array, n);
    return 0;
}

/**
 * ___Output___
 * Enter size of array: 9
 * Enter elements of the array : one picture is worth more than ten thousand words
 * is more one picture ten than thousand words worth 
*/