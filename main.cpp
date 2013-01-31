/*
 *	File:	main.cpp
 *	Author: Connor Freeman
 *	
 *	Program 1 - CSCE 2110
 *	Implement a class Student containing 5 parameters
 *		First Name
 *		Last Name
 *		ID Number
 *		Classification
 *		Major
 *
 *	Each student is stored in an array that can 
 *		add - takes all 5 parameters of student class
 *		remove - takes 1 int parameter, ID, finds and removes entire object
 *		print - takes 1 string parameter (ex: firstname) and prints out all occurences
 *
 */

#include <iostream>
#include <string>
#include <sstream>
#include "student.h"

 using namespace std;

#define prompt "students> "
#define arraySize 20

 Student classroom[arraySize];
 int count = 0;

/* Local functions */
 bool ifexist(int id);
 int getInsertPoint();
 void print(string);
 void remove(int);
 void shiftLeft();

void splitString(string input)
{
	istringstream iss(input, istringstream::in);
	string i;
	while(iss >> i) {
		cout << i << endl;
	}
}

 int main() 
 {
 	bool done = false;
 	string command, first, last, grade, major;
 	int id;
 	string query, input;

 	while(!done) {
 		cout << prompt;
 		//cin >> command;
 			cin >> input;
 			splitString(input);

 		if(command == "add")
 		{
			/* Get new student info */
 			//cin >> first >> last >> id >> grade >> major;

 			int i = getInsertPoint();
 			bool e = ifexist(id);

			/* Check if student already exists */
 			if(e) cout << "Error! Already exists, try again" << endl;
 			else  classroom[i].add(first, last, id, grade, major);
 		}
 		else if(command == "print") 
 		{
 			/* Get query type to be printed (ex: firstname) */
 			cin >> query;
 			print(query);
 		}
 		else if(command == "remove")
 		{
 			cin >> id;
 			remove(id);
		}
		else if(command == "quit") done = true;
		else cout << "Error! Invalid input, try again." << endl;
	}
	return 0;
}


bool ifexist(int id)
{
	bool exists;
	for(int j=0; j < arraySize; j++) {
		exists = classroom[j].ifexist(id);

		if(exists)
			return true;
		else if(j == arraySize-1) 
			return false;
	}
}


int getInsertPoint() 
{
	/* Recursively count through array, return when empty node is found */
	if(classroom[count].empty())
		return count;
	
	count++;
	getInsertPoint();
}


void print(string query)
{
	/* Loop through classroom, printing as we go */
	count = 0;
	while(!classroom[count].empty()) {
		classroom[count].print(query);
		if(!classroom[count+1].empty()) cout << "-";
		count++;
	}
	cout << endl;
}


void remove(int id)
{
	/* Loop through classroom looking for id, break if found&removed, clear empty elements */
	bool removed = false;
	count = 0;

	while(!classroom[count].empty()) {
		removed = classroom[count].remove(id);

		// Element found & removed
		if(removed == 1) { 
			cout << "true" << endl;
			break;
		}
		count ++;
	}

	if(removed == 0) cout << "false" << endl;  // Element not found
			
	shiftLeft();  // Clear empty array elements
}


void shiftLeft()
{
	/* Loop through classroom, copy into temporary array, skipping empty array elements */
	Student temp[arraySize];
	int tmp=0;

	for(int i=0; i<arraySize; i++) {
		if(!classroom[i].empty()) {
			temp[tmp] = classroom[i];
			tmp++;
		}
	}
	/* Put back into classroom */
	for(int i=0; i<arraySize; i++) {
		classroom[i] = temp[i];
	}
}