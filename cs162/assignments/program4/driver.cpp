/******************************************************
** Program: driver.cpp - Hunt the Chimera
** Author: Audrey Au
** Date: 08/05/22
** Description: This game is called Hunt the Chimera, a parody of the popular 1973 text-based adventure game “Hunt the Wumpus”. Before beginning the game, the user will indicate how large the map should be by adding a number during the command line argument (thus, the cave will always be a square). Within this map, there will always be 1 room of gold, 2 rooms of bats, 2 rooms of lava, 1 room with the chimera, and 1 starting/escape room. This will be randomized during the map/cave initialization. The player will navigate and move around the map using the typical WASD keys used in other computer games. The user will receive clues called “precepts” when in a room adjacent to a unique room (e.g. with gold, lava, bats…). The game is initialized with 3 arrows. The user can shoot them in any adjacent direction for up to three rooms. If the player hits the chimera successfully, the chimera dies. If the chimera is not hit, it moves to a random room. Anytime the player uses an arrow, the number of arrows decrements. In order to win the game, the user will need to survive, collect the bag of gold, kill the chimera, and escape. If the player wins, the game quits. However, if the player loses, the program should prompt the user if they want to play again and, if yes, with what configurations.
** Input: string choice (move/shoot); string move (W, A, S, D); string shoot ( W,  A,  S,  D); string again (play again yes/no); string config (same/random); char* argv[1, 2] (char tempCaveSize[128]/int caveSize, int gameMode)
** Output: prints error messages & reprompts for inputs, display objectives, displays cave map (2 modes: debug, regular), displays percepts, displays num arrows if applicable, displays possible user actions, narrates events, asks questions
** DOES PLAYER NEED TO KILL CHIMERA TO WIN???? -> Yes.
******************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>

#include "game.h"

using namespace std;

//prototypes
void errorHandle (int&, char[]);
void playerLoses (string&, string&, int&, int&, Game&);

/************   MAIN FUNCTION   *********************************************************************************************************************/

int main (int argc, char* argv[]) {
    srand (time (0));
    
    if (argc != 3) {
        cout << "You are supposed to indicate the cave size and game mode. Goodbye!" << endl;
        return 1;
    }   

    int myLoop, sameConfig;
    int caveSize = atoi (argv[1]);
    errorHandle (caveSize, argv[2]);
    
    do {
        myLoop = 0;
        Game HTC (caveSize, argv[2]);

        do {
            string again, config;
            myLoop = 0;
            sameConfig = 0;
            int deathStatus = HTC.play ();
            
            if (deathStatus == 1) 
                playerLoses (again, config, myLoop, sameConfig, HTC);
    
        } while (sameConfig == 1);
    } while (myLoop == 1);

    return 0;
}

/************   OTHER FUNCTIONS   *********************************************************************************************************************/

/*********************************************************************
** Function: errorHandle ()
** Description: error handles incorrect command line argument inputs
** Parameters: int& caveSize, char argv[]
** Pre-Conditions: user printed 3 command line arguments
** Post-Conditions: sets caveSize and gameMode
*********************************************************************/
void errorHandle (int& caveSize, char argv[]) {
    char tempCaveSize[128];

    if ((caveSize < 4) || (!((strcmp(argv, "true") == 0) || (strcmp(argv, "false") == 0)))) {
        cout << endl << "\u001b[1m[Error]\x1b[0m" << endl;
        if (caveSize < 4) {
            do {
                cout << "► You did not enter valid dimensions. The cave must be 4 or more units large." << endl;
                cout << "  \u001b[31mPlease try again: \x1b[0m";
                cin >> tempCaveSize;
                caveSize = atoi (tempCaveSize);
            } while (caveSize < 4);
        }

        if (!((strcmp(argv, "true") == 0) || (strcmp(argv, "false") == 0))) {
            do {
                cout << "► You did not enter a valid game mode. Type \"true\" for debugger mode or \"false\" for regular mode." << endl;
                cout << "  \u001b[31mPlease try again: \x1b[0m";
                cin >> argv;
            } while (!((strcmp(argv, "true") == 0) || (strcmp(argv, "false") == 0)));
        }
    }
}

/*********************************************************************
** Function: playerLoses ()
** Description: if player loses, asks if they want to play again and if yes what configs
** Parameters: string& again, string& config, int& myLoop, int& sameConfig, Game& HTC
** Pre-Conditions: player loses
** Post-Conditions: either quits or sets up a new game
*********************************************************************/
void playerLoses (string& again, string& config, int& myLoop, int& sameConfig, Game& HTC) {
    do {
        cout << "► Would you like to try again (0-no, 1-yes)? ";
        cin >> again;
    } while (again != "0" && again != "1");
    
    if (again == "1") {
        myLoop = 1;
        do {
            cout << "► Would you like the same cave setup or a new random setup (0-same, 1-random)? ";
            cin >> config;
        } while (config != "0" && config != "1");
    }

    if (config == "0") 
        sameConfig = HTC.resetConfig ();
}
