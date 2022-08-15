#ifndef CLASS_H
#define CLASS_H

class Matrix {
    private:
        int x;
        int y;
        float** matrix;
        
    public:

        Matrix ();
        Matrix (int x, int y);
        ~Matrix ();

        Matrix (const Matrix&); //copy constructor

        float** alloc (int rows, int cols);

        void setMatrix ();
        void display ();
        void settings (int, int);

        float** setSize (int x, int y);
        float* getMatrix ();
        float* getRow (int x);
        float* getColumn (int y);
};

#endif