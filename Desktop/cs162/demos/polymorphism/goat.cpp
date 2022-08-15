/*
	Goat Class
*/
#include <iostream>
#include "goat.h"

using namespace std;

Goat::Goat() : Animal("Billy", 0) {
	cout << "Default goat constructor called\n" << endl;
}

Goat::Goat(string newName) : Animal(newName, 0) {
	cout << "Special goat constructor called\n" << endl;
}

Goat::~Goat() {
	cout << "Goat destructor called." << endl;
}

void Goat::make_noise() {
   cout << "Baaaaaa!!!" << endl;
}
