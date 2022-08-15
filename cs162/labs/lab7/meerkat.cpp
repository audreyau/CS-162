#include <iostream>

#include "meerkat.h"
#include "animal.h"

using namespace std;

//initalize static variables
int Meerkat::numBabies = 3;
double Meerkat::purchasePrice = 500;
double Meerkat::baseRevenueMultiplier = 0.05;
double Meerkat::foodMultiplier = 1;

/*********************************************************************
** Function: Meerkat (int a)
** Description: custom constructor to create meerkat with a certain age
** Parameters: none
** Pre-Conditions: Meerkat class
** Post-Conditions: initializes a meerkat with age a
*********************************************************************/
Meerkat::Meerkat (int a) {
    type = 1;
    age = a;
}

Meerkat::Meerkat (string n) {
    name = n;
}

Meerkat::Meerkat () {
}

/*********************************************************************
** Function: calculateVetFee ()
** Description: calculates how much a meerkat's vet fee is (pricier for babies)
** Parameters: none
** Pre-Conditions: Meerkat class, meerkat is sick
** Post-Conditions: returns double value representing vet fee
*********************************************************************/
double Meerkat::calculateVetFee () {
    double fee = Animal::vetFeeMulitplier * Meerkat::purchasePrice;

    //if the monkey is a baby, double the vet fee
    if (age < BABYTHRESHOLD) {
        fee = fee * BABYSURCHARGE;
    }

    return fee;
}

/*********************************************************************
** Function: calculateRevenue (int)
** Description: calculates the revenue a meerkat brings in during 1 week
** Parameters: int attendance
** Pre-Conditions: Meerkat class
** Post-Conditions: returns a double value of the meerkat's revenue
*********************************************************************/
double Meerkat::calculateRevenue (int attendance) {
    //baby
    if (age < 7) { 
        return 2 * purchasePrice * baseRevenueMultiplier;
    }

    //nonbaby
    else {           
        return purchasePrice * baseRevenueMultiplier;
    }
}

/*********************************************************************
** Function: calculateFoodCost ()
** Description: calculates the cost of food for a meerkat
** Parameters: none
** Pre-Conditions: Meerkat class
** Post-Conditions: returns a double value of the cost for 1 meerkat
*********************************************************************/
double Meerkat::calculateFoodCost () {
    return Animal::baseCostofFood * Meerkat::foodMultiplier;
}

/*********************************************************************
** Function: getNumBabies ()
** Description: gets the number of babies a meerkat can have at a time
** Parameters: none
** Pre-Conditions: Meerkat class
** Post-Conditions: returns int numBabies (3)
*********************************************************************/
int Meerkat::getNumBabies () {
    return numBabies;
}

/*********************************************************************
** Function: getPrice ()
** Description: gets the cost of a meerkat 
** Parameters: none
** Pre-Conditions: Meerkat class
** Post-Conditions: returns double purchasePrice ($500)
*********************************************************************/
double Meerkat::getPrice () {
    return purchasePrice;
}

