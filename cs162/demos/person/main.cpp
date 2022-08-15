/*
	Written by Justin Goins as an in-class demo of inheritance
*/
#include <iostream>
#include "Person.h"
#include "Student.h"

using namespace std;

/*
  Illustrate how to utilize inheritance
*/
int main() {

	cout << endl;
	Person p1("Violet");
	cout << "Person name: " << p1.getName() << endl;

 	cout << endl;
	Student s1("Malik Faasil");
	// now we can use the inherited variables and functions
	cout << "Created student. Retrieved name: " << s1.getName() << endl;

	cout << endl;
	Student *ptr = new Student("Dynamic Bob");
	cout << "Student name: " << ptr->getName() << endl;
	Person *ptr2 = ptr;
	// make sure you understand why the following line of code is valid!
	delete ptr2;

	cout << endl;

	return 0;
}
