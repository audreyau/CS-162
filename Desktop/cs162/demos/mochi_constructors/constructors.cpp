#include <iostream>
#include "constructors.h"

using namespace std;

void customizeMochi (string & a, int & b, int & c, double & d) {
    cout << "enter a flavor: ";
    getline (cin, a);

    cout << "enter the number of mochis: ";
    cin >> b;

    cout << "enter the number of calories: ";
    cin >> c;

    cout << "enter the price: ";
    cin >> d;

    cout << endl;
}

int main () {
    Mochi firstMochi;
    firstMochi.displayMochi();

    cout << endl << endl << endl << endl;

    Mochi secondMochi ("taro", 6, 114, 1.30);
    secondMochi.displayMochi();

    cout << endl << endl << endl << endl;

    int b = 0, c = 0;
    double d = 0;
    string a;

    customizeMochi (a, b, c, d);

    Mochi thirdMochi (a, b, c, d);
    thirdMochi.displayMochi();

    return 0;
}