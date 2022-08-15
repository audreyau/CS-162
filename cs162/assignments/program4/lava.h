/*
    This file describes the Lava class
*/ 

#ifndef LAVA_H
#define LAVA_H

#include <iostream>
#include "event.h"

class Lava : public Event {
    public:
        virtual ~Lava () = default;
        void percept () override;
        int encounter () override;
        int shootTarget () override;
       
};

#endif