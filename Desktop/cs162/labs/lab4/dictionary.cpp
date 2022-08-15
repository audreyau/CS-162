#include "dictionary.h"
using namespace std;

// default constructor
Dictionary::Dictionary() {
	printf("\u001b[35mDefault constructor invoked.\n");   //color it magenta
    printf("\x1b[0m"); // Reset colors to defaults 

	index = 0; // start with 0 entries
	
	// set the default number of alternate spellings to 0
	for (int i = 0; i < MAX_ENTRIES; i++) {
		entries[i].alt_spellings = NULL;
		entries[i].num_alt_spellings = 0;
	}
}

// copy constructor
Dictionary::Dictionary(const Dictionary& old_obj) {
	printf("\u001b[32mCopy constructor invoked.\n");   //color it green
    printf("\x1b[0m"); // Reset colors to defaults

	index = old_obj.index;
	
	for (int i = 0; i < MAX_ENTRIES; i++) {
		entries[i].word = old_obj.entries[i].word;
		entries[i].num_alt_spellings = old_obj.entries[i].num_alt_spellings;

		if (entries[i].num_alt_spellings > 0) {
			entries[i].alt_spellings = new string[entries[i].num_alt_spellings];
			
			for (int j = 0; j < entries[i].num_alt_spellings; j++) {
				entries[i].alt_spellings[j] = old_obj.entries[i].alt_spellings[j];
			}
		}

		else 
			entries[i].alt_spellings = NULL;
	}
}

// assignment operator overload
Dictionary& Dictionary::operator=(const Dictionary& old_obj) {
	printf("\u001b[31mAssignment operator overload invoked.\n");   //color it red
    printf("\x1b[0m"); // Reset colors to defaults

	index = old_obj.index;
	for (int i = 0; i < index; i++) {
		entries[i].word = old_obj.entries[i].word;
		entries[i].num_alt_spellings = old_obj.entries[i].num_alt_spellings;

		if (entries[i].num_alt_spellings > 0) {
			delete[] entries[i].alt_spellings;

			entries[i].alt_spellings = new string[entries[i].num_alt_spellings];
			
			for (int j = 0; j < entries[i].num_alt_spellings; j++) {
				entries[i].alt_spellings[j] = old_obj.entries[i].alt_spellings[j];
			}
		}
		else 
			entries[i].alt_spellings = NULL;
	}

	return *this;
}

// deallocate all dynamic memory
Dictionary::~Dictionary() {
	printf("\u001b[34mDestructor invoked.\n");   //color it blue
    printf("\x1b[0m"); // Reset colors to defaults

	for (int i = 0; i < MAX_ENTRIES; i++)
		delete [] entries[i].alt_spellings;
}

// add a word to the dictionary (along with its two alternate spellings)
void Dictionary::add_word(string new_word, string alt_1, string alt_2) {
	entry *tmp = &entries[index];
	tmp->word = new_word;
	tmp->num_alt_spellings = 2;
	tmp->alt_spellings = new string[tmp->num_alt_spellings];
	tmp->alt_spellings[0] = alt_1;
	tmp->alt_spellings[1] = alt_2;
	index++;
}

void Dictionary::display() {
	cout << endl << "There are " << index << " words." << endl << endl;

	for (int i = 0; i < index; i++ ) {
		cout << "Word " << i + 1 << ": " << entries[i].word << endl;
		cout << "alternate spellings:" << endl;
		for (int j = 0; j < entries[i].num_alt_spellings; j++) {
			cout << "\t" << j + 1 << ": " << entries[i].alt_spellings[j] << endl;
		}

		cout << endl;
	}
}
