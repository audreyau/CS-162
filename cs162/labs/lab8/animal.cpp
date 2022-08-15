/*
	Animal Class
*/
#include <iostream>
#include "animal.h"

using namespace std;

Animal::Animal(string name, int age) {
	this->name = name;
	this->age = age;
}

Animal::Animal() {
	this->name = "Specimen Unknown";
	this->age = 0;
}

Animal::~Animal() {
}

string Animal::get_name() {
	return name;
}
