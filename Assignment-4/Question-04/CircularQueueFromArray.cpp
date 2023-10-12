// Implement a circular queue using array with the following operations : ENQUEUE, DEQUEUE, ISEMPTY, SIZE()

#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int front, rear;
    int length;
    int *array;
    int count;

public:
    CircularQueue(int length);
    void enqueue(int element);
    int dequeue();
    bool isEmpty();
    bool isFull();
    int size();
    void print();
};

CircularQueue::CircularQueue(int length)
{
    this->length = length;
    this->array = new int[length];
    front = 0;
    rear = -1;
    count = 0;
}

void CircularQueue::enqueue(int element)
{
    if (isFull())
    {
        cout << "[Error]: Queue is Full!" << endl;
        return;
    }
    rear = (rear + 1) % length;
    array[rear] = element;
    count++;
}

int CircularQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "[Error]: Queue is Empty!" << endl;
        return INT32_MIN;
    }
    int element = array[front];
    front = (front + 1) % length;
    count--;
    return element;
}

bool CircularQueue::isEmpty()
{
    return count == 0;
}

bool CircularQueue::isFull()
{
    return count == length;
}

int CircularQueue::size()
{
    return count;
}

void CircularQueue::print()
{
    if (isEmpty())
    {
        cout << "[Error]: Queue is Empty!" << endl;
        return;
    }
    cout << "Queue: [";
    int i = front;
    int elementsPrinted = 0;

    do
    {
        cout << array[i];
        if (elementsPrinted < count - 1)
        {
            cout << ", ";
        }
        i = (i + 1) % length;
        elementsPrinted++;
    } while (i != (rear + 1) % length);

    cout << "]" << endl;
}

int main()
{
    int length;
    cout << "Enter the length of the queue: ";
    cin >> length;
    CircularQueue queue(length);
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
