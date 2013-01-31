/*	
 *	File:	student.cpp
 *	Author: Connor Freeman
 *	
 *	Program 1 - CSCE 2110
 *	Student Class Functions
 */

#include <iostream>
#include <string>
#include "student.h"

using namespace std;

/* Constructor */
Student::Student() 
{
	first_name = "";
	last_name = "";
	ID = -1;
	classification = "";
	major = "";
}


/************************* ADD METHOD *************************/
void Student::add(string f, string l, int i, string c, string m) 
{
	first_name = f;
	last_name = l;
	ID = i;
	classification = c;
	major = m;
}


/********* PRINT METHOD *********/
void Student::print(string query) 
{
	if(query == "firstname") 			cout << first_name;
	else if(query == "lastname") 		cout << last_name;	
	else if(query == "id") 				cout << ID;
	else if(query == "classification") 	cout << classification;
	else if(query == "major") 			cout << major;
	else 								cout << "Error! Invalid input, try again" << endl;
}


/****** REMOVE METHOD ******/
bool Student::remove(int arg) 
{
	if(ID == arg) {
		first_name = "";
		last_name = "";
		ID = -1;
		classification = "";
		major = "";
		return true;
	}
	return false;
}


/* Checks if student is already in array by comparing id to every element in array */
bool Student::ifexist(int i)
{
	return ID == i ?  true : false;
}

/* Checks if all student parameters blank */
bool Student::empty() 
{
	return (first_name == "" && last_name == "" && ID == -1 && classification == "" && major == "") ? true : false;
}