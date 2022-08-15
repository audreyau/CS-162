#include <iostream>
#include <cstdlib>
#include "Laptop.h"

using namespace std;

// assign random values to the system specs
void Laptop::randomize() {
	ramSpace = 4 + (rand() % 29);
	hddSpace = 200 + (rand() % 1001);
	screenSize = 13.0 + (rand() % 6);
	id = rand();
}

void Laptop::display() {
	cout << "Laptop " << id << " has " << ramSpace << "GB RAM, "
	<< hddSpace << "GB HDD, and a " << screenSize << " in. screen" << endl;
}