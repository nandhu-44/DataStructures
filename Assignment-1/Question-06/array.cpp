/**
 * Write a menu driven program that repeatedly reads an option from the terminal to do the
following array operations on array ARR :
Option 1. Read integer n (<=100) , the size of array followed by n integer elements of
ARR
Option 2. Print the elements of array ARR
Option 3. Read an integer elem to search in the array. Print FOUND/SORRY
accordingly
Option 4. Print the largest and smallest element of the array
Option 5. Exit
The program should be modular and should contain the following functions :
main(), read_arr(int[] arr, int n), print_arr(int[] arr, int n), search_arr(int[] arr, int n,
int elem), get_max(int[] arr, int n), get_min(int[] arr, int n)
*/

#include <iostream>
using namespace std;

// Defining functions to be used.
void read_arr(int *arr, int n);
void print_arr(int *arr, int n);
int search_arr(int *arr, int n, int elem);
int get_max(int *arr, int n);
int get_min(int *arr, int n);

int main()
{
    bool continueLoop = true, assigned = false;
    int *arr;
    cout << endl;
    while (continueLoop)
    {
        int choice;
        cout << "------------------------------" << endl;
        cout << "-----Main Menu-----" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Print elements" << endl;
        cout << "3. Search element" << endl;
        cout << "4. Max and Min elements" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        cout << "------------------------------" << endl;
        cout << endl;
        switch (choice)
        {
        case 1:
            int n;
            cout << "Enter the size of the array : ";
            cin >> n;
            if (n > 100)
            {
                cout << "The size should be less than or equal to 100.";
                break;
            }
            arr = new int[n];
            read_arr(arr, n);
            assigned = true;
            break;
        case 2:
            if (assigned)
            {
                print_arr(arr, n);
                break;
            }
            else
            {
                cout << "Input data first!" << endl;
                break;
            }
        case 3:
            if (assigned)
            {
                int elem, index;
                cout << "Enter the element to search : ";
                cin >> elem;
                index = search_arr(arr, n, elem);
                if (index != -1)
                    cout << "Element \'" << elem << "\' found at index \'" << index << "\'!" << endl;
                else
                    cout << "Sorry, the element could not be found!" << endl;
                break;
            }
            else
            {
                cout << "Input data first!" << endl;
                break;
            }
        case 4:
            if (assigned)
            {
                cout << "Max element : " << get_max(arr, n) << endl;
                cout << "Min element : " << get_min(arr, n) << endl;
                break;
            }
            else
            {
                cout << "Input data first!" << endl;
                break;
            }
        case 5:
            cout << "Thanks for using the program." << endl;
            continueLoop = false;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        cout << endl;
    }
    return 0;
}

// Reading array elements individually.
void read_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
}

// Printing array elements.
void print_arr(int *arr, int n)
{
    cout << "Elements of array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i != n - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

// Searching for an element in the array.
int search_arr(int *arr, int n, int elem)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == elem)
            return i;
    }
    return -1; // If element is not found.
}

// Getting maximum from the array.
int get_max(int *arr, int n)
{
    int max = arr[0]; // Assuming first element to be the maximum.
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Getting minimum from the array.
int get_min(int *arr, int n)
{
    int min = arr[0]; // Assuming first element to be the minimum.
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

/**
 * ___Output___

------------------------------
-----Main Menu-----
1. Input Data
2. Print elements
3. Search element
4. Max and Min elements
5. Exit
Enter your choice : 1
------------------------------

Enter the size of the array : 5
Enter element [1] : 1
Enter element [2] : 6
Enter element [3] : 3
Enter element [4] : 7
Enter element [5] : 3

------------------------------
-----Main Menu-----
1. Input Data
2. Print elements
3. Search element
4. Max and Min elements
5. Exit
Enter your choice : 2
------------------------------

Elements of array : 1, 6, 3, 7, 3

------------------------------
-----Main Menu-----
1. Input Data
2. Print elements
3. Search element
4. Max and Min elements
5. Exit
Enter your choice : 3
------------------------------

Enter the element to search : 9
Sorry, the element could not be found!

------------------------------
-----Main Menu-----
1. Input Data
2. Print elements
3. Search element
4. Max and Min elements
5. Exit
Enter your choice : 3
------------------------------

Enter the element to search : 3
Element '3' found at index '2'!

------------------------------
-----Main Menu-----
1. Input Data
2. Print elements
3. Search element
4. Max and Min elements
5. Exit
Enter your choice : 4
------------------------------

Max element : 7
Min element : 1

------------------------------
-----Main Menu-----
1. Input Data
2. Print elements
3. Search element
4. Max and Min elements
5. Exit
Enter your choice : 5
------------------------------

Thanks for using the program.

*/