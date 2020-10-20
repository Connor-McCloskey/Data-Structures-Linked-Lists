

#ifndef INPUT_
#define INPUT_

#include "LinkedList.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

void inputToSS(string input, LinkedList &list)
{
	stringstream ss;
	ss << input;
	char insert;

	while (ss >> insert)
	{
		if (ss.fail())
		{
			cout << "Failure." << endl;
		}
		list.insertAtFront(insert);
	}

}

#endif // !INPUT_


