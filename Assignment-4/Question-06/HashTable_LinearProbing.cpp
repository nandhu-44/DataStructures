// Implement a hash table with linear probing using array with the following operations : INSERT(key), DELETE(key), SEARCH(key).

#include <iostream>
using namespace std;

class HashTable
{
private:
    int *arr;
    int size;
    int hash(int key);

public:
    HashTable(int size);
    void insert(int key);
    int deleteElement(int key);
    int search(int key);
    void displayTable();
    ~HashTable();
};

HashTable::HashTable(int size)
{
    this->size = size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = INT32_MIN;
    }
}

int HashTable::hash(int key)
{
    return std::abs(key) % size;
}

void HashTable::insert(int key)
{
    int index = hash(key);
    int originalIndex = index;
    if (arr[index] != INT32_MIN)
    {
        int i = 1;
        while (arr[hash(index + i)] != INT32_MIN)
        {
            if (hash(index + i) == originalIndex)
            {
                cout << "Hash Table is full! Cannot insert key.\n";
                return;
            }
            i++;
        }
        index = hash(index + i);
    }
    arr[index] = key;
}

int HashTable::deleteElement(int key)
{
    int index = hash(key);
    if (arr[index] == key)
    {
        arr[index] = INT32_MIN;
        return index;
    }
    else
    {
        int i = 1;
        int originalIndex = index;
        while (arr[hash(index + i)] != key)
        {
            if (hash(index + i) == originalIndex)
            {
                return -1;
            }
            i++;
        }
        index = hash(index + i);
        arr[index] = INT32_MIN;
        return index;
    }
}

int HashTable::search(int key)
{
    int index = hash(key);
    if (arr[index] == key)
        return index;
    else
    {
        int i = 1;
        int originalIndex = index;
        while (arr[hash(index + i)] != key)
        {
            if (hash(index + i) == originalIndex)
            {
                return INT32_MIN;
            }
            i++;
        }
        index = hash(index + i);
        return index;
    }
    return INT32_MIN;
}

void HashTable::displayTable()
{
    cout << "Hash Table : [";
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == INT32_MIN)
        {
            cout << "-";
        }
        else
        {
            cout << arr[i];
        }

        if (i != size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

HashTable::~HashTable()
{
    delete[] arr;
}

int main()
{
    int size;
    cout << "Enter the size of the hash table : ";
    cin >> size;
    HashTable ht(size);
    bool continueLoop = true;
    cout << "-----Main Menu-----\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";
    while (continueLoop)
    {
        int choice, key, index;
        cout << "\n----------------------------------------\n";
        cout << "Enter your choice : ";
        cin >> choice;
        cout << "----------------------------------------\n\n";
        switch (choice)
        {
        case 1:
            cout << "Enter the key to insert : ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            cout << "Enter the key to delete : ";
            cin >> key;
            index = ht.deleteElement(key);
            if (index == -1)
                cout << "Key not found!\n";
            else
                cout << "Key deleted at index : " << index << endl;
            break;
        case 3:
            cout << "Enter the key to search : ";
            cin >> key;
            index = ht.search(key);
            if (index == INT32_MIN)
                cout << "Key not found!\n";
            else
                cout << "Key found at index : " << index << endl;
            break;
        case 4:
            ht.displayTable();
            break;
        case 5:
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
