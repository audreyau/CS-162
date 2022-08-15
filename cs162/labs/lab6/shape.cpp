#include <iostream>

#include "shape.h"

using namespace std;

Shape::Shape () {
    cout << "\n[default shape constructor]" << endl;
    name = "";
    color = "";
}

Shape::Shape (string n, string c) {
    cout << "\n[custom shape constructor]" << endl;
    name = n;
    color = c;
}

string Shape::getName () {
    return name;
}

string Shape::getColor () {
    return color;
}

void Shape::changeName (string n) {
    name = n;
}

void Shape::changeColor (string c) {
    color = c;
}