/*
    This file describes the SeaOtter class
*/ 

#ifndef SEA0TTER_H
#define SEA0TTER_H

#include <iostream>
#include "animal.h"

class SeaOtter : public Animal {
    private:
        //demographic variables
        static int numBabies;

        //calculation related variables
        static double purchasePrice;
        static double baseRevenueMultiplier;
        static double foodMultiplier;

    public:
        //constructor & destructor
        SeaOtter (int);
        virtual ~SeaOtter () = default;

        //calculator methods
        double calculateVetFee () override;
        double calculateRevenue (int) override;
        double calculateFoodCost () override;
        
        //getter methods
        int getNumBabies () override;
        double getPrice () override;
};

#endif