/*
    This file describes the Player class
*/ 

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "hand.h"

class Player {
    private:
        Hand hand;
        std::string name;

    public:
        //accessors
        void getPlayerName () const;
        Card getHumanChoice (int);
        Card* getCard (int) const;
        int getNumHand () const;
        void displayHand () const;  

        //mutators
        void setName (std::string); 
        void addCardToHand (Card);
        void removeCardFromHand (int); 
};

#endif