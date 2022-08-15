#include <iostream>

#include "constructors.h"

using namespace std;

int Mochi::totalCount = 0;

void Mochi::displayMochi() {
    cout << "flavor: " << flavor << endl;
    cout << "numPieces: "  << numPieces << endl;
    cout << "numCalories: "  << numCalories << endl;
    cout << "price: "  << price << endl;

    cout << "there are: " << totalCount << " mochis" << endl << endl;
}

Mochi::Mochi() {
    cout << "a mochi was created!" << endl << endl;
    totalCount ++;

    //intialize with these default values
    flavor = "unknown flavor";
    numPieces = 0;
    numCalories = 0;
    price = 0.00;
}

Mochi::Mochi (string x, int y, int z, double a) {
    cout << "a mochi was customized!" << endl << endl;
    totalCount ++;

    //user provides values
    flavor = x;
    numPieces = y;
    numCalories = z;
    price = a;
}


Mochi::~Mochi() {
    cout << "a mochi was destroyed!" << endl;
    totalCount --;
    cout << "there are: " << totalCount << " mochis" << endl;
}