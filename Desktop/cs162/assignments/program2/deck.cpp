#include <iostream>
#include <ctime>
#include <cstdlib>

#include "deck.h"
#include "card.h"

using namespace std;

/*********************************************************************
** Function: Deck () - default constructor
** Description: intializes a shuffled Deck of 52 unique cards
** Parameters: none
** Pre-Conditions: Deck class
** Post-Conditions: created Deck object is a shuffled, accurate Deck of unique cards from the 13 ranks and 4 suits
*********************************************************************/
Deck::Deck () {
    numCards = 52;
    int cardNumber = 0;

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            cards[cardNumber].setContent (i, j);
            cardNumber ++;
        }
    }

    shuffle ();
}

/*********************************************************************
** Function: getTopCard ()
** Description: gets the card at the top of the deck (used for drawing a card)
** Parameters: none
** Pre-Conditions: Deck class
** Post-Conditions: returns the card at index 0 in the deck
*********************************************************************/
Card Deck::getTopCard () const {
    return cards[0];
}

/*********************************************************************
** Function: getNumDeck ()
** Description: get the number of cards remaining in a deck
** Parameters: none
** Pre-Conditions: Deck class
** Post-Conditions: return the member variable int numCards from a deck
*********************************************************************/
int Deck::getNumDeck () const {
    return numCards;
}

/*********************************************************************
** Function: shuffle ()
** Description: shuffles a deck of 52 cards
** Parameters: none
** Pre-Conditions: Deck class
** Post-Conditions: mutates the object to randomize the order of the cards
*********************************************************************/
void Deck::shuffle () {
    int randomCard;
    Card temp;

    for (int i = 0; i < 52; i++) {
        randomCard = rand() % 52;       //select a random card from the deck
        temp = cards[i];  

        cards[i] = cards[randomCard];   //switch card at i with random card from deck
        cards[randomCard] = temp;
    }
}

/*********************************************************************
** Function: removeCardFromDeck ()
** Description: shrinks the deck by 1
** Parameters: none
** Pre-Conditions: Deck class
** Post-Conditions: decreases numCards by 1 and shuffles all cards up by 1 to replace lost card
*********************************************************************/
void Deck::removeCardFromDeck () {
    numCards --;

	for (int i = 0; i < numCards; i++) {
		cards[i] = cards[i + 1];            //replace card at index 0
	}
}

/*
this function was discarded because it's not necessary for the gameplay. 
this function was used to monitor card activity and ensure verifiability
    void Deck::displayDeck () const {
        cout << "Displayed deck: " << endl;
        for (int i = 0; i < numCards; i++) {
            cout << i + 1 << ": \t";
            cards[i].displayCard();
        }
    }
*/