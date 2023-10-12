// Implementing linear search.

#include <iostream>
using namespace std;

int linearSearch(int[], int, int);

int main()
{
    int array[] = {1, 5, 6, 2, 5, 22, 5, 3, 5, 6, 3, 6, 3, 5, 7, 100, 4, 5, 6};
    int length = sizeof(array) / sizeof(int);
    cout << "Size is " << length << endl;
    int element;
    cout << "Enter element to search : ";
    cin >> element;
    int index = linearSearch(array, length, element);
    if (index != -1)
    {
        cout << "Element found at index : " << index << endl;
    }
    else
    {
        cout << "Element not found!" << endl;
    }
    return 0;
}

int linearSearch(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}