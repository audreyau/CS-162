#include <iostream>
#include <cstdlib>

#include "monkey.h"
#include "animal.h"

using namespace std;

//initalize static variables
int Monkey::numBabies = 1;
double Monkey::purchasePrice = 12000;
double Monkey::baseRevenueMultiplier = 0.03;
double Monkey::foodMultiplier = 4;

/*********************************************************************
** Function: Monkey (int a)
** Description: custom constructor to create monkey with a certain age
** Parameters: none
** Pre-Conditions: Monkey class
** Post-Conditions: initializes a monkey with age a
*********************************************************************/
Monkey::Monkey (int a) {
    type = 0;
    age = a;
}

/*********************************************************************
** Function: calculateVetFee ()
** Description: calculates how much a monkey's vet fee is (pricier for babies)
** Parameters: none
** Pre-Conditions: Monkey class, monkey is sick
** Post-Conditions: returns double value representing vet fee
*********************************************************************/
double Monkey::calculateVetFee () {
    double fee = Animal::vetFeeMulitplier * Monkey::purchasePrice;

    //if the monkey is a baby, double the vet fee
    if (age < BABYTHRESHOLD) {
        fee = fee * BABYSURCHARGE;
    }

    return fee;
}

/*********************************************************************
** Function: calculateRevenue (int)
** Description: calculates the revenue a monkey brings in during 1 week
** Parameters: int attendance
** Pre-Conditions: Monkey class
** Post-Conditions: returns a double value of the monkey's revenue
*********************************************************************/
double Monkey::calculateRevenue (int attendance) {
    double randomValue = (rand() % 701) + 500; //random number between $500 and $1200

    //special event: attendance boom --> monkey generates additional revenue of randomValue
    if (attendance == 1) {
        if (age < 7) {
            return (2 * purchasePrice * baseRevenueMultiplier) + randomValue;
        }
        else {
            return purchasePrice * baseRevenueMultiplier + randomValue;
        }
    }

    //no boom in attendance --> monkey generates standard revenue amount
    else {
        if (age < 7)   { 
            return 2 * purchasePrice * baseRevenueMultiplier;
        }
        else {           
            return purchasePrice * baseRevenueMultiplier;
        }
    }
}

/*********************************************************************
** Function: calculateFoodCost ()
** Description: calculates the cost of food for a monkey
** Parameters: none
** Pre-Conditions: Monkey class
** Post-Conditions: returns a double value of the cost for 1 monkey
*********************************************************************/
double Monkey::calculateFoodCost () {
    return Animal::baseCostofFood * Monkey::foodMultiplier;
}

/*********************************************************************
** Function: getNumBabies ()
** Description: gets the number of babies a monkey can have at a time
** Parameters: none
** Pre-Conditions: Monkey class
** Post-Conditions: returns int numBabies (1)
*********************************************************************/
int Monkey::getNumBabies () {
    return numBabies;
}

/*********************************************************************
** Function: getPrice ()
** Description: gets the cost of a monkey 
** Parameters: none
** Pre-Conditions: Monkey class
** Post-Conditions: returns double purchasePrice ($12,000)
*********************************************************************/
double Monkey::getPrice () {
    return purchasePrice;
}

