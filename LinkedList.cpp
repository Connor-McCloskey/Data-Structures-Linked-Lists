#include "LinkedList.h"
#include "Node.h"
#include <iostream>

using namespace std;

//COMPLETE
LinkedList::LinkedList()
{
	headPtr = nullptr;
}

LinkedList::~LinkedList()
{

	Node *currentPtr = headPtr;
	while (currentPtr != nullptr)
	{
		Node * movePtr = currentPtr->next;
		delete currentPtr;
		currentPtr = movePtr;
	}
}

//COMPLETE
bool LinkedList::insertAtFront(char data)
{
	Node * temp = new Node;
	temp->next = headPtr;
	temp->data = data;
	headPtr = temp;
	if (headPtr == nullptr)
		return false;
	else
		return true;
}

//COMPLETE
bool LinkedList::insertBeforePosition(char data, int index)
{
	Node *currentPtr;
	int count = 0;
	if (headPtr == nullptr)
	{
		cout << "List empty. Please use insertAtFront to create a new list." << endl;
		return false;
	}

	for (currentPtr = headPtr; currentPtr != nullptr; currentPtr = currentPtr->next)
	{
		count++;
		if (count == index-1)
		{
			Node * temp = new Node;
			temp->next = currentPtr->next;
			currentPtr->next = temp;
			temp->data = data;
			return true;
		}
	}

	return false;

}

//COMPLETE
bool LinkedList::insertAtBack(char data)
{
	if (headPtr == nullptr)
	{
		cout << "List empty. Please use insertAtFront to create a new list." << endl;
		return false;
	}

	Node *currentPtr = headPtr;

	while (currentPtr->next != nullptr)
	{
		currentPtr = currentPtr->next;
	}

	if (currentPtr->next == nullptr)
	{
		Node * temp = new Node;
		temp->data = data;
		currentPtr->next = temp;
		return true;
	}

	else
	{
		return false;
	}
}

//COMPLETE
bool LinkedList::deleteAtFront()
{
	Node *currentPtr = headPtr;
	cout << "Test for headptr: " << headPtr->data << endl;
	Node * deletedNode = currentPtr;
	cout << "Test for deletedNode char: " << deletedNode->data << endl;
	headPtr = deletedNode->next;
	delete deletedNode;
	if (headPtr == nullptr)
	{
		return false;
	}
	else
		return true;
}

//COMPLETE
bool LinkedList::deleteBeforePosition(int index)
{
	Node *currentPtr;
	Node * deletedNode;
	int count = 0;
	for (currentPtr = headPtr; currentPtr != nullptr; currentPtr = currentPtr->next)
	{
		count++;
		if (count == index - 2)
		{
			deletedNode = currentPtr->next;
			currentPtr->next = currentPtr->next->next;
			delete deletedNode;
			return true;
		}
	}
	return false;
}

//COMPLETE
bool LinkedList::deleteAtBack()
{
	Node *currentPtr = headPtr;
	while (currentPtr->next->next != nullptr)
	{
		currentPtr = currentPtr->next;
	}
	if (currentPtr->next->next == nullptr)
	{
		Node * deletedNode = currentPtr->next->next;
		currentPtr->next = nullptr;
		delete deletedNode;
	}
	return false;
}

//COMPLETE
void LinkedList::print()
{
	Node *currentPtr;
	for (currentPtr = headPtr; currentPtr != nullptr; currentPtr = currentPtr->next)
	{
		cout << currentPtr->data << endl;
	}
}

//COMPLETE
void operator + (const LinkedList &a, const LinkedList &b)
{

	LinkedList temp;

	Node * currentPtr;
	for (currentPtr = a.headPtr; currentPtr != nullptr; currentPtr = currentPtr->next)
	{
		temp.insertAtFront(currentPtr->data);
	}

	Node * secondListPtr;
	for (secondListPtr = b.headPtr; secondListPtr != nullptr; secondListPtr = secondListPtr->next)
	{
		temp.insertAtFront(secondListPtr->data);
	}

	temp.print();
}

//COMPLETE
void operator - (const LinkedList &a, const LinkedList &b)
{
	//How am I going to do this?
	//I think if I step through the first list and add it to temp
	//In second for loop, check first to see if it's already there
	//If not, add it. If so, don't.

	LinkedList temp;

	Node * currentPtr;
	for (currentPtr = a.headPtr; currentPtr != nullptr; currentPtr = currentPtr->next)
	{
		temp.insertAtFront(currentPtr->data);
	}

	Node * secondListPtr;
	bool duplicate = false;

	for (secondListPtr = b.headPtr; secondListPtr != nullptr; secondListPtr = secondListPtr->next)
	{
		duplicate = checkDup(secondListPtr->data, temp);
		if (duplicate == false)
		{
			temp.insertAtFront(secondListPtr->data);
		}
	}
	temp.print();
}

//COMPLETE
bool checkDup(char data, const LinkedList &b)
{
	Node *currentPtr;
	for (currentPtr = b.headPtr; currentPtr != nullptr; currentPtr = currentPtr->next)
	{
		if (data == currentPtr->data)
		{
			return true;
		}
	}
	return false;
}