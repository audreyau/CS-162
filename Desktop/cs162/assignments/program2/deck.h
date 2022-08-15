/*
    This file describes the Deck class
*/

#ifndef DECK_H     
#define DECK_H

#include <iostream>
#include "card.h"

class Deck {
    private:
        Card cards[52];
        int numCards;  // Number of cards remaining in the deck.
    
    public:
        //default constructor
        Deck (); 

        //acessors
        Card getTopCard () const; 
        int getNumDeck () const;  

        //mutators
        void shuffle ();  
        void removeCardFromDeck ();

        //void displayDeck () const;  //view all cards in the deck (discarded function)
};



#endif