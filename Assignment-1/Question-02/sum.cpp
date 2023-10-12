// Write a recursive function that, given a number n, returns the sum of the digits of the number n.

#include <iostream>
using namespace std;

// Function to calculate sum of digits.
int sumOfDigits(int n)
{
    if (n == 0) return 0; // Special condition when n becomes 0.
    return n % 10 + sumOfDigits(n/10);
}

int main()
{
    int number;
    cout << "Enter the number : ";
    cin >> number;
    cout << "The sum of the digits of " << number << " is " << sumOfDigits(number) << endl;
    return 0;
}

/**
 * ___Output___
Enter the number : 12736
The sum of the digits of 12736 is 19
*/