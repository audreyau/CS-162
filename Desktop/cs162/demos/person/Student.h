/*
	Student Class
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Person.h"

class Student : public Person {
public:
	Student(std::string);
	std::string getRank();
	void display();

private:
	// Note that derived classes can also have extra properties in addition
	// to the ones that are inherited.
	double gpa;
	std::string major;
	int numTextbooks = 0;
};
#endif
