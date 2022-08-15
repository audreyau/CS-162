#include <iostream>
#include "lava.h"

using namespace std;

/*********************************************************************
** Function: percept ()
** Description: calls corresponding percepts to rooms adjacent to player's location
** Parameters: none
** Pre-Conditions: Lava class
** Post-Conditions: prints percept
*********************************************************************/
void Lava::percept () {
    cout << "• You feel an intense blast of heat ♨" << endl;
}

/*********************************************************************
** Function: encounter ()
** Description: intiates Lava event
** Parameters: none
** Pre-Conditions: Lava class
** Post-Conditions: user presses 0 to proceed
*********************************************************************/
int Lava::encounter () {
    cout << "• \u001b[7m\u001b[3mYou enter a room of lava!                        \x1b[0m" << endl;
    cout << "• \u001b[7m\u001b[3mYou fall in and die. Game over.                  \x1b[0m" << endl;

    return 4;
}

/*********************************************************************
** Function: shootTarget ()
** Description: determines if the user shot the chimera or not
** Parameters: none
** Pre-Conditions: Lava class
** Post-Conditions: returns 0; didn't hit chimera
*********************************************************************/
int Lava::shootTarget () {
    return 0;
}