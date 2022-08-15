#include <iostream>

#include "hand.h"
#include "card.h"

using namespace std;

/*********************************************************************
** Function: Hand () - default constructor
** Description: intializes a new Hand object
** Parameters: none
** Pre-Conditions: Hand class
** Post-Conditions: returns a Hand with 0 cards 
*********************************************************************/
Hand::Hand () {
    numCards = 0;
    cards = nullptr;
}

/*********************************************************************
** Function: Hand () - copy constructor
** Description: performs a deep copy if a new Hand object is intialized to be a copy of a pre-existing Hand; creating a new hand using data from a pre-existing one 
** Parameters: const Hand& old_obj
** Pre-Conditions: Hand class
** Post-Conditions: returns a copy of the Hand with a new dynamic array
*********************************************************************/
Hand::Hand (const Hand& old_obj) {
	numCards = old_obj.numCards;
	
	if (numCards > 0) {
		cards = new Card[numCards];
		for (int i = 0; i < numCards; i++) {
			cards[i] = old_obj.cards[i];
		}
	} 

	else {
		cards = NULL;   
	}
}

/*********************************************************************
** Function: operator= () - assignment assignment overload
** Description: performs a deep copy if a pre-existing Hand object is intialized to be a copy of a pre-existing Hand; setting already-made hand equal to pre-existing one
** Parameters: const Hand& old_obj
** Pre-Conditions: Hand class
** Post-Conditions: returns a pointer to a copy of the Hand with a new dynamic array
*********************************************************************/
Hand& Hand::operator= (const Hand& old_obj) {
	delete [] cards;
	numCards = old_obj.numCards;

	if (numCards > 0) {
		cards = new Card[numCards];
		for (int i = 0; i < numCards; i++) {
			cards[i] = old_obj.cards[i];
		}
	} 

	else {
		cards = NULL; 
	}

	return *this;
}

/*********************************************************************
** Function: ~Hand () - destructor
** Description: destroys a Hand object and deletes the dynamic memory used
** Parameters: none
** Pre-Conditions: Hand class
** Post-Conditions: frees memory
*********************************************************************/
Hand::~Hand () {
    delete[] cards;
}

/*********************************************************************
** Function: getHumanChoice ()
** Description: returns the card that the person player chose to play
** Parameters: int choice
** Pre-Conditions: Hand class
** Post-Conditions: returns a Card in a Hand
*********************************************************************/
Card Hand::getHumanChoice (int choice) const {
	Card newCard = cards[choice - 1];
	return newCard; 
}

/*********************************************************************
** Function: getCard ()
** Description: get card at index i in a hand
** Parameters: int cardNumber
** Pre-Conditions: Hand class
** Post-Conditions: returns a Card according to the int in a hand
*********************************************************************/
Card* Hand::getCard (int cardNumber) const {
    return &cards[cardNumber]; 
}

/*********************************************************************
** Function: getNumHand ()
** Description: get the number of cards in a hand
** Parameters: none
** Pre-Conditions: Hand class
** Post-Conditions: returns numCard as an int
*********************************************************************/
int Hand::getNumHand () const {
    return numCards;
}

/*********************************************************************
** Function: displayHand ()
** Description: displays all the cards in a hand
** Parameters: none
** Pre-Conditions: Hand class
** Post-Conditions: prints the card information of each card in a hand
*********************************************************************/
void Hand::displayHand () const {
    for (int i = 0; i < numCards; i++) {
        cout << i + 1 << ": ";
        cards[i].displayCard();
    }
}

/*********************************************************************
** Function: addCardToHand ()
** Description: add a card to a hand (e.g. drawing a card)
** Parameters: Card newCard
** Pre-Conditions: Hand class
** Post-Conditions: replaces cards with a dynamic array that stores one more Card
*********************************************************************/
void Hand::addCardToHand (Card newCard) {
	Card* temp = new Card[numCards + 1];

	for (int i = 0; i < numCards; i++) {
		temp[i] = cards[i];
	}

	temp[numCards] = newCard;
	delete[] cards;
	cards = temp;

	numCards++;
}

/*********************************************************************
** Function: removeCardFromHand
** Description: remove a card from a hand (e.g. playing a card)
** Parameters: int indexToGrab
** Pre-Conditions: Hand class
** Post-Conditions: replaces cards with a dynamic array that stores one less Card and shuffles Cards to replace the discarded Card
*********************************************************************/
void Hand::removeCardFromHand (int indexToGrab) {
	int tempIndex = 0;
	indexToGrab --;

	Card* temp = new Card[numCards - 1];

	for (int i = 0; i < numCards; ++i) {
		if (! (indexToGrab == i)) {
			temp[tempIndex] = cards[i];
			tempIndex ++;
		}
	}

	delete[] cards;
	cards = temp;
	numCards--;
}