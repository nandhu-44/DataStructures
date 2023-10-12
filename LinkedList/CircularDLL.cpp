#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the end
    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    // Insert at the beginning
    void insertAtBegin(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at a specific position
    void insertAtPosition(int value, int position)
    {
        if (position < 1)
        {
            cout << "Invalid position." << endl;
            return;
        }

        Node *newNode = new Node(value);

        if (position == 1)
        {
            insertAtBegin(value);
            return;
        }

        Node *current = head;
        int currentPosition = 1;
        while (current)
        {
            if (currentPosition == position - 1)
            {
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next)
                {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                return;
            }
            current = current->next;
            currentPosition++;
        }

        cout << "Invalid position." << endl;
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
        Node *current = head;
        while (current)
        {
            if (current->data == value)
            {
                if (current == head)
                {
                    head = current->next;
                    if (head)
                    {
                        head->prev = nullptr;
                    }
                }
                else
                {
                    if (current == tail)
                    {
                        tail = current->prev;
                    }
                    current->prev->next = current->next;
                    if (current->next)
                    {
                        current->next->prev = current->prev;
                    }
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    void deleteAtEnd()
    {
        if (!tail)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        if (tail)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
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
        if (head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
        cout << "Node at start deleted" << endl;
    }

    void deleteAtPosition(int position)
    {
        if (position < 1)
        {
            cout << "Invalid position." << endl;
            return;
        }

        if (position == 1)
        {
            deleteAtStart();
            return;
        }

        int currentPosition = 1;
        Node *current = head;
        while (current)
        {
            if (currentPosition == position)
            {
                current->prev->next = current->next;
                if (current->next)
                {
                    current->next->prev = current->prev;
                }
                else
                {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
            currentPosition++;
        }

        cout << "Invalid position." << endl;
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
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    list.display();
    int listOfInts[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    list.insertAtBegin(0);
    for (int i = 0; i < 9; i++)
    {
        list.insert(listOfInts[i]);
    }

    cout << "Original List: ";
    list.display();
    cout << endl;

    int searchValue = 20;
    int pos = list.search(searchValue);
    if (pos != -1)
    {
        cout << searchValue << " found at position " << pos << endl;
    }
    else
    {
        cout << searchValue << " not found" << endl;
    }

    int deleteValue = 30;
    list.remove(deleteValue);
    cout << endl;
    cout << "List after removing " << deleteValue << ": ";
    list.display();
    cout << endl;
    list.deleteAtPosition(1);
    list.deleteAtPosition(5);
    list.display();

    return 0;
}
