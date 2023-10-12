// Write a recursive function that, given a string s, prints the characters of s in reverse order.

#include <iostream>
using namespace std;

string stringReverse(string s)
{
    if (s.length() == 1)
        return s; // Special case to return if string has length of 1 character.
    return stringReverse(s.substr(1)) + s[0]; // Using the substr method to make a substring of the string and adding the first character to the last.
}

int main()
{
    string str;
    cout << "Enter the string to be reversed : ";
    cin >> str;
    cout << "The reverse of \"" << str << "\" is : " << stringReverse(str) << endl;
    return 0;
}

/**
 * ___Output___
Enter the string to be reversed : Nandhu
The reverse of "Nandhu" is : uhdnaN
*/