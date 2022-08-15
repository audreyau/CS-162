#include <iostream>

#include "player.h"
#include "hand.h"

using namespace std;

/*********************************************************************
** Function: getPlayerName ()
** Description: prints the player's name
** Parameters: none
** Pre-Conditions: Player class
** Post-Conditions: prints a string name
*********************************************************************/
void Player::getPlayerName () const {
    cout << name;
}

/*********************************************************************
** Function: getHumanChoice ()
** Description: accesses the Hand class to return the card that the person player chose to play
** Parameters: int choice
** Pre-Conditions: Player class
** Post-Conditions: returns a Card in a Hand
*********************************************************************/
Card Player::getHumanChoice (int choice) {
    return hand.getHumanChoice(choice);
}

/*********************************************************************
** Function: getCard ()
** Description: accesses the Hand class to get card at index i in a hand
** Parameters: int cardNumber
** Pre-Conditions: Player class
** Post-Conditions: returns a Card according to the int in a hand
*********************************************************************/
Card* Player::getCard (int cardNumber) const {
    return hand.getCard(cardNumber); 
}

/*********************************************************************
** Function: getNumHand ()
** Description: accesses the Hand class to get the number of cards in a hand
** Parameters: none
** Pre-Conditions: Player class
** Post-Conditions: returns numCard as an int
*********************************************************************/
int Player::getNumHand () const {
    int num = hand.getNumHand();
    return num;
}

/*********************************************************************
** Function: displayHand ()
** Description: access to Hand class to display all the cards in a hand
** Parameters: none
** Pre-Conditions: Player class
** Post-Conditions: prints the card information of each card in a hand
*********************************************************************/
void Player::displayHand () const {
    hand.displayHand();
}

/*********************************************************************
** Function: setName ()
** Description: sets a player's name
** Parameters: string n
** Pre-Conditions: Player class
** Post-Conditions: sets player[0] to "human" and player[1] to "computer"
*********************************************************************/ 
void Player::setName (string n) {
    name = n;
}

/*********************************************************************
** Function: addCardToHand ()
** Description: accesses the Hand class to add a card to a hand (e.g. drawing a card)
** Parameters: Card newCard
** Pre-Conditions: Player class
** Post-Conditions: replaces cards with a dynamic array that stores one more Card
*********************************************************************/
void Player::addCardToHand (Card newCard) {
    hand.addCardToHand (newCard);
}

/*********************************************************************
** Function: removeCardFromHand
** Description: accesses the Hand class to remove a card from a hand (e.g. playing a card)
** Parameters: int indexToGrab
** Pre-Conditions: Player class
** Post-Conditions: replaces cards with a dynamic array that stores one less Card and shuffles Cards to replace the discarded Card
*********************************************************************/
void Player::removeCardFromHand (int indexToGrab) {
    hand.removeCardFromHand (indexToGrab);
}