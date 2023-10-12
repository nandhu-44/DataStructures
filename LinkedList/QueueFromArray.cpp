#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *arr;

public:
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
            }
            else
            {
                rear = (rear + 1) % size;
            }
            arr[rear] = value;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else
        {
            int value = arr[front];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
            return value;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl;
    }
};

int main()
{
    Queue queue(5);

    queue.dequeue();
    cout << boolalpha;
    cout << "Empty : " << queue.isEmpty() << endl;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60); // Queue is full
    queue.display();
    cout << "Full : " << queue.isFull() << endl;

    cout << queue.peek() << endl;
    queue.dequeue();
    queue.dequeue();
    queue.enqueue(60);
    queue.enqueue(70);
    cout << queue.peek() << endl;
    queue.display();

    return 0;
}
