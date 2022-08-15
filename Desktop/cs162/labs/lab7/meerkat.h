/*
    This file describes the Meerkat class
*/ 

#ifndef MEERKAT_H
#define MEERKAT_H

#include <iostream>

#include "animal.h"

class Meerkat : public Animal {
    private:
       //demographic variables
        static int numBabies;

        //calculation related variables
        static double purchasePrice;
        static double baseRevenueMultiplier;
        static double foodMultiplier;

    public:
        //constructor & destructor
        Meerkat ();
        Meerkat (int);
        Meerkat (std::string);
        virtual ~Meerkat () = default;
        
        //calculator methods
        double calculateVetFee () override;
        double calculateRevenue (int) override;
        double calculateFoodCost () override;

        //getter methods
        int getNumBabies () override;
        double getPrice () override;
};

#endif