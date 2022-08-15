#include <iostream>
#include <cstdlib>
#include <iomanip>  //set precision

#include "mult_div.h"

using namespace std;

class Matrix {
    private:
        int** matrix;
        int X; // Matrix rows
        int Y; // Matrix columns

    public:
        // Default Constructor
        Matrix () {
            X = 0;
            Y = 0;
            matrix = NULL;
        }

        // Constructor with parameters
        Matrix (int _X, int _Y) {
            X = _X;
            Y = _Y;
            matrix = new int*[X];

            for (int i = 0; i < X; i++)
                matrix[i] = new int[Y];

            for (int i = 0; i < X; i++) {
                for (int j = 0; j < Y; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Copy constructor
        Matrix (const Matrix& N) {
            X = N.X;
            Y = N.Y;

            matrix = new int*[X];

            for (int i = 0; i < X; i++)
                matrix[i] = new int[Y];

            for (int i = 0; i < X; i++) {
                for (int j = 0; j < Y; j++) {
                    matrix[i][j] = N.matrix[i][j];
                }
            }
        }
        
        // Destructor
        ~Matrix () {
            for (int i = 0; i < X; i++)
                delete[] matrix[i];

            delete[] matrix;
        }

        //--------------------------------------
        void display () {
            for (int i = 0; i < X; i++) {
                for (int j = 0; j < Y; j++)
                    cout << matrix[i][j] << "\t";

                cout << endl << endl;
            }
        }

        void settings (int x, int y) {
            for (int i = 0; i < X; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;

            X = x;
            Y = y;

            matrix = new int*[X];

            for (int i = 0; i < X; i++)
                matrix[i] = new int[Y];

            for (int i = 0; i < X; i++) {
                for (int j = 0; j < Y; j++) {
                    matrix[i][j] = 0;
                }
            }
                
        }

};

int main () {
    Matrix x (5, 7);
    Matrix y = x;

    y.settings (8, 8);

    x.display ();
    cout << endl << endl << endl;
    y.display ();

    return 0;
}