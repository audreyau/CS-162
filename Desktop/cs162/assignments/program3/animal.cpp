#include <iostream>
#include "animal.h"

using namespace std;

//intialize static variables
double Animal::vetFeeMulitplier = 0.2;
double Animal::baseCostofFood = 25;

/*********************************************************************
** Function: incrementAge ()
** Description: ages an animal by 1 week
** Parameters: none
** Pre-Conditions: Animal class
** Post-Conditions: returns void; age increased by 1
*********************************************************************/
void Animal::incrementAge () {
    age++;
}

/*********************************************************************
** Function: getType ()
** Description: gets an animal's type (0-monkey, 1-meerkat, 2-sea otter)
** Parameters: none
** Pre-Conditions: Animal class
** Post-Conditions: returns int corresponding to the animal's type
*********************************************************************/
int Animal::getType () {
    return type;
}

/*********************************************************************
** Function: getAge (a)
** Description: gets an animal's age in weeks
** Parameters: none
** Pre-Conditions: Animal class
** Post-Conditions: returns int corresponding to the animal's age
*********************************************************************/
int Animal::getAge () {
    return age;
}