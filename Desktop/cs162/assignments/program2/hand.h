/*
    This file describes the Hand class
*/ 

#ifndef HAND_H
#define HAND_H

#include "card.h"

class Hand {
    private:
        Card* cards; 
        int numCards; 

    public:
        //constructors
        Hand ();
        Hand (const Hand&);  
        Hand& operator= (const Hand&); 
        
        //destructor 
        ~Hand ();

        //accessors
        Card getHumanChoice (int) const; 
        Card* getCard (int) const; 
        int getNumHand () const;   
        void displayHand () const;
        
        //mutators
        void addCardToHand (Card);
        void removeCardFromHand (int); 
};

#endif