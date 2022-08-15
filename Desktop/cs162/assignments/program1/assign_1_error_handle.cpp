#include <iostream>
#include <fstream>  //file input/output
#include <cstdlib>  //exit command
#include <iomanip>  //set precision
#include <string>

using namespace std;

struct Match {
    unsigned int year;
    unsigned int homeScore;
    string opponentName;
    unsigned int opponentScore;
};

struct BestYear {
    unsigned int year;
    unsigned int numPoints;
};

struct School {
    string name;
    string moniker;
    string city;
    double winRatio;
    unsigned int numMatches; 
    Match* array;
};

struct UniqueArray {
    string name;    //school name
    BestYear* array;
    BestYear finalized;
    unsigned int numYears;
    unsigned int highestYear;
};

struct AthleticInfo {
    School* array;
    UniqueArray* uniqueArray;
	unsigned int numSchools;
};

/************************************************************************************************************************************/

School* create_school_array (int numSchools) {
    School* ptr = new School[numSchools];   //  allocate HEAP memory for new array of schools
    return ptr;     //  ptr = pointer to a School or an array of Schools 
}

UniqueArray* create_unique_array (int numSchools) {
    UniqueArray* ptr = new UniqueArray[numSchools];

    return ptr;
}

Match* create_match_array (int numMatches) {
    Match* ptr = new Match[numMatches];
    return ptr;
}

void load_match_data (Match* array, int numMatches, ifstream& fin) {
    for (int i = 0; i < numMatches; i++) {  // i = 0 is the first school aka Subrosa HS
        fin >> array[i].year;
        fin.ignore();
        fin >> array[i].homeScore;
        fin.ignore();
        getline(fin, array[i].opponentName, ';');
        fin >> array[i].opponentScore;
        fin.ignore();
    }
}

void load_school_data (School* myarray, int numSchools, ifstream& fin) {
    for (int i = 0; i < numSchools; i++) {  // i = 0 is the first school aka Subrosa HS
        getline (fin, myarray[i].name, ';');
        getline (fin, myarray[i].moniker, ';');
        getline (fin, myarray[i].city, ';');

        fin >> myarray[i].numMatches;
        fin.ignore();

        myarray[i].array = create_match_array(myarray[i].numMatches);
        load_match_data(myarray[i].array, myarray[i].numMatches, fin);
    }
}

/************************************************************************************************************************************/

void process_file (char* filename, AthleticInfo& ai) {      //only func processing file
    ifstream fin;
    fin.open(filename);
    
    if (!fin.is_open()) {
        cout << "Failed to open file." << endl;
        exit(1);
    }

    fin >> ai.numSchools;
	fin.ignore();
	
	ai.array = create_school_array(ai.numSchools);
	load_school_data(ai.array, ai.numSchools, fin);

    ofstream fout;
    fout.close();
}

void calculate_winRatio (AthleticInfo& ai, int numSchools) {  //FINISHED!!!
    for (int i = 0; i < numSchools; i++) {
        double winRatio, winCount = 0;

        //num_matches
        for (int j = 0; j < ai.array[i].numMatches; j++) {          
            if (ai.array[i].array[j].homeScore > ai.array[i].array[j].opponentScore) {
                winCount = winCount + 1;  
            }
        }
        winRatio = winCount / ai.array[i].numMatches  ;        
        ai.array[i].winRatio = winRatio;
    }
}

School* duplicate_school_array (School* array, int numSchools) {
    School* duplicate_School = new School[numSchools];   // duplicate original array

    for (int i = 0; i < numSchools; i++)
        duplicate_School[i] = array[i];

    return duplicate_School;
}

/************************************************************************************************************************************/

void find_highest_year (UniqueArray* unique_array, int index, School* array, int numMatches) {
    int num_years = 0;
    unsigned int highest_year = 0;
    
    for (int j = 0; j < numMatches; j++) {
        if (array[index].array[j].year == highest_year) {   //found
            //ai.uniqueArray[i].array.
            //add points
        }
        else if (array[index].array[j].year > highest_year) {    //not found
            //populate array
            highest_year = array[index].array[j].year;
            num_years ++;
        }   
    }

    unique_array[index].numYears = num_years;
    unique_array[index].highestYear = highest_year;
}

//for one school at a time
void populate_unique_array (UniqueArray* special, int index, School* array, int numMatches) {
    BestYear* ptr = new BestYear[special[index].numYears];
    special[index].array = ptr;
    
    int length = -1, track = 0;

    for (int i = 0; i < special[index].numYears; i++) {
        special[index].array[i].year = 0;
        special[index].array[i].numPoints = 0;
    }

    for (int i = 0; i < numMatches; i++) {
        if (array[index].array[i].year == track) {   //already exists 
            special[index].array[length].numPoints += array[index].array[i].homeScore;
        }

        else if (array[index].array[i].year > track) { //doesn't exist
            track = array[index].array[i].year;
            length = length + 1;

            special[index].array[length].year = array[index].array[i].year;
            special[index].array[length].numPoints += array[index].array[i].homeScore;
        }
    }
}

//one school!
void highest_points (UniqueArray* special, int index, School* array, int numSchools) {
    int high_year = 0, high_point = 0;
    
    for (int i = 0; i < special[index].numYears; i++) {
        for (int j = 0; j < special[index].numYears; j++) {
            if (special[index].array[i].numPoints > special[index].array[j].numPoints) {
                if (special[index].array[i].numPoints > high_year) {
                    high_point = special[index].array[i].numPoints;
                    high_year = special[index].array[i].year;
                }
            }
            else if (special[index].array[i].numPoints < special[index].array[j].numPoints) {
                if (special[index].array[i].numPoints < high_year) {
                    high_point = special[index].array[j].numPoints;
                    high_year = special[index].array[j].year;
                }
            }
        }
    }

    special[index].finalized.numPoints = high_point;
    special[index].finalized.year = high_year;
}


void alphabetize (UniqueArray* special, int numSchools) {
    string temp;
    BestYear temp_final;
    for (int i = 0; i < numSchools; i++) {
        for (int j = i + 1; j < numSchools; j++){
            if (special[i].name > special[j].name) {
                temp = special[i].name;
                special[i].name = special[j].name;
                special[j].name = temp; 

                temp_final = special[i].finalized;
                special[i].finalized = special[j].finalized;
                special[j].finalized = temp_final; 
            }
        }
    }

    for (int i = 0; i < numSchools; i++) {
        cout << "• " << special[i].name << ": " << special[i].finalized.numPoints << " points in " << special[i].finalized.year << endl;
    }
}

/************************************************************************************************************************************/

void option_one (AthleticInfo& ai, int numSchools) {    //FINISHED!!
    //need to find first game for a school
    for (int i = 0; i < numSchools; i++) {

        int x = 2022;   //  will store lowest number/earliest year
        for (int j = 0; j < ai.array[i].numMatches; j++) {           // AUDREY FIGURE OUT HOW TO GET NUMMATCHES
            if (ai.array[i].array[j].year < x)
                x = ai.array[i].array[j].year;    
        }
        cout << "• " << ai.array[i].name << ", \"" << ai.array[i].moniker << "\", Team founded: " << x << ", City: " << ai.array[i].city << endl;
    }
}

void option_two (AthleticInfo& ai, School* array, int numSchools) {
    ai.uniqueArray = create_unique_array(ai.numSchools);
    for (int i = 0; i < numSchools; i++) {
        ai.uniqueArray[i].name = ai.array[i].name;   
    }

    for (int i = 0; i < numSchools; i++) {
        find_highest_year (ai.uniqueArray, i, array, array[i].numMatches);
        populate_unique_array (ai.uniqueArray, i, array, array[i].numMatches);
        highest_points (ai.uniqueArray, i, array, numSchools);
    }

    alphabetize (ai.uniqueArray, numSchools);
}

//sort winratio output from largest to smallest
void option_three (School* array, int numSchools) {
    School* duplicate_School = duplicate_school_array (array, numSchools);
 
    // sort by winRatio
    for (int i = 0; i < numSchools; i++) {
        for (int j = i + 1; j < numSchools; j++) {
            if (duplicate_School[i].winRatio < duplicate_School[j].winRatio) {
                School temp;
                temp = duplicate_School[i];
                duplicate_School[i] = duplicate_School[j];
                duplicate_School[j] = temp;
            }
        }
    }

    for (int i = 0; i < numSchools; i++)
       cout << "• " << duplicate_School[i].name << ": " << duplicate_School[i].winRatio << endl;

    delete[] duplicate_School;
}

void option_four (AthleticInfo& ai, School* myarray, int numSchools) {
    for (int i = 0; i < numSchools; i++) {
        delete[] myarray[i].array;
        //delete[] ai.uniqueArray[i].array;
    }
    delete[] myarray;
    //delete[] ai.uniqueArray;

    exit(1);
}

/************************************************************************************************************************************/

int main (int argc, char* argv[]) {
    AthleticInfo info;
    unsigned int option;
    cout << fixed << setprecision(3);
	
    if (argc != 2) {    //  argc = # of command line argument values
		cout << "You are supposed to provide a command line argument with the input filename." << endl;
		return 1;
	}

	process_file(argv[1], info);    //  argv[1] = text file name

    do {
        cout << "\n------------------------------------\n" << endl;
        cout << "\nWhich option would you like to choose?" << endl;
        cout << "► Display each school's earliest year on file (Press 1)" << endl;
        cout << "► List the best year (by points acquired) for each school (Press 2)" << endl;
        cout << "► Sort schools by overall historical performance (win ratio) (Press 3)" << endl;
        cout << "► Quit (Press 4)" << endl;
        cout << "\nType your answer here: ";
        cin >> option;
        
        if (cin.fail()) {   //error handle non int values
            do {
                cin >> option;
                cin.clear(); 
                cin.ignore(512, '\n');
                cout << "Please enter a valid input: ";
                cin >> option;
            } while (cin.fail());
        }

        if ((option <= 0 || option >= 5)||(option == 0)) {    //error handle int values out of range
             do {
                cout << "Please choose from the 4 options: ";
                cin >> option;
                if (cin.fail()) {   //error handle non int values
                    do {
                        cin >> option;
                        cin.clear(); 
                        cin.ignore(512, '\n');
                        cout << "Please enter a valid input: ";
                        cin >> option;
                    } while (cin.fail());
                }
            } while ((option <= 0 || option >= 5)||(option == 0));
        }

        if (!(option == 4)) {
            cout << endl;
            cout << "-----\n\nYour result..." << endl;
        }
        
        if (option == 1) 
            option_one(info, info.numSchools);

        else if (option == 2) {
            option_two(info, info.array, info.numSchools);
            for (int i = 0; i < info.numSchools; i++) {
                delete[] info.uniqueArray[i].array;
            }
            delete[] info.uniqueArray;
        }   
        
        else if (option == 3) {
            calculate_winRatio(info, info.numSchools);
            option_three(info.array, info.numSchools);
        }
            
        else if (option == 4) 
            option_four(info, info.array, info.numSchools);
        
    } while (!(option == 4));

    return 0;
}