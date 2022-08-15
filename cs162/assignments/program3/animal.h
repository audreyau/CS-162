/*
    This file describes the Animal class
*/ 

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

#define BABYTHRESHOLD 7
#define BABYSURCHARGE 2

class Animal {
    protected:
        //identifier variables
        int age;   
        int type;

        //calculation related variables
        static double vetFeeMulitplier;
        static double baseCostofFood;
        
    public:
        //destructor
        virtual ~Animal () = default;

        //calculator methods
        virtual double calculateVetFee () = 0;
        virtual double calculateRevenue (int) = 0;
        virtual double calculateFoodCost () = 0;
        
        //mutator methods
        void incrementAge ();
        
        //getter methods
        int getAge ();
        int getType ();
        virtual double getPrice () = 0;
        virtual int getNumBabies () = 0;    
};

#endif