#include <iostream>
#include <cstdlib>
#include <vector>

#include "animal.h"
#include "meerkat.h"

using namespace std;

int main () {
    Meerkat mk1 ("Emma");
    Meerkat mk2 ("Liam");
    Meerkat mk3 ("Oliver");
    // mk2.displayName(); // this will print “Liam” on the console.

    vector<Meerkat> den;
    den.push_back(mk1);
    den.push_back(mk2);
    den.push_back(mk3);
    
    cout << endl; 
    cout << "[DEN]" << endl;
    for (int x = 0; x < den.size(); x++){
        cout << " • ";
        den[x].displayName();
    }

    cout << endl;
    cout << "first meerkat: ";
    den.front().displayName();

    cout << endl << "[DEN after adding Charles]" << endl;
    Meerkat mk4 ("Charles");
    den.push_back(mk4);

    for (int x = 0; x < den.size(); x++){
        cout << " • ";
        den[x].displayName();
    }

    cout << endl;

    //[]: does not check if position n is out of bounds 
    cout << "meerkat at index 2: ";
    den[2].displayName ();
    //cout << "\tusing []" << endl;
    
    //AT: checks if position n is out of bounds 
    cout << "meerkat at index 2: ";
    den.at(2).displayName ();
    //cout << "\tusing at()" << endl;

    cout << endl;

    vector<Meerkat> betterDen;
    betterDen = den;

    Meerkat mk5 ("Bob");
    betterDen.push_back(mk5);

    cout << "[BETTER DEN]" << endl;
    for (int x = 0; x < betterDen.size(); x++){
        cout << " • ";
        betterDen[x].displayName();
    }

    cout << endl;
}
