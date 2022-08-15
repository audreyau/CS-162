#include <iostream>
#include <iomanip>

#include "card.h"

using namespace std;

/*********************************************************************
** Function: displayCard () 
** Description: this function prints out the information (rank and suit) of a single card 
** Parameters: none
** Pre-Conditions: Card class
** Post-Conditions: prints a card's information (e.g. K of diamonds)
*********************************************************************/
void Card::displayCard () const {
	/* identify a card's rank (0 -> 12) */
	if (rank == 0)
		cout << "J of ";
	else if (rank == 1)
		cout << "A of ";
	else if (rank == 11)
		cout << "Q of ";
	else if (rank == 12)
		cout << "K of ";
	else
		cout << rank << " of ";

    /* identify a card's suit (0 -> 3) */
	if (suit == 0)
		cout << "hearts" << endl;
	else if (suit == 1)
		cout << "diamonds" << endl;
	else if (suit == 2)
		cout << "spades" << endl;
	else if (suit == 3)
		cout << "clubs" << endl;
}

/*********************************************************************
** Function: getRank ()
** Description: returns a card's rank
** Parameters: none
** Pre-Conditions: Card class
** Post-Conditions: returns an int value (0 -> 12) corresponding to the card's rank
*********************************************************************/
int Card::getRank () const { 
    return rank; 
}

/*********************************************************************
** Function: getSuit ()
** Description: returns a card's suit
** Parameters: none
** Pre-Conditions: Card class
** Post-Conditions: returns an int value (0 -> 3) corresponding to the card's suit
*********************************************************************/
int Card::getSuit () const { 
    return suit; 
}

/*********************************************************************
** Function: setContent ()
** Description: intializes a card by preparing its information
** Parameters: int a, int b
** Pre-Conditions: Card class
** Post-Conditions: rank will be intialized to a, suit will be intialized to b 
*********************************************************************/
void Card::setContent (int a, int b) {
	rank = a;
	suit = b;
}

/*********************************************************************
** Function: changeSuit ()
** Description: changes the suit of an 8 card according to the user's chosen suit
** Parameters: int wild
** Pre-Conditions: Card class, used for wild card cases
** Post-Conditions: changes the suit of a singular card to the int wild (0 -> 3)
*********************************************************************/
void Card::changeSuit (int wild) {
	suit = wild;
}