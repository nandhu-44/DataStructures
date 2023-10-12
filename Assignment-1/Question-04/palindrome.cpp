// Write a recursive function that checks whether a string is a palindrome (a palindrome is a string that's the same when reads forwards and backwards.)

#include <iostream>
using namespace std;

bool checkPalindrome(string s)
{
    int length = s.length(); // Using the length method to get string length.
    if (length <= 1)
        return true;
    else
        return (s[0] == s[length - 1]) && checkPalindrome(s.substr(1, length - 2)); // After each iteration, we remove first element and last element (length-1 wont work as it refers to last element, so length-2 is needed).
}

int main()
{
    string str;
    cout << "Enter the string to check palindrome : ";
    cin >> str;
    cout << "The string " << str << " is" << (checkPalindrome(str) ? " " : " not ") << "a palindrome." << endl;
    return 0;
}
