#include <iostream>

#include "class.h"

using namespace std;

int main () {
    int rows, cols;

    rows = 5;
    cols = 6;

    Matrix myMatrix (rows, cols);
    Matrix newMatrix = myMatrix;
    myMatrix.settings (1, 2);

    myMatrix.setMatrix ();
    myMatrix.display ();

	newMatrix.setMatrix();
    newMatrix.display ();

    return 0;
}