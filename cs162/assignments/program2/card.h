/*
    This file describes the Card class
*/ 

#ifndef CARD_H     
#define CARD_H

class Card {
    private:
        int rank;  // Should be in the range 0-12.
        int suit;  // Should be in the range 0-3.

    public:
        //acessors
        void displayCard () const;
        int getRank () const;
        int getSuit () const;

        //mutators
        void setContent (int, int);
        void changeSuit (int);
};

#endif