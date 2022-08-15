/*
    This file describes the Deck class
*/

#ifndef DECK_H     //want header guard on all .h files
#define DECK_H

#include <iostream>
#include "card.h"

class Deck {
  private:
    Card cards[52];
    int numCards;  // Number of cards remaining in the deck.
  public:
    void addToDeck (Card, int);
    void display ();
    void shuffle ();
};

#endif