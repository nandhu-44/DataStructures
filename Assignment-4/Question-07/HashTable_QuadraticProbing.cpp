// Implement a hash table with quadratic probing using array with the following operations: INSERT(key), DELETE(key), SEARCH(key)

#include <iostream>
using namespace std;

class HashTable
{
private:
    int *arr;
    int size;
    int hash(int key);
    int quadraticProbe(int index, int i);

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

int HashTable::quadraticProbe(int index, int i)
{
    return (index + i * i) % size;
}

void HashTable::insert(int key)
{
    int index = hash(key);
    int i = 0;
    if (arr[index] == INT32_MIN)
    {
        arr[index] = key;
        return;
    }
    else if (arr[index] == key)
    {
        cout << "Key already present!\n";
        return;
    }
    else
    {
        while (i < size)
        {
            int newIndex = quadraticProbe(index, i);
            if (arr[newIndex] == INT32_MIN)
            {
                arr[newIndex] = key;
                return;
            }
            else if (arr[newIndex] == key)
            {
                cout << "Key already present!\n";
                return;
            }
            i++;
        }
        cout << "Unable to insert the key!\n";
        return;
    }
}

int HashTable::search(int key)
{
    int index = hash(key);
    int originalIndex = index;
    int i = 0;

    while (i < size)
    {
        if (arr[index] == INT32_MIN)
        {
            return INT32_MIN;
        }
        else if (arr[index] == key)
        {
            return index;
        }
        index = quadraticProbe(originalIndex, i);
        i++;
    }

    return INT32_MIN;
}

int HashTable::deleteElement(int key)
{
    int index = hash(key);
    int originalIndex = index;
    int i = 0;

    while (i < size)
    {
        if (arr[index] == INT32_MIN)
        {
            return -1;
        }
        else if (arr[index] == key)
        {
            arr[index] = INT32_MIN;
            return index;
        }
        index = quadraticProbe(originalIndex, i);
        i++;
    }

    return -1;
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
