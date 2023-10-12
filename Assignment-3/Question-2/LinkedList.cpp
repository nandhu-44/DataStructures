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

class LinkedList
{
private:
    Node *head;
    int size;

public:
    LinkedList();
    void display(void);
    void insert(int value);
    void insert_pos(int value, int pos);
    void delete_pos(int pos);
    void alternate_split(LinkedList &list1, LinkedList &list2);
};

LinkedList::LinkedList()
{
    head = nullptr;
    size = 0;
}

void LinkedList::display(void)
{
    Node *current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::insert(int value)
{
    Node *new_node = new Node(value);
    if (!head)
    {
        head = new_node;
    }
    else
    {
        Node *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    size++;
}

void LinkedList::insert_pos(int value, int pos)
{
    if (pos < 1 || pos > size + 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    Node *new_node = new Node(value);
    if (pos == 1)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        Node *current = head;
        for (int i = 1; i < pos - 1; i++)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    size++;
}

void LinkedList::delete_pos(int pos)
{
    if (pos < 1 || pos > size)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node *current = head;
        for (int i = 1; i < pos - 1; i++)
        {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    size--;
}

void LinkedList::alternate_split(LinkedList &list1, LinkedList &list2)
{
    Node *current = head;
    while (current)
    {
        list1.insert(current->data);
        if (current->next)
        {
            list2.insert(current->next->data);
            current = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }
}