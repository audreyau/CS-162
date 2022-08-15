/*
    This file describes the Zoo class
*/ 

#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include "animal.h"

class Zoo final {
    private:
        //dynamic array of Animal pointers
        Animal** roster;
        int capacity;
        int numAnimals;

        //housekeeping variables
        int numWeeks;
        static int twoYearOldAnimal;
        int attendance;
        int again;
        bool valid;

        //bank-related variables
        double bankBalance;
        int bankrupt;

    public:
        //constructor & destructor
        Zoo ();
        ~Zoo ();

        //gameplay
        void zooTycoon ();
        void announceRound ();
        void initiateRound ();
        void initiateRoundCont (double, double);
        void ageAnimals ();
        void verifyPlayablity ();

        //display table of current animals
        void countAnimals (Animal*, int[], int[], int[]);
        void countMonkeys (Animal*, int[]);
        void countMeerkats (Animal*, int[]);
        void countSeaOtters (Animal*, int[]);
        void displayTable ();
        
        //random event functions
        void randomEvent ();
        void sickAnimalEvent ();
        void cure (double, int);
        void removeAnimal (Animal*, int);
        void birthAnimalEvent ();
        void randomizeAnimal (int[]);
        void delivery (int, int);

        //shop functions
        void expandCapacity ();
        void shop ();
        void errorHandle (int&, int&);
        void verifyFunds (int&, int&, int&);
        void purchaseAnimal (int);

        //feeding functions
        void feedAnimals ();
    
        //getter methods
        std::string announceType (int);
};

#endif