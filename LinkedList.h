#ifndef LINKEDLIST_
#define LINKEDLIST_

#include "Node.h"

class LinkedList {
private:
	Node * headPtr;

public:
	//Constructor
	LinkedList();
	//Destructor
	~LinkedList();

	//insertion functions
	bool insertAtFront(char data);
	bool insertBeforePosition(char data, int index);
	bool insertAtBack(char data);

	//deletion functions
	bool deleteAtFront();
	bool deleteBeforePosition(int index);
	bool deleteAtBack();

	//function for printing a list
	void print();

	//overloaded + operator for adding lists
	friend void operator + (const LinkedList &, const LinkedList &);

	//overloaded - operator for subtracting lists
	friend void operator - (const LinkedList &, const LinkedList &);

	//friend function for checking duplicates in lists
	friend bool checkDup(char data, const LinkedList &);
};

#endif // !LINKEDLIST_

