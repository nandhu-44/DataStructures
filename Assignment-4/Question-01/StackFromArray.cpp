// Implement a stack using array with the following operations : PUSH, POP, ISEMPTY, SIZE()

#include <iostream>
using namespace std;

class Stack
{
private:
    int length;
    int top;
    int *array;

public:
    Stack(int length);
    void push(int element);
    int pop();
    bool isEmpty();
    int size();
    void print();
};

Stack::Stack(int length)
{
    this->length = length;
    this->top = -1;
    this->array = new int[length];
}

void Stack::push(int element)
{
    if (top + 1 == length)
    {
        cout << "[Error]: Stack Overflow!\n";
        return;
    }
    array[++top] = element;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "[Error]: Stack Underflow!\n";
        return INT32_MIN;
    }
    return array[top--];
}

bool Stack::isEmpty()
{
    return top == -1;
}

int Stack::size()
{
    return top + 1;
}

void Stack::print()
{
    cout << "Stack : [";
    for (int i = 0; i < top + 1; i++)
    {
        cout << array[i];
        if (i != top)
        {
            cout << ", ";
        }
    }
    cout << "]\n";
}

int main()
{
    int size;
    cout << "Enter length of stack: ";
    cin >> size;
    Stack stack(size);
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