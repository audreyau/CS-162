// #include <iostream>
// #include <cstdlib>

// #include "mult_div.h"

// using namespace std;

// Matrix::Matrix () {

// }

// Matrix::Matrix (int m, int n) {
//     cout << "make" << endl;

//     x = m;
//     y = n;
//     float a = 0.1;

//     float** table = new float* [m];

//     for (int i = 0; i < x; i++) {
//         table[i] = new float [y];
//     }

//     for (int i = 0; i < x; i++) {
//         for (int j = 0; j < y; j++) {
//             table[i][j] = a; 
//             a++;
//         }
//     }

//     matrix = table;
// }


// void Matrix::display () {
//     cout << endl << "Table:" << endl;

//     for (int i = 0; i < x; i++) {	
// 		for (int j = 0; j < y; j++)
// 			cout << matrix[i][j] << "\t";
// 		cout << endl;
// 	}

//     cout << endl;
// }

// Matrix::~Matrix () {
//     cout << "destroy" << endl;

//     for (int i = 0; i < x; i++)
//         delete[] matrix[i];

//     delete[] matrix;
// }

// Matrix::Matrix (const Matrix& old_obj) {
// 	cout << "copy constructor" << endl;

// 	// copy over the existing data
// 	x = old_obj.x;
// 	y = old_obj.y;
	
//     matrix = new float* [x];

//     for (int i = 0; i < x; i++) {
//         matrix[i] = new float [y];

//         for (int j = 0; j < y; j++) {
//             matrix[i][j] = old_obj.matrix[i][j];
//         }
        
//     }

// }

// void Matrix::settings (int rows, int cols) {
//     x = rows;
//     y = cols;    
// }