#include <iostream>
#include <cstdlib>

#include "mult_div.h"

using namespace std;

bool is_valid_dimensions (char* rowString, char* colString) {
    int rows = atoi (rowString);
    int cols = atoi (colString);

    if (rows < 1 || cols < 1) {
        return false;
    }
    return true;
}

mult_div_values** create_table (int m, int n) {
    mult_div_values** table = new mult_div_values* [m];

    for (int i = 0; i < m; i++) {
        table[i] = new mult_div_values [n];

        for (int j = 0; j < n; j++) {
            if (i == 0) {
                table[0][j].mult = j + 1;
                table[0][j].div = 1.00 / (j + 1);
            }

            if (j == 0) {
                table[i][0].div = i + 1;
                table[i][0].mult = i + 1;
            }
        }
    }

    return table;
}

void set_mult_values (mult_div_values** table, int m, int n) {
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (!(i == 0) && !(j == 0))  
                table[i][j].mult = table[0][j].mult * table[i][0].mult;
        }
    }  

    set_div_values (table, m, n);
    print_table (table, m, n);
}

void set_div_values (mult_div_values** table, int m, int n) {
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (!(i == 0) && !(j == 0)) 
                table[i][j].div = table[0][j].div * table[i][0].div;
        }
    }  
}

void print_table (mult_div_values** table, int m, int n) {
    cout << "Multiplication Table:" << endl;
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if (j == n - 1)
                cout << table[i][j].mult << endl;
            else 
                cout << table[i][j].mult << "\t";
        }
    }

    cout << "Division Table:" << endl;
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if (j == n - 1) 
                cout << table[i][j].div << endl;
            else 
                cout << table[i][j].div << "\t";
        }
    }
}

void delete_table (mult_div_values** table, int m, int n) {
    for (int i = 0; i < m; i++)
        delete[] table[i];

    delete[] table;
}

int re_prompt (int & m, int & n) {
    int x;

    do {
        cout << endl << "Would you like to see a different size matrix (0-no, 1-yes)?" << endl;
        cin >> x;
    } while (!(x == 0 || x == 1));

    if (x == 1) {
        do {
            cout << "How many rows? ";
            cin >> m;
        } while (! (m > 0));

        do {
            cout << "How many columns? ";
            cin >> n;
        } while (! (n > 0));
    }

    return x;
}