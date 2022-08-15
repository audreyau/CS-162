#include <iostream>

#include "rectangle.h"
#include "shape.h"

using namespace std;

Rectangle::Rectangle () : Shape ("rectangle", "no color") {
    cout << "[default rectangle constructor]" << endl;
    width = 1;
    height = 1;
}

Rectangle::Rectangle (float w, float h) : Shape ("rectangle", "no color") {
    cout << "[custom rectangle constructor]" << endl;
    width = w;
    height = h;
}

void Rectangle::displayRectangle () {
    cout << endl;
    printf("\u001b[4m");
    cout << "Displaying a " << getName () << "..." << endl;
    printf("\x1b[0m");

    displayShape ();

    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << endl;

    cout << "Area: " << area () << endl;
}

float Rectangle::area () {
    float x = (width * height);
    return x;
}