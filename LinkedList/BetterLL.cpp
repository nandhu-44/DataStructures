#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node() : data(0), next(nullptr) {}
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList()
    {
        Node *current = head;
        while (current)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAtPosition(int value, int position)
    {
        if (position < 1)
        {
            cout << "Invalid position." << endl;
            return;
        }

        Node *newNode = new Node(value);

        // if (!head)
        // {
        //     head = newNode;
        //     return;
        // }
        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *current = head;
        for (int i = 1; i < position - 1; i++)
        {
            if (!current)
            {
                cout << "Invalid position." << endl;
                return;
            }
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    int search(int value)
    {
        int pos = 0;
        Node *current = head;
        while (current)
        {
            pos++;
            if (current->data == value)
            {
                return pos;
            }
            current = current->next;
        }
        return -1;
    }

    void remove(int value)
    {
        if (!head)
            return;

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *prev = head;
        Node *current = head->next;
        while (current)
        {
            if (current->data == value)
            {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void deleteAtEnd()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *current = head;
        Node *prev = nullptr;
        while (current->next)
        {
            prev = current;
            current = current->next;
        }
        prev->next = nullptr;
        delete current;
        cout << "Node at end deleted" << endl;
    }

    void deleteAtStart()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Node at start deleted" << endl;
    }
    
    void deleteAtPosition(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        int listLength = 0;
        Node *current = head;
        while (current != nullptr)
        {
            current = current->next;
            listLength++;
        }

        if (position < 1 || position > listLength)
        {
            cout << "Invalid position." << endl;
            return;
        }

        current = head;

        if (position == 1)
        {
            head = head->next;
            delete current;
            cout << "Node at position " << position << " deleted." << endl;
            return;
        }

        Node *previous = nullptr;
        for (int i = 1; i < position; i++)
        {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        delete current;
        cout << "Node at position " << position << " deleted." << endl;
    }

    void display()
    {
        if (!head)
        {
            cout << "List empty" << endl;
            return;
        }

        Node *current = head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    LinkedList list;

    list.display();
    int listOfInts[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    list.insertAtPosition(0, 1);
    for (int i = 0; i < 9; i++)
    {
        list.insert(listOfInts[i]);
    }

    std::cout << "Original List: ";
    list.display();
    cout << endl;

    int searchValue = 20;
    int pos = list.search(searchValue);
    if (pos != -1)
    {
        std::cout << searchValue << " found at position " << pos << std::endl;
    }
    else
    {
        std::cout << searchValue << " not found" << std::endl;
    }

    int deleteValue = 30;
    list.remove(deleteValue);
    cout << endl;
    std::cout << "List after removing " << deleteValue << ": ";
    list.display();
    cout << endl;
    list.deleteAtPosition(1);
    list.deleteAtPosition(5);
    list.display();

    return 0;
}
