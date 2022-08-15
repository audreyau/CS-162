#include <iostream>
#include "chimera.h"

using namespace std;

/*********************************************************************
** Function: percept ()
** Description: calls corresponding percepts to rooms adjacent to player's location
** Parameters: none
** Pre-Conditions: Chimera class
** Post-Conditions: prints percept
*********************************************************************/
void Chimera::percept () {
    cout << "• You smell a terrible stench ☢" << endl;
}

/*********************************************************************
** Function: encounter ()
** Description: intiates Chimera event
** Parameters: none
** Pre-Conditions: Chimera class
** Post-Conditions: user presses 0 to proceed
*********************************************************************/
int Chimera::encounter () {
    // cout << "\u001b[7m[0m";
    cout << "• \u001b[7m\u001b[3mYou stumble upon the chimera's territory!        \x1b[0m" << endl;
    cout << "• \u001b[7m\u001b[3mYou wake the chimera, and it angrily eats you.   \x1b[0m" << endl;

    return 2;
}

/*********************************************************************
** Function: shootTarget ()
** Description: determines if the user shot the chimera or not
** Parameters: none
** Pre-Conditions: Chimera class
** Post-Conditions: returns 1; hit chimera
*********************************************************************/
int Chimera::shootTarget () {
    return 1;
}