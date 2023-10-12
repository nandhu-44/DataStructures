// Implement a stack using Linked List with the following operations : PUSH, POP, ISEMPTY, SIZE()

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
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
private:
    Node *head;
    int count;

public:
    Stack();
    void push(int element);
    int pop();
    bool isEmpty();
    int size();
    void print();
};

Stack::Stack()
{
    head = NULL;
    count = 0;
}

void Stack::push(int element)
{
    Node *newNode = new Node(element);
    newNode->next = head;
    head = newNode;
    count++;
}

int Stack::pop()
{
    if (!head)
    {
        cout << "[Error]: Stack Underflow!\n";
        return INT32_MIN;
    }

    Node *temp = head;
    if (head->next)
    {
        head = head->next;
    }
    else
    {
        head = NULL;
    }
    int element = temp->data;
    delete temp;
    count--;
    return element;
}

bool Stack::isEmpty()
{
    return count == 0;
}

int Stack::size()
{
    return count;
}

void Stack::print()
{
    if (!head)
    {
        cout << "Stack: []\n";
        return;
    }
    Node *current = head;
    cout << "Stack : [";
    while (current)
    {
        cout << current->data;
        if (current->next)
        {
            cout << ", ";
        }
        current = current->next;
    }
    cout << "]" << endl;
}

int main()
{
    Stack stack;
    bool continueLoop = true;
    cout << "-----Main Menu-----\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. IsEmpty\n";
    cout << "4. Size\n";
    cout << "5. Print\n";
    cout << "6. Exit\n";
    while (continueLoop)
    {
        int choice;
        cout << "\n----------------------------------------\n";
        cout << "Enter your choice : ";
        cin >> choice;
        cout << "----------------------------------------\n\n";
        switch (choice)
        {
        case 1:
            int element;
            cout << "Enter element : ";
            cin >> element;
            stack.push(element);
            break;
        case 2:
            element = stack.pop();
            if (element != INT32_MIN)
            {
                cout << "Popped element is : " << element << endl;
            }
            break;
        case 3:
            cout << "Is Empty : " << (stack.isEmpty() ? "true" : "false") << endl;
            break;
        case 4:
            cout << "Size of stack : " << stack.size() << endl;
            break;
        case 5:
            stack.print();
            break;
        case 6:
            cout << "Thank you for using the program.\n\n";
            continueLoop = false;
            break;
        default:
            cout << "Please provide a valid choice!\n";
            break;
            cout << endl;
        }
    }
}