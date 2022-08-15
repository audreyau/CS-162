/*
    This file describes the Event class
*/ 

#ifndef EVENT_H
#define EVENT_H

#include <iostream>

class Event {
    public:
        virtual ~Event () = default;
        virtual void percept () = 0;
        virtual int encounter () = 0;
        virtual int shootTarget () = 0;
       
};

#endif