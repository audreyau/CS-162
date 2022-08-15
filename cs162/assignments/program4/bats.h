/*
    This file describes the Bats class
*/ 

#ifndef BATS_H
#define BATS_H

#include <iostream>
#include "event.h"

class Bats : public Event {
    public:
        virtual ~Bats () = default;
        void percept () override;
        int encounter () override;
        int shootTarget () override;
    
};

#endif