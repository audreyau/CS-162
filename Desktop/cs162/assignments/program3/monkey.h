/*
    This file describes the Monkey class
*/ 

#ifndef MONKEY_H
#define MONKEY_H

#include <iostream>
#include "animal.h"

class Monkey : public Animal {
    private:
        //demographic variables
        static int numBabies;

        //calculation related variables
        static double purchasePrice;
        static double baseRevenueMultiplier;
        static double foodMultiplier;

    public:
        //constructor & destructor
        Monkey (int);
        virtual ~Monkey () = default;
        
        //calculator methods
        double calculateVetFee () override;
        double calculateRevenue (int) override;
        double calculateFoodCost () override;

        //getter methods
        int getNumBabies () override;
        double getPrice () override;
};

#endif