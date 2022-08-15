/*
	Written by Justin Goins as an in-class demo of polymorphism
*/
#include <iostream>
#include "animal.h"
#include "goat.h"
#include "fish.h"
#include "test.h"

using namespace std;

/*
  Illustrate how to utilize inheritance & polymorphism
*/
int main() {

	// line 15 of animal.h marks the make_noise() function as a "pure virtual" function
	// (indicated by the "= 0"): 	virtual void make_noise() = 0;
	// this means that the Animal class is now "abstract" which implies that you
	// cannot create an Animal object (you can only create derived classes such as Fish and Goat)
	// Consequently, this line won't work anymore:
	//Animal z1;

	Goat z2("Rob");
	//Goat* z3 = & z2;

	// the following two lines are identical:
	//(*z3).make_noise();
	//z3->make_noise();

	Fish f1;

	Animal* z4;
	Animal* z5;

	z4 = &z2;
	z5 = &f1;

	// z4 is an "Animal pointer". It is now pointing at a Goat object (which is allowed).
	// The make_noise() function is using polymorphism,
	// that's why the following line of code generates a Goat noise
	
	z4 -> make_noise ();
	z5 -> make_noise ();

	Poo myPoo;
	z5 -> getPoo (myPoo);

	cout << endl;
	return 0;
}
