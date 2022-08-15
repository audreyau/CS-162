#include <iostream>
#include "house.h"

using namespace std;

string House::getAddress() {
	return address;
}

void House::displayAddress() {
	cout << "The address is: " << address << endl;
}