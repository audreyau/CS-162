#include <iostream>

#include "shape.h"

using namespace std;

Shape::Shape () {
    cout << "[default shape constructor]" << endl;
    name = "";
    color = "";
}

Shape::Shape (string n, string c) {
    cout << "[custom shape constructor]" << endl;
    name = n;
    color = c;
}

void Shape::displayShape () {
    cout << "Name: " << name << endl;
    cout << "Color: " << color << endl << endl;
}

float Shape::area () {
    return 0;
}

string Shape::getName () {
    return name;
}

void Shape::changeName (string n) {
    name = n;
}

void Shape::changeColor (string c) {
    color = c;
}