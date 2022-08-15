/*
	Animal Class
*/
#ifndef POO_H
#define POO_H

#include <iostream>
#include "animal.h"

class Poo {
    private:
        int pee = 56;
        int poop = 26;

    public: 
        friend class Animal;
        
};

#endif
