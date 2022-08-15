#include <iostream>

#include "card.h"

using namespace std;

//a = rank, b = suit
void Card::setContent (int a, int b, int cardCount) {
	rank = a;
	suit = b;
	number = cardCount + 1;
}

void Card::display () {
	if (rank == 0)
		cout << "jack";
	else if (rank == 1)
		cout << "ace";
	else if (rank == 11)
		cout << "queen";
	else if (rank == 12)
		cout << "king";
	else
		cout << rank;
	
	cout << " of ";
	
	switch (suit) {
		case 0: 
			cout << "hearts";
			break;
		case 1:
			cout << "diamonds";
			break;
		case 2:
			cout << "spades";
			break;
		case 3:
			cout << "clubs";
	}

	cout << " (card #" << number << ")" << endl;
}