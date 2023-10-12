#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int size;
    int *arr;

public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    bool isFull()
    {
        return top == size - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            return arr[top--];
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Stack stack(5);
    stack.pop();
    cout << boolalpha;
    cout << "Empty : " << stack.isEmpty() << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    cout << "Full : " << stack.isFull() << endl;

    cout << stack.peek() << endl;
    stack.pop();
    cout << stack.peek() << endl;
    stack.display();

    return 0;
}