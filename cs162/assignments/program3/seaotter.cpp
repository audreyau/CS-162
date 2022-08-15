#include <iostream>

#include "seaotter.h"
#include "animal.h"

using namespace std;

//initalize static variables
int SeaOtter::numBabies = 1;
double SeaOtter::purchasePrice = 4000;
double SeaOtter::baseRevenueMultiplier = 0.05;
double SeaOtter::foodMultiplier = 2;

/*********************************************************************
** Function: SeaOtter (int a)
** Description: custom constructor to create sea otter with a certain age
** Parameters: none
** Pre-Conditions: SeaOtter class
** Post-Conditions: initializes a sea otter with age a
*********************************************************************/
SeaOtter::SeaOtter (int a) {
    type = 2;
    age = a;
}

/*********************************************************************
** Function: calculateVetFee ()
** Description: calculates how much a sea otter's vet fee is (pricier for babies)
** Parameters: none
** Pre-Conditions: SeaOtter class, SeaOtter is sick
** Post-Conditions: returns double value representing vet fee
*********************************************************************/
double SeaOtter::calculateVetFee () {
    double fee = Animal::vetFeeMulitplier * SeaOtter::purchasePrice;

    //baby costs extra
    if (age < BABYTHRESHOLD) {
        fee = fee * BABYSURCHARGE;
    }

    return fee;
}

/*********************************************************************
** Function: calculateRevenue (int)
** Description: calculates the revenue a sea otter brings in during 1 week
** Parameters: int attendance
** Pre-Conditions: SeaOtter class
** Post-Conditions: returns a double value of the sea otter's revenue
*********************************************************************/
double SeaOtter::calculateRevenue (int attendance) {
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
** Description: calculates the cost of food for a sea otter
** Parameters: none
** Pre-Conditions: SeaOtter class
** Post-Conditions: returns a double value of the cost for 1 sea otter
*********************************************************************/
double SeaOtter::calculateFoodCost () {
    return Animal::baseCostofFood * SeaOtter::foodMultiplier;
}

/*********************************************************************
** Function: getNumBabies ()
** Description: gets the number of babies a sea otter can have at a time
** Parameters: none
** Pre-Conditions: SeaOtter class
** Post-Conditions: returns int numBabies (1)
*********************************************************************/
int SeaOtter::getNumBabies () {
    return numBabies;
}

/*********************************************************************
** Function: getPrice ()
** Description: gets the cost of a sea otter 
** Parameters: none
** Pre-Conditions: SeaOtter class
** Post-Conditions: returns double purchasePrice ($4,000)
*********************************************************************/
double SeaOtter::getPrice () {
    return purchasePrice;
}

