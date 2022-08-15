/*
	Student Class
*/
#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(string newName) {
	cout << "Alternate student constructor called" << endl;
	// set the initial gpa
	gpa = 0.0;
	name = newName;
}

string Student::getRank() {
	return "Students have a beginner rank";
}

void Student::display() {
	cout << name << " owns " << numTextbooks << " textbooks." << endl;
}
