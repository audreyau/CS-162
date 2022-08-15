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
        ~Circle () = default;

        float area () const;
        void display () override;
        void settings (float, float) override;

};

#endif