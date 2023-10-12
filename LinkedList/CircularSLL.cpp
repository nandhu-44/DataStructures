#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = nullptr;

    Node() : data(0), next(nullptr) {}
    Node(int value) : data(value), next(nullptr) {}
};

class CircularSinglyLinkedList
{
private:
    Node *head;

public:
    CircularSinglyLinkedList() : head(nullptr) {}

    // Check if the list is empty
    bool isEmpty()
    {
        return head == nullptr;
    }

    // Insert at the end
    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            head = newNode;
            newNode->next = head; // Circular reference
        }
        else
        {
            Node *current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head; // Update the last node's next pointer
        }
    }

    // Insert at the beginning
    void insertAtBegin(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            head = newNode;
            newNode->next = head; // Circular reference
        }
        else
        {
            Node *current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            newNode->next = head; // Update the new node's next pointer
            head = newNode;
            current->next = head; // Update the last node's next pointer
        }
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
        while (current && currentPosition < position - 1)
        {
            current = current->next;
            currentPosition++;
        }

        if (!current)
        {
            cout << "Invalid position." << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Search for a value and return its position
    int search(int value)
    {
        if (isEmpty())
            return -1;

        Node *current = head;
        int pos = 1;
        do
        {
            if (current->data == value)
            {
                return pos;
            }
            current = current->next;
            pos++;
        } while (current != head);

        return -1;
    }

    // Remove a value from the list
    void remove(int value)
    {
        if (isEmpty())
            return;

        if (head->data == value)
        {
            if (head->next == head)
            {
                delete head;
                head = nullptr;
                return;
            }
            Node *current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            current->next = head->next;
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *current = head;
        while (current->next != head)
        {
            if (current->next->data == value)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    // Delete the first node
    void deleteAtStart()
    {
        if (isEmpty())
            return;

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = head->next;
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Delete at a specific position
    void deleteAtPosition(int position)
    {
        if (isEmpty() || position < 1)
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
        Node *prev = nullptr;

        do
        {
            prev = current;
            current = current->next;
            currentPosition++;
        } while (current != head && currentPosition < position);

        if (current == head || currentPosition != position)
        {
            cout << "Invalid position." << endl;
            return;
        }

        prev->next = current->next;
        delete current;
    }

    // Display the circular linked list
    void display()
    {
        if (isEmpty())
        {
            cout << "List empty" << endl;
            return;
        }

        Node *current = head;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main()
{
    CircularSinglyLinkedList list;

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

    cout << "Deleting at position 1:" << endl;
    list.deleteAtPosition(1);
    list.display();

    cout << "Deleting at position 5:" << endl;
    list.deleteAtPosition(5);
    list.display();

    cout << "Deleting at start:" << endl;
    list.deleteAtStart();
    list.display();

    return 0;
}
