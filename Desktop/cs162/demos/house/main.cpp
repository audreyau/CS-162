/*
	In-class demo to illustrate the development of a House class.
*/

#include <iostream>
#include "house.h"

using namespace std;


int main() {
	House myHouse;
	myHouse.address = "123 Main St, Happytown, USA";
	myHouse.displayAddress();
	
	House anotherHouse;
	anotherHouse.address = "223 4th Ave, Sunny Cove, USA";
	anotherHouse.displayAddress();
	
	House* coolHouse = new House;
	(*coolHouse).address = "330 5th Ave, Emerald Beach, USA";
	// The following commented line is identical to the next line...
	//(*coolHouse).displayAddress();
	coolHouse->displayAddress(); // uses the "arrow" operator to dereference the pointer
	
	return 0;
}