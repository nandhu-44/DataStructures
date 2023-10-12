// Write a recursive implementation of the factorial function. Recall that n! = 1 × 2 × ... × n, with the special case that 0! = 1.

#include <iostream>
using namespace std;

// Factorial recursive function.
int factorial(int n)
{
    if (n == 0) // The 0! = 1 special condition.
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int number;
    cout << "Enter the number to find factorial: ";
    cin >> number; 
    if (number < 0) // Checking for positive number inputs.
    {
        cout << "Cannot find factorial of negative numbers!" << endl;
        return 1;
    }
    cout << "The factorial of " << number << " is : " << factorial(number) << endl;
    return 0;
}

/**
 * ___Output___
Enter the number to find factorial: 5
The factorial of 5 is : 120
*/