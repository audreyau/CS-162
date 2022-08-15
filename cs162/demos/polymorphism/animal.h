/*
	Animal Class
*/
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "test.h"

class Animal {
public:
	Animal(); // default constructor
	Animal(std::string, int); // alternate constructor
	~Animal(); // destructor

	void getPoo (Poo);
	//friend class Poo;
	
	std::string get_name();
	// The "virtual" keyword is super important!
	// It tells the compiler to utilize polymorphism for the make_noise() function:
	virtual void make_noise() = 0;

protected:
	std::string name;
	int age;
	int location;

	

};

#endif
