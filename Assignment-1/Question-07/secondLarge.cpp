// Write a program to find the second largest element of a given integer array. Can you modify it to find the k-th largest element?

#include <iostream>
using namespace std;

int secondLargest(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    return arr[1];
}

int main()
{
    int size;
    cout << "Enter size of array : ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
    cout << "Second largest element is : " << secondLargest(arr, size) << endl;
    return 0;
}

/**
 * ___Output___
Enter size of array : 10
Enter element [1] : 3
Enter element [2] : 6
Enter element [3] : 2
Enter element [4] : 7
Enter element [5] : 66
Enter element [6] : 346
Enter element [7] : 32
Enter element [8] : 45
Enter element [9] : 789
Enter element [10] : 0
Second largest element is : 346
*/