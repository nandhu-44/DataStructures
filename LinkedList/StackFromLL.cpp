#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack
{
private:
    int maxSize;
    int size;
    Node *top;

public:
    Stack(int maxSize) : maxSize(maxSize), size(0), top(nullptr) {}

    ~Stack()
    {
        while (top)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int value)
    {
        if (size == maxSize)
        {
            std::cout << "Stack overflow!" << std::endl;
            return;
        }

        if (!top)
        {
            top = new Node(value);
            size++;
            return;
        }

        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack underflow!" << std::endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int peek()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void printStack()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        Node *current = top;
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
    Stack stack(5);
    cout << boolalpha;
    cout << "Is stack empty? " << stack.isEmpty() << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    stack.printStack();

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.pop();
    std::cout << "Top element after pop: " << stack.peek() << std::endl;

    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}
