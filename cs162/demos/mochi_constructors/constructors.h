/*
	This file describes the MOchi class.
*/
#ifndef MOCHI_H
#define MOCHI_H

#include <iostream>

using namespace std;

class Mochi {
    private:
        string flavor;
        int numPieces;
        int numCalories;
        double price;

        static int totalCount;

    public:
        //infinte constructors
        Mochi();
        Mochi (string, int, int, double);

        //only one destructor
        ~Mochi();

        void displayMochi();
};
#endif
