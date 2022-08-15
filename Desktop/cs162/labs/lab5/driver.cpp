#include <iostream>

#include "circle.h"
#include "rectangle.h"
#include "shape.h"
#include "square.h"

using namespace std;

int main () {
    // cout << endl << "----------------------------" << endl << endl;
    // Shape shape1 ("random shape", "random color");
    // shape1.displayShape ();
    
    cout << endl << "----------------------------" << endl << endl;
    Circle circle1 (7);
    circle1.changeColor ("pink");   //making a pink circle
    circle1.displayCircle ();
    cout << endl;
    
    cout << endl << "----------------------------" << endl << endl;
    Rectangle rectangle2 (4, 3);
    rectangle2.changeColor ("purple");  //making a purple rectangle
    rectangle2.displayRectangle ();
    cout << endl;

    cout << endl << "----------------------------" << endl << endl;
    Square square1 (4.2);
    square1.changeColor ("yellow"); //making a yellow square
    square1.displayRectangle ();
    cout << endl;

    return 0;
}