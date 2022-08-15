#ifndef RECTANGLE_H     
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
    private:
        float width;
        float height;

    public:
        Rectangle ();
        Rectangle (float, float);

        float area ();
        void displayRectangle ();
};

#endif