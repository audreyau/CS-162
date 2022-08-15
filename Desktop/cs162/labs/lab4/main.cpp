#include "dictionary.h"
#include <iostream>
using namespace std;

/*
	Test the functionality of the dictionary
*/
int main() {

	Dictionary src, book2;
	src.add_word("island", "ilande", "ylonde");
	
	Dictionary book1 = src;
	book1.add_word("february", "feverere", "feverell");

	book2 = book1;
	book2.add_word("jeopardy", "yeopardie", "ieoperde");
	
	cout << "-----------------------------" << endl << endl;
	
	cout << "[CONTENTS OF SRC: ]" << endl;
	src.display();

	cout << "-----------------------------" << endl << endl;
	
	cout << "[CONTENTS OF BOOK1: ]" << endl;
	book1.display();

	cout << "-----------------------------" << endl << endl;

	cout << "[CONTENTS OF BOOK2: ]" << endl;
	book2.display();

	return 0;
}
