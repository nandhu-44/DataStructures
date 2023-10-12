/*
Write a function to implement alternate splicing of a singly linked list. Given a linked list
consisting of integers, split it into two smaller sublists, such that each of the sublists contain
alternating elements in the original list. The elements in the newly created sublists must be
in the same order as they occur in the original list.

Example:
Original list is {6, 4, 10, 13, 1, 7, 88, 10, 5}
Newly created sublists are {6, 10, 1, 88, 5} and {4, 13, 7, 10}
Input is a single line with n space seperated integers and output should be in two lines , each
line coresponding to a sublist. Please note the first line should be the sublist with first
element.
*/

#include "LinkedList.cpp"
#include <sstream>

int main()
{
    LinkedList list;
    string inputLine;
    getline(cin, inputLine); // Read the entire line

    istringstream inputStream(inputLine);
    int value;

    while (inputStream >> value)
    {
        list.insert(value);
    }

    LinkedList list1, list2;
    list.alternate_split(list1, list2);
    list1.display();
    list2.display();

    return 0;
}

/**
 * ------Input---Output------
 * 6 4 10 13 1 7 88 10 5
 * 6 10 1 88 5
 * 4 13 7 10
 */