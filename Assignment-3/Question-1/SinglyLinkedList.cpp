/*
Create a singly linked list of size n that contains positive integers. Write functions to
implement the following operations in the list:
search (key) – Search for the occurrence of the element specified by key in the list and
return its position. Display all positions if key is present multiple times. Print NOT FOUND
if key is not present.
count_duplicates (key) - Search for the occurrence of the element specified by key in the
list. Display the number of times key is duplicated. Print NO DUPLICATES if key is present
only once.
remove_duplicates (key) - Search for the occurrence of the element specified by key in the
list. Keep only the first occurrence of key and delete every other duplicate entry.
insert_pos (key, pos) – Insert the element specified by key at position pos in the list and
return the new list. pos is a postive integer. Display 'LIST TOO SMALL' if list has less than
pos - 1 entries initially.

Input format:
The first line of the input is the number of elements in the list n.
The next line contains n space separated integers constituting the list.
Each of the next line of the input contains a character from {'s', 'c', ‘r’, 'i', 'e'} followed by
one or two non-negative integers.
• ‘s key’ means search for the occurrence of the element specified by key in the list.
• ‘c key’ means display the number of times key is duplicated in the list.
• ‘r key’ means delete all duplicate entries of key in the list keeping only the first
occurrence of key.
• ‘i key pos’ means insert the element specified by key to position pos in the list.
• ‘e’ means exit the program.

*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }
    Node(int data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

class SinglyLinkedList
{
private:
    Node *head;
    int size;

public:
    SinglyLinkedList();
    void search(int key);
    void count_duplicates(int key);
    void remove_duplicates(int key);
    void insert(int key);
    void insert_pos(int key, int pos);
    int get_size() { return size; }
    void display();
};

SinglyLinkedList::SinglyLinkedList()
{
    head = nullptr;
    size = 0;
}

void SinglyLinkedList::search(int key)
{
    Node *current = head;
    int pos = 1;
    bool found = false;
    while (current)
    {
        if (current->data == key)
        {
            cout << pos << " ";
            found = true;
        }
        pos++;
        current = current->next;
    }
    if (!found)
    {
        cout << "NOT FOUND";
    }
    cout << endl;
}

void SinglyLinkedList::insert(int key)
{
    Node *newNode = new Node(key);

    if (!head)
    {
        newNode->next = head;
        head = newNode;
        size++;
        return;
    }

    Node *current = head;
    while (current->next)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    size++;
}

void SinglyLinkedList::insert_pos(int key, int pos)
{
    Node *newNode = new Node(key);

    if (pos < 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    else if (pos > size + 1)
    {
        cout << "LIST TOO SMALL" << endl;
        return;
    }

    if (!head || pos == 1)
    {
        newNode->next = head;
        head = newNode;
        size++;
        return;
    }

    Node *current = head;
    for (int i = 1; i < pos - 1; i++)
    {
        if (!current)
        {
            cout << "Invalid position!" << endl;
            return;
        }
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    size++;
}

void SinglyLinkedList::count_duplicates(int key)
{
    Node *current = head;
    int count = -1; // To subtract original.
    while (current)
    {
        if (current->data == key)
        {
            count++;
        }
        current = current->next;
    }
    if (count != -1)
    {
        cout << count << endl;
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }
}

void SinglyLinkedList::remove_duplicates(int key)
{
    bool firstOccurrence = true; // Flag to track first occurrence
    Node *current = head;
    Node *prev = nullptr;

    while (current)
    {
        if (current->data == key)
        {
            if (!firstOccurrence)
            {
                // This is a duplicate key, remove the node
                prev->next = current->next;
                delete current;
                current = prev->next;
                size--;
            }
            else
            {
                firstOccurrence = false; // Mark the first occurrence as encountered
                prev = current;
                current = current->next;
            }
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

void SinglyLinkedList::display()
{
    Node *current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    int n, key;
    cin >> n;
    SinglyLinkedList list;
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        list.insert_pos(key, i + 1);
    }
    char choice;
    while (choice != 'e')
    {

        cin >> choice;
        switch (choice)
        {
        case 's':
            cin >> key;
            list.search(key);
            break;
        case 'i':
            cin >> key;
            cin >> n;
            list.insert_pos(key, n);
            if (list.get_size() >= n)
            {
                list.display();
            }
            break;
        case 'c':
            cin >> key;
            list.count_duplicates(key);
            break;
        case 'r':
            cin >> key;
            list.remove_duplicates(key);
            list.display();
            break;
        case 'e':
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
    return 0;
}

/**
 * ------Input---Output------
 * 6
 * 10 1 0 14 5 45
 * s 11
 * NOT FOUND
 * i 5 7
 * 10 1 0 14 5 45 5
 * s 5
 * 5 7
 * i 50 9
 * LIST TOO SMALL
 * i 5 2
 * 10 5 1 0 14 5 45 5
 * c 5
 * 2
 * r 5
 * 10 5 1 0 14 45
 * e
 */