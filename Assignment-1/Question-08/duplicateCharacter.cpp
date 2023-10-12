// Write a program to count the total number of duplicate elements in an unsorted character array in O(n) time complexity

#include <iostream>
using namespace std;

int countDuplicateChars(char arr[], int size)
{
    int ASCII_SIZE = 256;            // ASCII chracters size 256
    int charCount[ASCII_SIZE] = {0}; // Setting all elements of the array to 0
    for (int i = 0; i < size; i++)
    {
        charCount[arr[i]]++; // Incrementing the count of the character
    }
    int duplicateCount = 0;
    for (int i = 0; i < ASCII_SIZE; i++)
    {
        if (charCount[i] > 1)
        {
            duplicateCount += charCount[i] - 1;
        }
    }
    return duplicateCount;
}

int main()
{
    int size;
    cout << "Enter the size of the character array: ";
    cin >> size;
    char arr[size];
    cout << "Enter the character array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
    cout << "The number of duplicate characters is: " << countDuplicateChars(arr, size) << endl;
    return 0;
}

/**
 * ___Output___
Enter the size of the character array: 6
Enter the character array
Enter element [1] : a
Enter element [2] : b
Enter element [3] : c
Enter element [4] : d
Enter element [5] : a
Enter element [6] : b
The number of duplicate characters is: 2
*/