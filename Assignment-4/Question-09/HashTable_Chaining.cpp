// Implement a hash table using Linked List with separate chaining with the following operations : INSERT(key), DELETE(key), SEARCH(key).

#include <iostream>
#include <vector>
using namespace std;

// Define a structure for the linked list node
struct Node
{
    int key;
    Node *next;
    Node(int k) : key(k), next(nullptr) {}
};

class HashTable
{
private:
    std::vector<Node *> table;
    int tableSize;

    int hash(int key)
    {
        return key % tableSize;
    }

public:
    HashTable(int size) : tableSize(size)
    {
        table.resize(size, nullptr);
    }

    // Function to insert a key into the hash table
    void insert(int key)
    {
        int index = hash(key);
        Node *newNode = new Node(key);
        if (table[index] == nullptr)
        {
            table[index] = newNode;
        }
        else
        {
            // Handle collision by adding to the linked list
            Node *current = table[index];
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to delete a key from the hash table
    void deleteElement(int key)
    {
        int index = hash(key);
        Node *current = table[index];
        Node *prev = nullptr;

        while (current != nullptr && current->key != key)
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Key not found." << endl;
            return;
        }

        if (prev == nullptr)
        {
            // Key is in the first node of the linked list
            table[index] = current->next;
        }
        else
        {
            // Key is in a non-first node
            prev->next = current->next;
        }

        delete current;
        cout << "Key " << key << " deleted." << endl;
    }

    // Function to search for a key in the hash table
    bool search(int key)
    {
        int index = hash(key);
        Node *current = table[index];

        while (current != nullptr)
        {
            if (current->key == key)
            {
                cout << "Key " << key << " found." << endl;
                return true;
            }
            current = current->next;
        }

        cout << "Key " << key << " not found." << endl;
        return false;
    }

    void displayTable()
    {
        cout << "Hash Table : [\n";
        for (int i = 0; i < tableSize; ++i)
        {
            cout << ">> ";
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << " -> ";
                current = current->next;
            }
            cout << "||" << endl;
        }
        cout << "]" << endl;
    }

    ~HashTable()
    {
        for (int i = 0; i < tableSize; ++i)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main()
{
    int tableSize;
    cout << "Enter the size of the hash table: ";
    cin >> tableSize;

    HashTable ht(tableSize);
    cout << "-----Main Menu-----\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";

    bool continueLoop = true;
    while (continueLoop)
    {
        int choice, key;
        cout << "\n-------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "-------------------------\n\n";
        switch (choice)
        {
        case 1:
            cout << "Enter the key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            cout << "Enter the key to delete: ";
            cin >> key;
            ht.deleteElement(key);
            break;
        case 3:
            cout << "Enter the key to search: ";
            cin >> key;
            ht.search(key);
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
