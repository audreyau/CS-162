#include <iostream>
#include "gold.h"

using namespace std;

/*********************************************************************
** Function: percept ()
** Description: calls corresponding percepts to rooms adjacent to player's location
** Parameters: none
** Pre-Conditions: Gold class
** Post-Conditions: prints percept
*********************************************************************/
void Gold::percept () {
    cout << "• You notice the shine of bullion in the distance ✧" << endl;
}

/*********************************************************************
** Function: encounter ()
** Description: intiates Gold event
** Parameters: none
** Pre-Conditions: Gold class
** Post-Conditions: user presses 0 to proceed
*********************************************************************/
int Gold::encounter () {
    cout << "• \u001b[7m\u001b[3mYou stumble upon a room full of gold!            \x1b[0m" << endl;
    cout << "• \u001b[7m\u001b[3mYou carefully retrieve it.                       \x1b[0m" << endl << endl;

    string next;
    do {
        cout << "Press 0 to continue to the next round: ";
        cin >> next;
    } while (next != "0");

    return 3;
}

/*********************************************************************
** Function: shootTarget ()
** Description: determines if the user shot the chimera or not
** Parameters: none
** Pre-Conditions: Gold class
** Post-Conditions: returns 0; didn't hit chimera
*********************************************************************/
int Gold::shootTarget () {
    return 0;
}