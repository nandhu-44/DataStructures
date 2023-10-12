// Implement a queue using array with the following operations : ENQUEUE, DEQUEUE, ISEMPTY, SIZE()

#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int maxSize;
    int *array;

public:
    Queue(int size);
    void enqueue(int element);
    int dequeue();
    bool isEmpty();
    int size();
    void print();
};

Queue::Queue(int size)
{
    maxSize = size;
    front = -1;
    rear = -1;
    array = new int[maxSize];
}

void Queue::enqueue(int element)
{
    if (rear == maxSize - 1)
    {
        cout << "[Error]: Queue is full. Cannot enqueue.\n";
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    array[rear] = element;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "[Error]: Queue is empty. Cannot dequeue.\n";
        return INT32_MIN;
    }
    int dequeuedElement = array[front];
    if (front == rear)
    {
        front = rear = -1; // Reset the queue when the last element is dequeued.
    }
    else
    {
        front++;
    }
    return dequeuedElement;
}

bool Queue::isEmpty()
{
    return front == -1;
}

int Queue::size()
{
    if (isEmpty())
    {
        return 0;
    }
    return rear - front + 1;
}

void Queue::print()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    int i = front;
    int elementsPrinted = 0;
    cout << "Queue : [";
    while (elementsPrinted < size())
    {
        cout << array[i];
        if (elementsPrinted < size() - 1)
        {
            cout << ", ";
        }
        i = (i + 1) % maxSize;
        elementsPrinted++;
    }

    cout << "]" << endl;
}

int main()
{
    int length;
    cout << "Enter the length of the queue: ";
    cin >> length;
    Queue queue(length);
    bool continueLoop = true;
    cout << "-----Main Menu-----\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
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
            queue.enqueue(element);
            break;

        case 2:
            element = queue.dequeue();
            if (element != INT32_MIN)
            {
                cout << "Dequeued element is : " << element << endl;
            }
            break;
        case 3:
            cout << "Is Empty :  " << (queue.isEmpty() ? "true" : "false") << endl;
            break;

        case 4:
            cout << "Size : " << queue.size() << endl;
            break;
        case 5:
            queue.print();
            break;
        case 6:
            continueLoop = false;
            cout << "Thank you for using the program.\n\n";
            break;
        default:
            cout << "Please provide a valid choice!\n";
            break;
        }
    }
    return 0;
}
