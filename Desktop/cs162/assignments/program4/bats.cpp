#include <iostream>
#include "bats.h"

using namespace std;

/*********************************************************************
** Function: percept ()
** Description: calls corresponding percepts to rooms adjacent to player's location
** Parameters: none
** Pre-Conditions: Bats class
** Post-Conditions: prints percept
*********************************************************************/
void Bats::percept () {
    cout << "• You hear wings flapping ♪" << endl;
}

/*********************************************************************
** Function: encounter ()
** Description: intiates Bats event
** Parameters: none
** Pre-Conditions: Bats class
** Post-Conditions: user presses 0 to proceed
*********************************************************************/
int Bats::encounter () {
    cout << "• \u001b[7m\u001b[3mYou enter a room of super bats!                  \x1b[0m" << endl;
    cout << "• \u001b[7m\u001b[3mThey grab you and take you to a random room.     \x1b[0m" << endl << endl;

    string next;
    do {
        cout << "Press 0 to continue to the next round: ";
        cin >> next;
    } while (next != "0");

    return 1;
}

/*********************************************************************
** Function: shootTarget ()
** Description: determines if the user shot the chimera or not
** Parameters: none
** Pre-Conditions: Bat class
** Post-Conditions: returns 0; didn't hit chimera
*********************************************************************/
int Bats::shootTarget () {
    return 0;
}