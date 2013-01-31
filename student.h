/*	
 *	File:	student.h
 *	Author: Connor Freeman
 *	
 *	Program 1 - CSCE 2110
 *	Student Class
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	string first_name;
	string last_name;
	int ID;
	string classification;
	string major;
public:
	Student();

	/* Main class functions */
	void add(string, string, int, string, string);
	void print(string);
	bool remove(int);

	/* Helper class functions */
	bool empty();
	bool ifexist(int);
};
#endif