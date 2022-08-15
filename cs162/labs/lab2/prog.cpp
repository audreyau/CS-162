#include <iostream>
#include <cstdlib>
#include <iomanip>  //set precision

#include "mult_div.h"

using namespace std;

int main (int argc, char* argv[]) {
    int again;
    cout << fixed << setprecision(2);

    if (argc != 3) {    //  argc = # of command line argument values
        cout << "You are supposed to indicate the number of rows and columns." << endl;
        return 1;
    }

    bool result = is_valid_dimensions (argv[1], argv[2]);
    if (result == false) {
        cout << "You did not imput valid dimensions. Goodbye!" << endl;
        exit (1);
    }

    int rows = atoi (argv[1]);
    int cols = atoi (argv[2]);

    do {
        mult_div_values** table = create_table (rows, cols);
        set_mult_values (table, rows, cols);
        delete_table (table, rows, cols);

        again = re_prompt (rows, cols);
    } while (again == 1);

    return 0;
}