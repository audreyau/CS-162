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

void Circle::displayCircle () {
    cout << endl;
    printf("\u001b[4m");
    cout << "Displaying a " << getName () << "..." << endl;
    printf("\x1b[0m");

    displayShape ();

    cout << "Radius: " << radius << endl;
    cout << endl;

    cout << "Area: " << area () << endl;
}

float Circle::area () {
    float x = M_PI * radius * radius;
    return x;
}