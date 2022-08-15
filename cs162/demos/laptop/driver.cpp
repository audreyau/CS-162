/*
	Review session demo to practice OOP.
*/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Cart.h"
#include "Laptop.h"

using namespace std;

void demoCode() {
	Cart myCart;
	myCart.initialize();
	myCart.display();
	
	Laptop myLaptop = myCart.grabLaptop();
	myCart.display();
	
	cout << "We grabbed this laptop: " << endl;
	myLaptop.display();
}


int main() {
	// seed the random number generator
	srand(time(0));
	
	demoCode();

	return 0;
}

