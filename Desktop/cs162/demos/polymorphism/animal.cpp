/*
	Animal Class
*/
#include <iostream>
#include "animal.h"
#include "test.h"

using namespace std;

Animal::Animal(string x, int y) {
	cout << "Alternate animal constructor called" << endl;
	name = x;
	age = y;
}

Animal::Animal() {
	cout << "Default animal constructor called" << endl;
	this->name = "Specimen Unknown";
	this->age = 0;
}

Animal::~Animal() {
	cout << "Animal destructor invoked\n" << endl;
}

string Animal::get_name() {
	return name;
}

void Animal::getPoo (Poo a) {
	cout << "poo: " << a.poop << endl;
	cout << "pee: " << a.pee << endl;
}

/*
void Animal::make_noise() {
	cout << "??? UNKNOWN NOISE" << endl;
}
*/
