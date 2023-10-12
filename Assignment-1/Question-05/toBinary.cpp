// Write a recursive function that converts a decimal number into its binary representation.

#include <iostream>
using namespace std;

int decimalToBinary(int decimal)
{
    if (decimal < 2)
        return decimal; // Returning the last digit.
    return decimalToBinary( decimal / 2) * 10 + (decimal % 2); 
}

int main()
{
    int decimal;
    cout << "Enter the number in decimal format : ";
    cin >> decimal;
    cout << "The binary representation of " << decimal << " is " << decimalToBinary(decimal) << endl;
    return 0;
}

/**
 * ___Output___
Enter the number in decimal format : 45
The binary representation of 45 is 101101
*/