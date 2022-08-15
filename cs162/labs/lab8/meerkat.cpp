/*
	Meerkat Class
*/
#include <iostream>
#include "meerkat.h"

using namespace std;

Meerkat::Meerkat() : Animal("Timon", 0) {
}

Meerkat::Meerkat(string name) : Animal(name, 0) {
}

Meerkat::~Meerkat() {
}

void Meerkat::make_noise() {
   cout << "Shriek!!!" << endl;
}
