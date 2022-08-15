#ifndef CIRCLE_H     
#define CIRCLE_H

#include <cmath>
#include "shape.h"

class Circle : public Shape {
    private:
        float radius;

    public:
        Circle ();
        Circle (float);

        float area ();
        void displayCircle ();
};

#endif