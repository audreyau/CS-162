/*
    This file describes the Gold class
*/ 

#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include "event.h"

class Gold : public Event {
    public:
        virtual ~Gold () = default;
        void percept () override;
        int encounter () override;
        int shootTarget () override;
       
};

#endif