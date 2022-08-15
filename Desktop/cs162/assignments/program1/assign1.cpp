/******************************************************
** Program Filename: assign1.cpp
** Author: Audrey Au
** Date: 07/03/22
** Description: Upon compiling this program alongside a .txt file of high school football data (in a specific organization!), the user can choose among four different options. The options are explained/printed by the program. The options are (1) display each school's earliest year on file, (2) list the best year for each school, (3) sort schools by their win ratios), and (4) quit. If the user chooses options 1-3, the program will print the results in an easy-to-read format. If the user does not select 4, the program will run again.
** Input: sample_1.txt (or a .txt variation; declarated through command line arguments), option (unsigned int)
** Output: info.uniqueArray[i].finalized.year (year w/ highest total points for school i), info.uniqueArray[i].finalized.numPoints (highest gross points for school i), duplicate_School[i].winRatio (winRatio for school i), explanation of the 4 options and execution of them
******************************************************/

#include <iostream>
#include <fstream>  //file input/output
#include <cstdlib>  //exit command
#include <iomanip>  //set precision

using namespace std;

/************************************ STRUCTS ************************************************************************************************/

struct Match {
    unsigned int year;
    unsigned int homeScore;
    string opponentName;
    unsigned int opponentScore;
};

struct School {
    string name;
    string moniker;
    string city;
    double winRatio;
    unsigned int numMatches; 
    Match* array;
};

struct BestYear {
    unsigned int year;
    unsigned int numPoints;
    string opponents;
};

struct UniqueArray {  
    string name;
    BestYear* array;
    BestYear finalized;
    int numYears;
    unsigned int highestYear;
};

struct AthleticInfo {
    School* array;
    UniqueArray* uniqueArray;
	int numSchools;
};

/************************************ REQUIRED PROTOTYPES ************************************************************************************************/

Match* create_match_array (int);
School* create_school_array (int);
void load_match_data (Match*, int, ifstream &);
void load_school_data (School*, int, ifstream &);

/************************************ REQUIRED FUNCTIONS ************************************************************************************************/

/*********************************************************************
** Function: Match* create_match_array (int numMatches)
** Description: This function dynamically allocates HEAP memory for an array of Match structs. The number of Match structs is based off of int numMatches.
** Parameters: int numMatches (file input from the .txt file)
** Pre-Conditions: Since this function is embedded in process_file(), the program must run process_file() in order to execute this function. Additionally, the array of School structs must exist since these arrays are subsections within.
** Post-Conditions: returns the pointer to a new dynamically allocated array, which allocates memory according to the number of matches per school in the txt file
*********************************************************************/ 
Match* create_match_array (int numMatches) {
    Match* ptr = new Match[numMatches];
    return ptr;
}

/*********************************************************************
** Function: School* create_school_array (int numSchools)
** Description: This function dynamically allocates HEAP memory for an array of School structs. The number of School structs is based off of int numSchools.
** Parameters: int numSchools (file input from the .txt file)
** Pre-Conditions: Since this function is embedded in process_file(), the program must run process_file() in order to execute this function.
** Post-Conditions: returns the pointer to a new dynamically allocated array, which allocates memory according to the number of schools in the txt file
*********************************************************************/ 
School* create_school_array (int numSchools) {
    School* ptr = new School[numSchools];   //  allocate HEAP memory for new array of schools
    return ptr;     //  ptr = pointer to a School or an array of Schools 
}

/*********************************************************************
** Function: void load_match_data (Match* array, int numMatches, ifstream& fin)
** Description: This function iterates through the input .txt file to collect the match data per school and store it into the various arrays of Match structs.
** Parameters: Match* array, int numMatches, ifstream& fin 
** Pre-Conditions: This function is embedded in the load_school_data() function, so that function must be run first.
** Post-Conditions: populates the arrays created in create_match_array() with data from the .txt file
*********************************************************************/ 
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

/*********************************************************************
** Function: void load_school_data (School* myarray, int numSchools, ifstream& fin)
** Description: This function iterates through the input .txt file to collect the school data and store it into the array of School structs.
** Parameters: School* myarray, int numSchools, ifstream& fin
** Pre-Conditions: This function is embedded in the process_file() function, so that function must be run first.
** Post-Conditions: populates the arrays created in create_school_array() with data from the .txt file
*********************************************************************/ 
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

/************************************ CUSTOM FUNCTIONS ************************************************************************************************/

/*********************************************************************
** Function: int prompt_user (int option) 
** Description: This function provides the descriptions of the 4 options and prompts the user to choose an option. If the user provides an invalid input, it reprompts the user.
** Parameters: int option
** Pre-Conditions: none
** Post-Conditions: option has a valid value of 1, 2, 3, or 4
*********************************************************************/
int prompt_user (int option) {
    cout << "\n------------------------------------\n" << endl;
    cout << "\nWhich option would you like to choose?" << endl;
    cout << "► Display each school's earliest year on file (Press 1)" << endl;
    cout << "► List the best year (by points acquired) for each school (Press 2)" << endl;
    cout << "► Sort schools by overall historical performance (win ratio) (Press 3)" << endl;
    cout << "► Quit (Press 4)" << endl;
    cout << "\nType your answer here: ";
    cin >> option;

    if (option <= 0 || option >= 5) {    //error handle int values out of range
        do {
            cout << "Please choose from the 4 options: ";
            cin >> option;
        } while (option <= 0 || option >= 5);
    }

    if (!(option == 4)) {
        cout << endl << "-----\n\nYour result..." << endl;
    }

    return option;
}

/*********************************************************************
** Function: UniqueArray* create_unique_array (int numSchools)
** Description: This function dynamically allocates HEAP memory for an array of UniqueArray structs. The number of UniqueArray structs is based off of int numSchools.
** Parameters: int numSchools (file input from the .txt file)
** Pre-Conditions: Since this function is embedded in option_two(), option == 2.
** Post-Conditions: returns the pointer to a new dynamically allocated array, which allocates memory according to the number of schools in the txt file
*********************************************************************/ 
UniqueArray* create_unique_array (int numSchools) {
    UniqueArray* ptr = new UniqueArray[numSchools];
    return ptr;
}

/*********************************************************************
** Function: School* duplicate_school_array (School* array, int numSchools)
** Description: This function duplicates each array of School structs so that this duplicate can be used in other functions to sort by winRatio without mixing up the original data.
** Parameters: School* myarray, int numSchools
** Pre-Conditions: option == 3
** Post-Conditions: returns a duplicated array of School structs (duplicates info.array)
*********************************************************************/ 
School* duplicate_school_array (School* array, int numSchools) {
    School* duplicate_School = new School[numSchools];   

    for (int i = 0; i < numSchools; i++)
        duplicate_School[i] = array[i];

    return duplicate_School;
}

/*********************************************************************
** Function: void process_file (char* filename, AthleticInfo& ai)
** Description: This function uses ifstream to read the user's provided .txt file and store the contents by values according to the specific sample structure. It then stores them into arrays using previously explained functions.
** Parameters: char* filename, AthleticInfo& ai
** Pre-Conditions: The user must provide a .txt file in the command line argument upon running the code since this function reads and processes that file.
** Post-Conditions: The file is processed, stored into various dynamically allocated arrays, and is no longer needed.
*********************************************************************/ 
void process_file (char* filename, AthleticInfo& ai) { 
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

/*********************************************************************
** Function: void calculate_winRatio (AthleticInfo& ai, int numSchools) 
** Description: This function calculates the winRatio (percent of time a specific school wins) and stores it into the various School struct arrays.
** Parameters: AthleticInfo& ai, int numSchools
** Pre-Conditions: previous functions must be run first to store the information into arrays and manipulate that info via calculations
** Post-Conditions: calculates the winRatio and stores it into each array of School structs
*********************************************************************/ 
void calculate_winRatio (AthleticInfo& ai, int numSchools) { 
    for (int i = 0; i < numSchools; i++) {
        double winRatio;
        double winCount = 0;

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

/*********************************************************************
** Function: void find_highest_year (UniqueArray* unique_array, int index, School* array, int numMatches)
** Description: This function finds a school's number of unique match years and highest year by iterating through an array of Matches structs for a specific school. It scans through the years. If there is a new year, it adds one to num_years and sets it as the new highest year.
** Parameters: UniqueArray* unique_array, int index, School* array, int numMatches
** Pre-Conditions: option == 2
** Post-Conditions: gives values to num_years and highest_year within the array of UniqueArray structs
*********************************************************************/ 
void find_highest_year (UniqueArray* unique_array, int index, School* array, int numMatches) {
    int num_years = 0;
    unsigned int highest_year = 0;
    
    for (int j = 0; j < numMatches; j++) {
        if (array[index].array[j].year > highest_year) { 
            highest_year = array[index].array[j].year;
            num_years ++;
        }   
    }

    unique_array[index].numYears = num_years;
    unique_array[index].highestYear = highest_year;
}

/*********************************************************************
** Function: void populate_unique_array (UniqueArray* special, int index, School* array, int numMatches)
** Description: This function creates a dynamic array of BestYear structs within the array of UniqueYear structs. Thus it first populates all values with 0 instead of garbage and finds the best year in terms of gross points for a specific school.
** Parameters: UniqueArray* special, int index, School* array, int numMatches
** Pre-Conditions: option == 2
** Post-Conditions: gives values to numPoints and year within the BestYears struct in the array of UniqueArray structs (essentially finds the best year lol)
*********************************************************************/ 
void populate_unique_array (UniqueArray* special, int index, School* array, int numMatches) {
    BestYear* ptr = new BestYear[special[index].numYears];
    special[index].array = ptr;
    
    int length = -1;
    int track = 0;

    for (int i = 0; i < special[index].numYears; i++) {
        special[index].array[i].year = 0;
        special[index].array[i].numPoints = 0;
    }

    for (int i = 0; i < numMatches; i++) {
        if (array[index].array[i].year == track) {   
            special[index].array[length].numPoints += array[index].array[i].homeScore;
        }
        else if (array[index].array[i].year > track) { 
            track = array[index].array[i].year;
            length = length + 1;

            special[index].array[length].year = array[index].array[i].year;
            special[index].array[length].numPoints += array[index].array[i].homeScore;
        }
    }
}

/*********************************************************************
** Function: void highest_points (UniqueArray* special, int index, School* array, int numSchools)
** Description: This function finds the best year in terms of gross points for a specific school.
** Parameters: UniqueArray* special, int index, School* array, int numSchools
** Pre-Conditions: option == 2
** Post-Conditions: sorts through the UniqueArray to locate the data for each school's best year in terms of gross points.
*********************************************************************/ 
void highest_points (UniqueArray* special, int index, School* array, int numSchools) {
    int high_year = 0;
    int high_point = 0;
    
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

/*********************************************************************
** Function: void list_opponents (UniqueArray* special, int index, School* array, int numSchools)
** Description: This function stores the opponents a school defeated in their best year via a string.
** Parameters: UniqueArray* special, int index, School* array, int numSchools
** Pre-Conditions: option == 2
** Post-Conditions: stores a list of defeated opponents for a school's best year
*********************************************************************/
void list_opponents (UniqueArray* special, int index, School* array, int numSchools) {
    string myString;

    for (int i = 0; i < array[index].numMatches; i++) {
        if ((array[index].array[i].year == special[index].finalized.year) && (array[index].array[i].homeScore > array[index].array[i].opponentScore)) {
            if (myString == "") {
                myString = myString + "\n  ◦ " + array[index].array[i].opponentName;
            }
            else if (!(myString == "")) {
                myString = myString + "\n  ◦ " + array[index].array[i].opponentName;
            }
        }
    }

    special[index].finalized.opponents = myString;
}

/*********************************************************************
** Function: if_no_wins (UniqueArray* special, int numSchools) 
** Description: This function alters the output if a school never won a game in their best year.
** Parameters: UniqueArray* special, int numSchools
** Pre-Conditions: option == 2
** Post-Conditions: if the school never won in their best year, don't print opponents defeated; if they did win, list opponents defeated
*********************************************************************/
void if_no_wins (UniqueArray* special, int numSchools) {
    for (int i = 0; i < numSchools; i++) {
        cout << "• " << special[i].name << ": " << special[i].finalized.numPoints << " points in " << special[i].finalized.year << endl;
        
        if (!(special[i].finalized.opponents == "")) {
            cout << "  Opponents Defeated: " << special[i].finalized.opponents << endl; 
        }
        else {
            cout << "  No Opponents Defeated" << endl;
        }

        cout << endl;
    }
}

/*********************************************************************
** Function: void alphabetize (UniqueArray* special, int numSchools) 
** Description: This function alphabetizes the result outputs for option 2.
** Parameters: UniqueArray* special, int numSchools
** Pre-Conditions: option == 2
** Post-Conditions: outputs each school and it's best year and the total points for that year in alphabetical order
*********************************************************************/
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

    if_no_wins(special, numSchools);
}

/************************************ OPTION-ORIENTED CUSTOM FUNCTIONS ************************************************************************************************/

/*********************************************************************
** Function: void option_one (AthleticInfo& ai, int numSchools)
** Description: This function lists all the schools, their mascot, the year they were founded, and their city.
** Parameters: AthleticInfo& ai, int numSchools
** Pre-Conditions: option == 1
** Post-Conditions: outputs the school's information along with the year of it's earliest recorded match
*********************************************************************/
void option_one (AthleticInfo& ai, int numSchools) {   
    for (int i = 0; i < numSchools; i++) {
        int x = 2023;   //  will store lowest number/earliest year
        for (int j = 0; j < ai.array[i].numMatches; j++) {          
            if (ai.array[i].array[j].year < x)
                x = ai.array[i].array[j].year;    
        }

        cout << "• " << ai.array[i].name << ", \"" << ai.array[i].moniker << "\", Team founded: " << x << ", City: " << ai.array[i].city << endl;
    }
}

/*********************************************************************
** Function: void option_two (AthleticInfo& ai, School* array, int numSchools)
** Description: This function will list, in alphabetical order, the schools, the year of their most gross points, and the total points for that year.
** Parameters: AthleticInfo& ai, School* array, int numSchools
** Pre-Conditions: option == 2
** Post-Conditions: outputs in alphabetical order the schools and their best year
*********************************************************************/
void option_two (AthleticInfo& ai, School* array, int numSchools) {
    ai.uniqueArray = create_unique_array(ai.numSchools);

    for (int i = 0; i < numSchools; i++) {
        ai.uniqueArray[i].name = ai.array[i].name;   
    }

    for (int i = 0; i < numSchools; i++) {
        find_highest_year (ai.uniqueArray, i, array, array[i].numMatches);
        populate_unique_array (ai.uniqueArray, i, array, array[i].numMatches);
        highest_points (ai.uniqueArray, i, array, numSchools);
        list_opponents (ai.uniqueArray, i, array, numSchools);
    }

    alphabetize (ai.uniqueArray, numSchools);
}

/*********************************************************************
** Function: void option_three (School* array, int numSchools) 
** Description: This function lists the schools and their winRatio (percent of time they won matches) from largest to smallest winRatio.
** Parameters: School* array, int numSchools
** Pre-Conditions: option == 3
** Post-Conditions: outputs schools and their winRatio in the correct order
*********************************************************************/
void option_three (School* array, int numSchools) {
    School* duplicate_School = duplicate_school_array (array, numSchools);
 
    for (int i = 0; i < numSchools; i++) {  //sorts by win ratio
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

/*********************************************************************
** Function: void option_four (AthleticInfo& ai, School* myarray, int numSchools) 
** Description: This function deletes the HEAP memory for the array of School structs and the array of Match structs within the array of School structs.
** Parameters: AthleticInfo& ai, School* myarray, int numSchools
** Pre-Conditions: declaration of dynamic arrays
** Post-Conditions: cleared memory and no valgrind errors :)
*********************************************************************/
void option_four (AthleticInfo& ai, School* myarray, int numSchools) {
    for (int i = 0; i < numSchools; i++) {
        delete[] myarray[i].array;
    }

    delete[] myarray;
    exit(1);
}

/*********************************************************************
** Function: void all_options (AthleticInfo& ai, int option, int numSchools)
** Description: This function is the hub for faciltating all the various 4 options. 
** Parameters: AthleticInfo& ai, int option, int numSchools
** Pre-Conditions: user declares a valid option
** Post-Conditions: the user's selected option will prompt the respective functions
*********************************************************************/
void all_options (AthleticInfo& ai, int option, int numSchools) {
    if (option == 1) 
        option_one(ai, numSchools);

    else if (option == 2) {
        option_two(ai, ai.array, numSchools);
        for (int i = 0; i < numSchools; i++) {
            delete[] ai.uniqueArray[i].array;
        }
        delete[] ai.uniqueArray;
    }   

    else if (option == 3) {
        calculate_winRatio(ai, numSchools);
        option_three(ai.array, numSchools);
    }
        
    else if (option == 4) 
        option_four(ai, ai.array,numSchools);
}

/************************************ MAIN FUNCTION ************************************************************************************************/

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
        option = prompt_user(option);
        all_options (info, option, info.numSchools);
    } while (!(option == 4));

    return 0;
}