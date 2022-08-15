/*
	Fish Class
*/
#include <iostream>
#include "fish.h"

using namespace std;

Fish::Fish() : Animal("Nemo", 0) {
	cout << "Default fish constructor called\n" << endl;
}

Fish::~Fish() {
	cout << "Fish destructor called." << endl;
}

void Fish::make_noise() {
   cout << "Bubbles, bubbles, bubbles." << endl;
}
