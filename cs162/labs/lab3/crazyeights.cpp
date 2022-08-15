#include <iostream>
#include <string>

#include "crazyeights.h"

using namespace std;

void nameCard (int cardCount, string & cardNumber, string & cardName) {
	cardNumber = to_string (cardCount);
	cardName = "card" + cardNumber;
	//cout << cardName << ": ";
}