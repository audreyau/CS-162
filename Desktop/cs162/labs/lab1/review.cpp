#include <iostream>
#include <string>

using namespace std;

//prototypes
void get_string(string *);
string convert_to_tilde(string *);
int search_and_replace(char, string, string &);

int main () {
    string string1; //this string stores our original sentence!
    string* address_String; //this string stores the address of string1!
    address_String = &string1; 

    get_string (address_String);
    string tilde = convert_to_tilde (address_String);
    cout << "The tilde version of your string is: " << tilde << endl;

    char letter; //this char will be the letter the user searches for and replaces

    cout << "\nPlease tell me the char that you would like to locate and replace: ";
    cin >> letter;

    int count = search_and_replace(letter, string1, tilde);
    cout << "The new version of your string is: " << tilde << endl;
    cout << "I located " << count << " \'" << letter << "\' characters!" << endl;

    return 0;
}

/******************************************************
** Function: get_string
** Description:
** 	This function accepts a pointer to a string and replaces the contents of that string. The user’s input will be stored in the string.
** Parameters
** 	address_String → A pointer to the C++ string (String1) that will be used as the basis for the copy. This string will not be modified.
** Pre-Conditions: None
** Post-Conditions: None (void function)
******************************************************/

void get_string (string *x) {                   //the '*x' means will point to a string (string1) and modify it directly
    cout << "\nPlease enter a string: ";          //therefore *x is a string with an address to another string (X IS AN ADDRESS)
    getline (cin, *x);
}

/******************************************************
** Function: convert_to_tilde
** Description:
** 	This function accepts a pointer to a string and creates a copy. The copy will be identical to the original string (which was passed by pointer) except for one major change... in the copied string, all non-space characters will be replaced by a tilde (~).
** Parameters
** 	address_String → A pointer to the C++ string (String1) that will be used as the basis for the copy. This string will not be modified.
** Pre-Conditions: None
** Post-Conditions:
** 	Returns a newly created string that is exactly the same length as the string parameter that was passed via pointer. However, each non-space character in this new string will be replaced by a tilde.
******************************************************/

string convert_to_tilde(string *x) {
    string copy = *x;                           //this string will be returned as the tilde version of the original string
    for (int i = 0; i < copy.length(); ++i) { 
		if (! (copy[i] == 32))                  //in the copy, if the character is not a space, replace with '~'
            copy[i] = '~';
	}
    return copy;
}

/******************************************************
** Function: search_and_replace
** Description:
** 	This function accepts a char, a string (the original user input string), and a reference to a string (the new version that contains tilde symbols). The function will search though the original string and look for the requested char. Any time that character is discovered in the original string, the tilde-version of the string will have the tilde replaced by that requested character. 
** Parameters
** 	letter → A char that the user inputs. This character is being searched and replaced.
**	string1 → The original string the user inputed.
** 	tilde → The modified string in which all non-space characters are replaced with tildes (‘~’). This is referenced so it’s modified directly despite not returning a string value.
** Pre-Conditions: None
** Post-Conditions:
** 	Returns an int a, which represents the number of times the character was replaced.
******************************************************/

int search_and_replace(char x, string y, string &z) {
    int a = 0;                                  //this int will store the number of instances of char x there are
    for (int i = 0; i < y.length(); ++i) {      //if the original string has a char that is equal to char x, replace the char in the tilde string with that char
        if (y[i] == x) {
            z[i] = x;
            a = a + 1;                          //add 1 to int a to store the count
        }
    }
    return a;
}