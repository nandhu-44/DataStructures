/*
Write a program to convert a given singly linked list to a doubly linked list, by adding the
required back pointers. You may add an additional tail pointer to point to the end of the list.
Traverse and print the list contents both from head to tail, as well as tail to head .
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int data, Node *next = nullptr, Node *prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList();
    void insert(int key);
    void display();
    void display_reverse();
};

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

void DoublyLinkedList::insert(int key)
{
    Node *newNode = new Node(key);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoublyLinkedList::display()
{
    Node *current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void DoublyLinkedList::display_reverse()
{
    Node *current = tail;
    while (current)
    {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

int main()
{
    DoublyLinkedList list;
    int n, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        list.insert(key);
    }
    cout << "The doubly linked list from head to tail : ";
    list.display();
    cout << "The doubly linked list from tail to head : ";
    list.display_reverse();
    return 0;
}

/**
 * ------Input---Output------
 * Enter the number of elements: 6
 * Enter the elements: 22 43 89 90 56 67
 * The doubly linked list from head to tail : 22 43 89 90 56 67 
 * The doubly linked list from tail to head : 67 56 90 89 43 22 
*/
