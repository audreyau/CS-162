#include <iostream>
#include <stdlib.h>

#include "class.h"

using namespace std;

Matrix::Matrix () {
    cout << "default constructor" << endl;

    x = 0;
    y = 0;
    
    float** new_matrix = new float* [x];

    for (int i = 0; i < x; i++) {
        new_matrix[i] = new float [y];
    }

    matrix = new_matrix;
}

Matrix::Matrix (int rows, int cols) {
    cout << "custom constructor" << endl;

    x = rows;
    y = cols;
   
    float** new_matrix = new float* [rows];

    for (int i = 0; i < rows; i++) {
        new_matrix[i] = new float [cols];
    }

    matrix = new_matrix;
}

Matrix::~Matrix () {
    cout << "destructor" << endl; 

    for (int i = 0; i < x; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

Matrix::Matrix (const Matrix& old_obj) {
	cout << "copy constructor" << endl;

	// copy over the existing data
	x = old_obj.x;
	y = old_obj.y;
	
	// allocate a new array of occupants (and copy the existing entries)
	if ((x || y) > 0) {
        matrix = new float* [x];

		for (int i = 0; i < x; i++) {
            matrix[i] = new float [y];
        }
	} 
	else {
		matrix = NULL;
	}

}

void Matrix::setMatrix () {
    float a = 0.1;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            getRow(i)[j] = a; 
            a++;
        }
    }
}

void Matrix::settings (int rows, int cols) {
    x = rows;
    y = cols;    
}

void Matrix::display () {
    cout << "[THE MATRIX]" << endl;
    for (int i = 0; i < x; i++) {	
		for (int j = 0; j < y; j++)
			cout << getRow(i)[j] << "\t";
		cout << endl;
	}

    cout << endl << endl;
}

float* Matrix::getRow (int row) {
    if (row > x) {
        cout << "error: the row at index " << row << " is out of bounds" << endl;
        return 0;
    }
    
    else {
        float* rowIndex = matrix[row];
        return rowIndex;
    }
}
