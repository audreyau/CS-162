#include <iostream>
#include "deck.h"
#include <ctime>
#include <cstdlib>

using namespace std;

void Deck::addToDeck (Card newCard, int x) {
    cards[x] = newCard;
}

void Deck::display () {
    for (int i = 0; i < 52; i++) {
        cout << i + 1 << ": ";
        cards[i].display();
    }
}

void Deck::shuffle () {
    int m;
    Card temp;

    for (int i = 0; i < 52; i++) {
        m = rand() % 52;
        temp = cards[i];
        cards[i] = cards[m];
        cards[m] = temp;
    }
}