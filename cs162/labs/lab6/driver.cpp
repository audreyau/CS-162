#include <iostream>

#include "circle.h"
#include "rectangle.h"
#include "shape.h"
#include "square.h"

using namespace std;

bool operator> (const Shape& a, const Shape& b) {
    float area1 = a.area();
    float area2 = b.area();

    if (area1 > area2)
        return true;
    else  
        return false;
}

int main () {
    Shape** array_of_shapes = new Shape*[3];

    //OPTION 1
    // array_of_shapes[0] = new Circle (7);
    // array_of_shapes[1] = new Rectangle (4, 3);
    // array_of_shapes[2] = new Square (4.2);

    //OPTION 2
    array_of_shapes[0] = new Circle;
    array_of_shapes[1] = new Rectangle;
    array_of_shapes[2] = new Square;

    for (int i = 0; i < 3; i++) {
        array_of_shapes[i] -> settings (2, 2);
    }
    
    cout << endl;

    for (int i = 0; i < 3; i++) {
        array_of_shapes[i] -> display ();
        cout << endl;
    }

    //IMPORTANT NOTE:
    // array_of_shapes[0] -> getName()
    // (*array_of_shapes[1]).getName()
    //are the same

    //compare shape areas
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            printf("\u001b[4m");
            cout << "Between the " << array_of_shapes[i] -> getName() << " and the " << array_of_shapes[j] -> getName() << "..." << endl;
            printf("\x1b[0m");

            if (*array_of_shapes[i] > *array_of_shapes[j]) 
                cout << "The " << array_of_shapes[i] -> getName() << " has a larger area";
            else 
                cout << "The " << array_of_shapes[i] -> getName() << " does not have a larger area";
        
            cout << endl << endl;
        }
    }

    //delete memory
    for (int i = 0; i < 3; i++) {
        delete array_of_shapes[i];
    }

    delete[] array_of_shapes;

    return 0;
}