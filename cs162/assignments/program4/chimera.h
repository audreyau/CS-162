/*
    This file describes the Chimera class
*/ 

#ifndef CHIMERA_H
#define CHIMERA_H

#include <iostream>
#include "event.h"

class Chimera : public Event {
    public:
        virtual ~Chimera () = default;
        void percept () override;
        int encounter () override;
        int shootTarget () override;
};

#endif