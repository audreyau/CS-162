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
        ~Rectangle () = default;

        float area () const;
        void display () override;
        void settings (float, float) override;
};

#endif