/*
	In-class demo to work on lab 3.
*/

#include <iostream>
#include <string>

#include <ctime>
#include <cstdlib>

#include "card.h"
#include "deck.h"
#include "crazyeights.h"

using namespace std;

int main() {
    srand (time (0));

    Deck myDeck;
    string cardNumber, cardName;
    int cardCount = 0;

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            nameCard (cardCount, cardNumber, cardName);
            
            Card cardName;
            cardName.setContent (i, j, cardCount);
            myDeck.addToDeck (cardName, cardCount);

            cardCount ++;
        }
    }

    //myDeck.display ();
    //cout << endl << endl << endl;

    myDeck.shuffle();
    myDeck.display();

	return 0;
}   