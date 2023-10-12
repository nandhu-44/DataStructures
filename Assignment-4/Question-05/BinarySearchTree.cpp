/* Create a Binary Search Tree which supports the following operations:
◦ insert(tree, element) – adds the node specified by element (which contains the data) into the BST specified by tree.
◦ search(tree, key) – searches for the data specified by key in the BST specified by tree.
◦ delete(tree, element) – removes the node specified by element from the BST specified by tree.
◦ inorder(tree) – To do a recursive inorder traversal of the BST.
◦ preorder(tree) – To do a recursive preorder traversal of the BST.
◦ postorder(tree) – To do a recursive postorder traversal of the BST.
Write a menu driven program to demonstrate these operations.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;

    Node()
    {
        left = right = nullptr;
    }

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class BinarySearchTree
{
private:
    void inorderNode(Node *);
    void postorderNode(Node *);
    void preorderNode(Node *);

public:
    Node *root;
    BinarySearchTree()
    {
        this->root = nullptr;
    }
    void insert(int);
    bool search(int);
    void deleteNode(int);
    void inorder();
    void postorder();
    void preorder();
};

void BinarySearchTree::insert(int element)
{
    Node *newNode = new Node(element);
    if (!root)
    {
        root = newNode;
        return;
    }

    Node *current = root;
    Node *parent = nullptr;
    while (current)
    {
        parent = current;
        if (element < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (element < parent->data)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
}

bool BinarySearchTree::search(int key)
{
    Node *current = root;
    while (current)
    {
        if (key == current->data)
        {
            return true;
        }
        else if (key < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return false;
}

void BinarySearchTree::deleteNode(int element)
{
    Node *current = root;
    Node *parent = nullptr;

    // Find the node to be deleted and its parent
    while (current)
    {
        if (element == current->data)
        {
            break;
        }
        parent = current;
        if (element < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (!current)
    {
        cout << "Element not found" << endl;
        return;
    }

    // Case 1: Node has no children
    if (!current->left && !current->right)
    {
        if (!parent)
        {
            // Deleting the root node
            root = nullptr;
        }
        else if (parent->left == current)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }
        delete current;
    }
    // Case 2: Node has one child (left)
    else if (!current->right)
    {
        if (!parent)
        {
            // Deleting the root node with only a left child
            root = current->left;
        }
        else if (parent->left == current)
        {
            parent->left = current->left;
        }
        else
        {
            parent->right = current->left;
        }
        delete current;
    }
    // Case 3: Node has one child (right)
    else if (!current->left)
    {
        if (!parent)
        {
            // Deleting the root node with only a right child
            root = current->right;
        }
        else if (parent->left == current)
        {
            parent->left = current->right;
        }
        else
        {
            parent->right = current->right;
        }
        delete current;
    }
    // Case 4: Node has two children
    else
    {
        Node *successor = current->right;
        Node *successorParent = current;

        while (successor->left)
        {
            successorParent = successor;
            successor = successor->left;
        }

        current->data = successor->data;

        if (successorParent->left == successor)
        {
            successorParent->left = successor->right;
        }
        else
        {
            successorParent->right = successor->right;
        }

        delete successor;
    }
}

void BinarySearchTree::inorder()
{
    if (root)
    {
        cout << "Inorder : ";
        inorderNode(root);
        cout << endl;
    }
    else
    {
        cout << "Tree is empty" << endl;
    }
}

void BinarySearchTree::inorderNode(Node *ptr)
{
    if (ptr)
    {
        inorderNode(ptr->left);
        cout << ptr->data << " ";
        inorderNode(ptr->right);
    }
}

void BinarySearchTree::postorder()
{
    if (root)
    {
        cout << "Postorder : ";
        postorderNode(root);
        cout << endl;
    }
    else
    {
        cout << "Tree is empty" << endl;
    }
}

void BinarySearchTree::postorderNode(Node *ptr)
{
    if (ptr)
    {
        postorderNode(ptr->left);
        postorderNode(ptr->right);
        cout << ptr->data << " ";
    }
}

void BinarySearchTree::preorder()
{
    if (root)
    {
        cout << "Preorder : ";
        preorderNode(root);
        cout << endl;
    }
    else
    {
        cout << "Tree is empty" << endl;
    }
}

void BinarySearchTree::preorderNode(Node *ptr)
{
    if (ptr)
    {
        cout << ptr->data << " ";
        preorderNode(ptr->left);
        preorderNode(ptr->right);
    }
}

int main()
{
    BinarySearchTree tree;
    cout << std::boolalpha;
    bool continueLoop = true;
    int choice, element;
    cout << "-----Main Menu-----\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. Inorder\n";
    cout << "5. Postorder\n";
    cout << "6. Preorder\n";
    cout << "7. Exit\n";
    while (continueLoop)
    {
        cout << "\n----------------------------------------\n";
        cout << "Enter your choice : ";
        cin >> choice;
        cout << "----------------------------------------\n\n";
        switch (choice)
        {
        case 1:
            cout << "Enter element : ";
            cin >> element;
            tree.insert(element);
            break;
        case 2:
            cout << "Enter element : ";
            cin >> element;
            tree.deleteNode(element);
            break;
        case 3:
            cout << "Enter element : ";
            cin >> element;
            cout << element << " in tree : " << (tree.search(element) ? "true" : "false") << endl;
            break;
        case 4:
            tree.inorder();
            break;
        case 5:
            tree.postorder();
            break;
        case 6:
            tree.preorder();
            break;
        case 7:
            continueLoop = false;
            cout << "Thank you for using the program.\n\n";
            break;
        default:
            cout << "Please provide a valid choice!\n";
            break;
        }
    }
}