#include <iostream>
#include <cmath>

#include "circle.h"
#include "shape.h"

using namespace std;

Circle::Circle () : Shape ("circle", "no color") {
    cout << "[default circle constructor]" << endl;
    radius = 1;
}

Circle::Circle (float r) : Shape ("circle", "no color") {
    cout << "[custom circle constructor]" << endl;
    radius = r;
}

void Circle::settings (float a, float b) {
    radius = a;
}

void Circle::display () {
    cout << endl;
    printf("\u001b[4m");
    cout << "Displaying a " << getName () << "..." << endl;
    printf("\x1b[0m");

    cout << "Name: " << getName () << endl;
    cout << "Color: " << getColor () << endl << endl;

    cout << "Radius: " << radius << endl;
    cout << endl;

    cout << "Area: " << area () << endl;
}

float Circle::area () const {
    float x = M_PI * radius * radius;
    return x;
}