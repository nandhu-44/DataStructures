#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class Linkedlist
{
	Node *head;

public:
	Linkedlist() { head = NULL; }

	void insertNode(int);
	void printList();
	void deleteNode(int);
};

void Linkedlist::deleteNode(int nodeOffset)
{
	Node *temp1 = head, *temp2 = NULL;
	int ListLen = 0;

	if (head == NULL)
	{
		cout << "List empty." << endl;
		return;
	}

	while (temp1 != NULL)
	{
		temp1 = temp1->next;
		ListLen++;
	}

	// Check if the position to be deleted is greater than the length of the linked list.
	if (ListLen < nodeOffset)
	{
		cout << "Index out of range"
			 << endl;
		return;
	}

	temp1 = head;

	// Deleting the head.
	if (nodeOffset == 1)
	{

		// Update head
		head = head->next;
		delete temp1;
		return;
	}

	// Traverse the list to find the node to be deleted.
	while (nodeOffset-- > 1)
	{

		// Update temp2
		temp2 = temp1;
		// Update temp1
		temp1 = temp1->next;
	}

	// Change the next pointer of the previous node.
	temp2->next = temp1->next;

	// Delete the node
	delete temp1;
}

void Linkedlist::insertNode(int data)
{
	Node *newNode = new Node(data);

	// Assign to head
	if (head == NULL)
	{
		head = newNode;
		return;
	}

	// Traverse till end of list
	Node *temp = head;
	while (temp->next != NULL)
	{

		// Update temp
		temp = temp->next;
	}

	// Insert at the last.
	temp->next = newNode;
}

void Linkedlist::printList()
{
	Node *temp = head;

	if (head == NULL)
	{
		cout << "List empty" << endl;
		return;
	}

	// Traverse the list.
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	Linkedlist list;

	// Inserting nodes
	list.insertNode(1);
	list.insertNode(2);
	list.insertNode(3);
	list.insertNode(4);
	list.insertNode(5);
	list.insertNode(0);

	cout << "Elements of the list are: ";

	// Print the list
	list.printList();
	cout << endl;

	// Delete node at position 2.
	list.deleteNode(2);

	cout << "Elements of the list are: ";
	list.printList();
	cout << endl;
	return 0;
}
