/*
	Person Class
*/
#include <iostream>
#include "Person.h"

using namespace std;

Person::Person() {
	cout << "Default person constructor called" << endl;
	name = "Name Unknown";
	email = "Unknown Email";
}

Person::Person(string n) {
	cout << "Alternate person constructor called (with string)" << endl;
	name = n;
	email = "Unknown Email";
}

string Person::getName() {
	return name;
}
