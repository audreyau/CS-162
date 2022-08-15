#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Cart.h"

using namespace std;

void Cart::initialize() {
	numLaptops = MAXNUMLAPTOPS;
	
	for (int i = 0; i < MAXNUMLAPTOPS; i++) {
		laptops[i].randomize();
	}
}

void Cart::display() {
	for (int i = 0; i < numLaptops; i++) {
		laptops[i].display();
	}
}

Laptop Cart::grabLaptop() {
	int indexToGrab = rand() % numLaptops;
	
	// debug
	cout << "Grabbing laptop at index: " << indexToGrab << endl;
	
	// get a copy of the laptop
	Laptop tmp = laptops[indexToGrab];
	
	// scoot all the lower laptops up by one position
	for (int i = 0; i < (numLaptops - indexToGrab - 1); i++) {
		laptops[indexToGrab + i] = laptops[indexToGrab + i + 1];
	}
	// there is one less laptop on the cart
	numLaptops--;
	
	return tmp;
}







