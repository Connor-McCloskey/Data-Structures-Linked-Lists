
/*	Driver File
	NAME: Connor McCloskey
	LAST DATE MODIFIED : 02 / 19 / 2017
	ASSIGNMENT : Data Structures Homework 5
	DESCRIPTION : Implementing the concepts of linked lists and nodes
	STATUS : INCOMPLETE
	COMMENTS :
	To Do list (since Augustine's does fuck all)
	1) Implement LinkedList.h stuff. Get the list going first.
	2) Implement overloaded operators
	3) Implement main testing bringing in input.txt
	4) Do Big O analysis of insertAtFront and insertAtBack ONLY
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
#include "inputFromFile.h"

using namespace std;

int main()
{
	//Main in this program will read in the data from the file
	//Then, using a for loop and all the SS crap, push the data
	//into the lists. Then add/subtract lists. Print them out...
	//somehow...
	bool testOne = false;
	bool testTwo = false;
	LinkedList listOne;
	LinkedList listTwo;
	ifstream inFile;
	string string1;
	string string2;

	//Inserting tests
	cout << "Demonstrating lists now. Inserting A to the front of the list and Z to the back..." << endl;
	testOne = listOne.insertAtFront('a');
	testTwo = listOne.insertAtBack('z');

	//Seeing what insert at front returns
	if (testOne == false)
	{
		cout << "Insert at front failure" << endl;
	}
	if (testOne == true)
	{
		cout << "Insert at front success" << endl;
	}

	//Seeing what insert at back reutnrs
	if (testTwo == false)
	{
		cout << "Insert at back failure" << endl;
	}
	if (testTwo == true)
	{
		cout << "Insert at back success" << endl;
	}
	cout << "Printing list as it currently is..." << endl;
	listOne.print();
	cout << endl;

	//Deleting tests
	cout << "Deleting at front... " << endl;
	listOne.deleteAtFront();
	cout << "Deleting complete. Displaying results: " << endl;
	listOne.print();

	//Reading from file for overloaded operators
	cout << endl;
	cout << "Reading in from file...";
	inFile.open("input.txt");

	if (inFile.fail())
	{
		cout << "Failure opening file." << endl;
	}

	while (!inFile.eof())
	{
		getline(inFile, string1);
		getline(inFile, string2);
	}

	inputToSS(string1, listOne);
	inputToSS(string2, listTwo);

	cout << endl;
	cout << "Test for adding lists..." << endl;

	listOne + listTwo;
	
	cout << endl;
	cout << "Test for subtracting lists..." << endl;

	listOne - listTwo;

	cout << endl;
	cout << "Testing complete." << endl << endl;

	return 0;
}