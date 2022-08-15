#include <iostream>

#include "square.h"
#include "rectangle.h"
#include "shape.h"

using namespace std;

Square::Square (double len) : Rectangle (len, len) {
    cout << "[custom square constructor]" << endl;

    changeName ("square");
}

