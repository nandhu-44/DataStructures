// Implementing binary search.

#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int element)
{
    int mid = (low + high) / 2;
    if (low > high)
        return -1;

    if (arr[mid] == element)
    {
        return mid;
    }
    else if (arr[mid] < element)
    {
        return binarySearch(arr, mid + 1, high, element);
    }
    else
    {
        return binarySearch(arr, low, mid - 1, element);
    }
}

int main()
{
    int arr[6] = {1, 4, 6, 8, 12, 44};
    int index = binarySearch(arr, 0, 5, 1);
    if(index == -1)
        cout << "Element not found." << endl;
    else
        cout << "Element found at index " << index << endl;
    return 0;
}