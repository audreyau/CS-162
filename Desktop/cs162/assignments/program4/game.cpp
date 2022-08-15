#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "game.h"

using namespace std;

/*********************************************************************
** Function: Game ()
** Description: custom constructor for Game class
** Parameters: int n, char mode[]
** Pre-Conditions: Game class
** Post-Conditions: creates a new initialized game of size n and mode mode[]
*********************************************************************/
Game::Game (int n, char mode[]) {
    caveSize = n;
    cave = vector<vector<Room>>(caveSize, vector<Room>(caveSize));
    
    takeGold = 0;
    isChimeraDead = 0;
    escape = 0;

    isPlayerDead = 0;
    numArrows = 3;
    pastAction = 0;

    if (strcmp(mode, "true") == 0)
        gameMode = 1;
    else if (strcmp(mode, "false") == 0)
        gameMode = 0;
    
    intialize ();
}

/*********************************************************************
** Function: ~Game ()
** Description: destructor for Game class
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: deletes dynamic HEAP memory when a Game is destroyed
*********************************************************************/
Game::~Game () {
    for (int i = 0; i < caveSize; i++) {
        for (int j = 0; j < caveSize; j++) {
            if (cave[i][j].ev != nullptr)
                delete cave[i][j].ev;
        }
    }
}

/*********************************************************************
** Function: play ()
** Description: initiates each round until the player dies or wins
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: returns an int; if the player dies, return 1; if the player wins, return 0
*********************************************************************/
int Game::play () {
    do {
        cout << endl << "=========================================================" << endl;
        cout << endl << "\u001b[1m[NEW ROUND...]\x1b[0m" << endl;
        cout << "You have " << numArrows << " arrows remaining." << endl;
        
        displayObjectives ();
        displayPercepts ();
        displayCave ();
    
        takeUserAction ();
        if (checkArrows () == 1) break;
        checkEvent ();
        detectWinStatus ();
    } while (isPlayerDead != 1 && escape != 1);
    
    if (isPlayerDead == 1) {
        died ();
        return 1;
    }
    else {
        won ();
        return 0;
    }
}

/*********************************************************************
** Function: resetConfig ()
** Description: resets the map with the same configuration 
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: called if player loses, wants to play again with same map
*********************************************************************/
int Game::resetConfig () {
    takeGold = 0;
    if (isChimeraDead == 1) {
        isChimeraDead = 0;
        int okay = 0;
        do {
            int eventX = rand () % caveSize;
            int eventY = rand () % caveSize;

            if (cave[eventX][eventY].ev == nullptr) {
                cave[eventX][eventY].ev = new Chimera;
                chimeraRow = eventX;
                chimeraCol = eventY;
                okay = 1;
            }
        } while (okay == 0);
    }
    
    escape = 0;
    isPlayerDead = 0;
    numArrows = 3;
    pastAction = 0;

    playerRow = ropeRow;
    playerCol = ropeCol;

    return 1;
}

/*********************************************************************
** Function: initialize ()
** Description: places the events (2 bats, 1 chimera, 1 gold, 2 lava) and player/rope in random rooms
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: returns a populated cave, each room having either no event or one event
*********************************************************************/
void Game::intialize () {
    for (int i = 0; i < 7; i++) {
        int okay = 0;
        do {
            int eventX = rand () % caveSize;
            int eventY = rand () % caveSize;

            if (cave[eventX][eventY].ev == nullptr) {
                if (i == 0 || i == 1) 
                    cave[eventX][eventY].ev = new Bats;
                if (i == 2) {
                    cave[eventX][eventY].ev = new Chimera;
                    chimeraRow = eventX;
                    chimeraCol = eventY;
                }
                if (i == 3)
                    cave[eventX][eventY].ev = new Gold;
                if (i == 4 || i == 5)
                    cave[eventX][eventY].ev = new Lava;
                if (i == 6) {
                    playerRow = eventX;
                    playerCol = eventY;
                    ropeRow = eventX;
                    ropeCol = eventY;
                }
                okay = 1;
            }
        } while (okay == 0);
    }
}

/*********************************************************************
** Function: detectWinStatus ()
** Description: determines whether the user has won the game or not after each turn
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: if the user succesfully completes all tasks, escape = 1
*********************************************************************/
void Game::detectWinStatus () {
    if (playerRow == ropeRow && playerCol == ropeCol) {
        if (takeGold == 1 && isPlayerDead == 0 && isChimeraDead == 1)
            escape = 1;
    }
}

/*********************************************************************
** Function: died ()
** Description: prints message if player dies
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: prints "you died"
*********************************************************************/
void Game::died () {
    cout << endl << "=========================================================" << endl;
    cout << endl << endl << endl << endl << "\033[5m\033[1;1;1m";
    cout << "▓██   ██▓ ▒█████   █    ██    ▓█████▄  ██▓▓█████ ▓█████▄ " << endl;
    cout << " ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▒██▀ ██▌▓██▒▓█   ▀ ▒██▀ ██▌" << endl; 
    cout << "  ▒██ ██░▒██░  ██▒▓██  ▒██░   ░██   █▌▒██▒▒███   ░██   █▌" << endl;
    cout << "  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ░▓█▄   ▌░██░▒▓█  ▄ ░▓█▄   ▌" << endl;
    cout << "  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░▒████▓ ░██░░▒████▒░▒████▓ " << endl;
    cout << "   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒     ▒▒▓  ▒ ░▓  ░░ ▒░ ░ ▒▒▓  ▒ " << endl;
    cout << " ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░     ░ ▒  ▒  ▒ ░ ░ ░  ░ ░ ▒  ▒ " << endl;
    cout << " ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░     ░ ░  ░  ▒ ░   ░    ░ ░  ░ " << endl;
    cout << " ░ ░         ░ ░     ░           ░     ░     ░  ░   ░    " << endl;
    cout << " ░ ░                           ░                  ░      " << endl;
    cout << "\033[0m" << endl;
}

/*********************************************************************
** Function: won ()
** Description: prints message if player wins
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: prints "you won"
*********************************************************************/
void Game::won () {
    cout << endl << "=========================================================" << endl;
    cout << endl << endl << endl << endl << "\033[5m\033[1;1;1m";

    cout << "██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗ ██████╗ ███╗   ██╗" << endl;
    cout << "╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██╔═══██╗████╗  ██║" << endl;
    cout << " ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║   ██║██╔██╗ ██║" << endl;
    cout << "  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║   ██║██║╚██╗██║" << endl;
    cout << "   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝╚██████╔╝██║ ╚████║" << endl;
    cout << "   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═══╝" << endl;
    cout << "\033[0m" << endl;   
}

/*********************************************************************
** Function: displayObjectives ()
** Description: prints to-do list of objectives
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: prints list with completed tasks crossed-off
*********************************************************************/
void Game::displayObjectives () {
    cout << endl << "\u001b[7m Your Objectives \x1b[0m";
    cout << " ------------------------------" << endl;
    cout << "| \t\t\t\t" << "     status" << "\t" << "|" << endl;

    if (takeGold == 0)
        cout << "| 1. Retrieve the gold\t\t      " << "...\t" << "|" << endl;
    else
        cout << "| 1. Retrieve the gold\t\t      " << " ✔\t" << "|" << endl;
    
    if (isChimeraDead == 0)
        cout << "| 2. Hunt the chimera\t\t      " << "...\t" << "|" << endl;
    else
        cout << "| 2. Hunt the chimera\t\t      " << " ✔\t" << "|" << endl;

    if (escape == 0)    
        cout << "| 3. Return to the escape room\t      " << "...\t" << "|" << endl;
    else
        cout << "| 3. Return to the escape room\t      " << " ✔\t" << "|" << endl;
    cout << " -----------------------------------------------" << endl << endl;
}

/*********************************************************************
** Function: displayCave ()
** Description: prints the cave map
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: prints only the player's location if mode = 0; prints everything if mode = 1
*********************************************************************/
void Game::displayCave () {
    for (int i = 0; i < caveSize; i++) {
        displayTopBar ();
        cout << "\u001b[7m \x1b[0m" << endl;

        for (int j = 0; j < caveSize; j++)
            cout << "\u001b[7m|     \x1b[0m";
        cout << "\u001b[7m|\x1b[0m" << endl;

        for (int j = 0; j < caveSize; j++) {
            cout << "\u001b[7m|  \x1b[0m";
            if (i == playerRow && i == ropeRow && j == playerCol && j == ropeCol && gameMode == 1)
                cout << "\u001b[7m*R \x1b[0m";
            else if ((i == playerRow) && (j == playerCol)) 
                cout << "\u001b[7m*  \x1b[0m";
            else if (gameMode == 1)
                displayDebugMode (i, j);
            else 
                cout << "\u001b[7m   \x1b[0m";
        }
        cout << "\u001b[7m|\x1b[0m" << endl;

        for (int j = 0; j < caveSize; j++)
            cout << "\u001b[7m|     \x1b[0m";
        cout << "\u001b[7m|\x1b[0m" << endl;
    }
    displayTopBar ();
    cout << "\u001b[7m \x1b[0m" << endl;
}

/*********************************************************************
** Function: displayTopBar ()
** Description: prints the top bar of the cave
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: displays the top bar
*********************************************************************/
void Game::displayTopBar () {
    for (int j = 0; j < caveSize; j++)
        cout << "\u001b[7m------\x1b[0m";
}

/*********************************************************************
** Function: displayDebugMode ()
** Description: prints letters to label the special event rooms in debug mode
** Parameters: int i, int j
** Pre-Conditions: Game class
** Post-Conditions: if gamemode = 1 (debug mode), prints letters for each event
*********************************************************************/
void Game::displayDebugMode (int i, int j) {
    if (i == ropeRow && j == ropeCol) 
        cout << "\u001b[7mR  \x1b[0m";

    else if (cave[i][j].ev == nullptr)
        cout << "\u001b[7m   \x1b[0m";

    else if (dynamic_cast<Bats*>(cave[i][j].ev))
        cout << "\u001b[7mB  \x1b[0m";

    else if (dynamic_cast<Lava*>(cave[i][j].ev)) 
        cout << "\u001b[7mL  \x1b[0m";

    else if (dynamic_cast<Gold*>(cave[i][j].ev)) 
        cout << "\u001b[7mG  \x1b[0m";

    else if (dynamic_cast<Chimera*>(cave[i][j].ev)) 
        cout << "\u001b[7mC  \x1b[0m";
}

/*********************************************************************
** Function: displayPercepts ()
** Description: displays any percepts of adjacent event rooms by calling child functions
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: prints a bulleted list of percepts
*********************************************************************/
void Game::displayPercepts () {
    int perceptCount = 0;
    cout << endl << "\u001b[1m[YOUR PERCEPTS]\x1b[0m" << endl;

    displayIndividualPercepts (perceptCount);

    if (perceptCount == 0)
        cout << "(none)" << endl;

    cout << endl;
}

/*********************************************************************
** Function: displayIndividualPercepts ()
** Description: displays individual percepts of adjacent event rooms by calling child functions
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: calls each event's version of percept () if applicable
*********************************************************************/
void Game::displayIndividualPercepts (int& perceptCount) {
    if (playerRow - 1 >= 0){
        if (cave[playerRow - 1][playerCol].ev != nullptr) {
            cave[playerRow - 1][playerCol].ev -> percept ();
            perceptCount++;
        }
    }
    
    if (playerCol + 1 <= caveSize - 1){
        if (cave[playerRow][playerCol + 1].ev != nullptr) {
            cave[playerRow][playerCol + 1].ev -> percept ();
            perceptCount++;
        }
    }

    if (playerRow + 1 <= caveSize - 1){
        if (cave[playerRow + 1][playerCol].ev != nullptr) {
            cave[playerRow + 1][playerCol].ev -> percept ();
            perceptCount++;
        }
    }

    if (playerCol - 1 >= 0){
        if (cave[playerRow][playerCol - 1].ev != nullptr) {
            cave[playerRow][playerCol - 1].ev -> percept ();
            perceptCount++;
        }
    }
}

/*********************************************************************
** Function: takeUserAction ()
** Description: prompts user to move and/or shoot
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: chimera alive and still arrows, ask player to move or shoot; chimera dead, ask player to move; out of arrow, ask player to move
*********************************************************************/
void Game::takeUserAction () {
    string choice;
    cout << endl << "\u001b[1m[YOUR TURN]\x1b[0m" << endl;

    if (isChimeraDead == 1 || numArrows == 0)
        stopArrow (choice);
    
    else if (numArrows > 0) {
        cout << "► What would you like to do (0-move, 1-shoot)? ";
        cin >> choice;

        do {
            if (choice != "0" && choice != "1") {
                cout << "  \u001b[31mPlease enter a valid input: \x1b[0m";
                cin >> choice;
            }
        } while (choice != "0" && choice != "1");

        if (choice == "0") 
            move ();
        else if (choice == "1")
            shootArrow ();
    }
}

/*********************************************************************
** Function: stopArrow (string& choice)
** Description: prevents the user from shooting arrow if the chimera is dead or there are no more arrows left
** Parameters: string& choice
** Pre-Conditions: Game class
** Post-Conditions: user inputs valid input string choice to move
*********************************************************************/
void Game::stopArrow (string& choice) {
    if (isChimeraDead == 1)
        cout << "► The chimera is dead. There is no need to shoot. Press 0 to move: ";
    else if (numArrows == 0)
        cout << "► You are out of arrows. Press 0 to move: ";

    cin >> choice;

    do {
        if (choice != "0") {
            cout << "  \u001b[31mPlease enter a valid input: \x1b[0m";
            cin >> choice;
        }
    } while (choice != "0");

    move ();
}

/*********************************************************************
** Function: move ()
** Description: allows a player to move during one round
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: moves the player's position
*********************************************************************/
void Game::move () {
    string move;
    
    if (playerRow != 0)
        cout << "  ► Enter \"w\" to move north" << endl;
    if (playerCol != 0)
        cout << "  ► Enter \"a\" to move west" << endl;
    if (playerRow != (caveSize - 1))
        cout << "  ► Enter \"s\" to move south" << endl;
    if (playerCol != (caveSize - 1))
        cout << "  ► Enter \"d\" to move east" << endl;
    cout << "  ";

    cin.ignore ();
    getline (cin, move);

    int tempPlayerRow, tempPlayerCol;
    verifyMovement (tempPlayerRow, tempPlayerCol, move);

    playerRow = tempPlayerRow;
    playerCol = tempPlayerCol;

    pastAction = 1;
}

/*********************************************************************
** Function: verifyMovement ()
** Description: ensures that the player can move to the requested position
** Parameters: int& tempPlayerRow, int& tempPlayerCol, string& mov
** Pre-Conditions: Game class
** Post-Conditions: rejects false inputs, allows movement to valid rooms
*********************************************************************/
void Game::verifyMovement (int& tempPlayerRow, int& tempPlayerCol, string& move) {
    int check = 0;
    do {
        tempPlayerRow = playerRow;
        tempPlayerCol = playerCol;
        do {
            if ((move != "w" && move != "a" && move != "s" && move != "d") || check == 1) {
                cout << "  \u001b[31mPlease enter a valid input: \x1b[0m";
                getline (cin, move);
            }
        } while (move != "w" && move != "a" && move != "s" && move != "d");

        if (move == "w") 
            tempPlayerRow --;
        else if (move == "a")
            tempPlayerCol --;
        else if (move == "s")
            tempPlayerRow ++;
        else if (move == "d")
            tempPlayerCol ++;

        check = 1;
    } while (tempPlayerRow < 0 || tempPlayerRow > (caveSize - 1) || tempPlayerCol < 0 || tempPlayerCol > (caveSize - 1));
}

/*********************************************************************
** Function: shootArrow ()
** Description: initiates the player's turn in shooting an arrow
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: one less arrow, arrow shot
*********************************************************************/
void Game::shootArrow () {
    int didHit = 0;
    string shoot;
    arrowDirection (shoot);
    
    if (shoot == " w")
        shootNorth (didHit);
    else if (shoot == " a")
        shootEast (didHit);
    else if (shoot == " s") 
        shootSouth (didHit);
    else if (shoot == " d")
        shootWest (didHit);

    if (didHit == 1) 
        hitChimera ();
    else 
        missedChimera ();

    numArrows--;
    pastAction = 2;
}

/*********************************************************************
** Function: arrowDirection ()
** Description: prompts user for valid input for direction to shoot arrow
** Parameters: string& shoot
** Pre-Conditions: Game class
** Post-Conditions: string; reprompts if user puts invalid input; if not, returns string with direction to shoot
*********************************************************************/
void Game::arrowDirection (string& shoot) {
    cout << "  ► Enter \" w\" to shoot north" << endl;
    cout << "  ► Enter \" a\" to shoot west" << endl;
    cout << "  ► Enter \" s\" to shoot south" << endl;
    cout << "  ► Enter \" d\" to shoot east" << endl;
    cout << "  ";

    cin.ignore ();
    getline (cin, shoot);

    do {
        if (shoot != " w" && shoot != " a" && shoot != " s" && shoot != " d") {
            cout << "  \u001b[31mPlease enter a valid input: \x1b[0m";
            getline (cin, shoot);
        }
    } while (shoot != " w" && shoot != " a" && shoot != " s" && shoot != " d");    
}

/*********************************************************************
** Function: shootNorth
** Description: shoots an arrow north
** Parameters: int& didHit
** Pre-Conditions: Game class
** Post-Conditions: if hit chimera, didHit = 1; if not, didHit = 0
*********************************************************************/
void Game::shootNorth (int& didHit) {
    if (playerRow - 1 >= 0)
        if (cave[playerRow - 1][playerCol].ev != nullptr) {
            didHit += cave[playerRow - 1][playerCol].ev -> shootTarget ();
    }
    
    if (playerRow - 2 >= 0) {
        if (cave[playerRow - 2][playerCol].ev != nullptr) 
            didHit += cave[playerRow - 2][playerCol].ev -> shootTarget ();
    }
    
    if (playerRow - 3 >= 0) {
        if (cave[playerRow - 3][playerCol].ev != nullptr) 
            didHit += cave[playerRow - 3][playerCol].ev -> shootTarget ();
    }
}

/*********************************************************************
** Function: shootEast
** Description: shoots an arrow east
** Parameters: int& didHit
** Pre-Conditions: Game class
** Post-Conditions: if hit chimera, didHit = 1; if not, didHit = 0
*********************************************************************/
void Game::shootEast (int& didHit) {
    if (playerCol - 1 >= 0) { 
        if (cave[playerRow][playerCol - 1].ev != nullptr)
            didHit += cave[playerRow][playerCol - 1].ev -> shootTarget ();
    }

    if (playerCol - 2 >= 0) {
        if (cave[playerRow][playerCol - 2].ev != nullptr)
            didHit += cave[playerRow][playerCol - 2].ev -> shootTarget ();
    }

    if (playerCol - 3 >= 0) {
        if (cave[playerRow][playerCol - 3].ev != nullptr)
            didHit += cave[playerRow][playerCol - 3].ev -> shootTarget ();
    }
}

/*********************************************************************
** Function: shootSouth
** Description: shoots an arrow south
** Parameters: int& didHit
** Pre-Conditions: Game class
** Post-Conditions: if hit chimera, didHit = 1; if not, didHit = 0
*********************************************************************/
void Game::shootSouth (int& didHit) {
    if (playerRow + 1 <= caveSize - 1) {
        if (cave[playerRow + 1][playerCol].ev != nullptr) 
            didHit += cave[playerRow + 1][playerCol].ev -> shootTarget ();
    }

    if (playerRow + 2 <= caveSize - 1) {
        if (cave[playerRow + 2][playerCol].ev != nullptr) 
            didHit += cave[playerRow + 2][playerCol].ev -> shootTarget ();
    }
    
    if (playerRow + 3 <= caveSize - 1) {
        if (cave[playerRow + 3][playerCol].ev != nullptr) 
            didHit += cave[playerRow + 3][playerCol].ev -> shootTarget ();
    }
}

/*********************************************************************
** Function: shootWest
** Description: shoots an arrow west
** Parameters: int& didHit
** Pre-Conditions: Game class
** Post-Conditions: if hit chimera, didHit = 1; if not, didHit = 0
*********************************************************************/
void Game::shootWest (int& didHit) {
    if (playerCol + 1 <= caveSize - 1) {
        if (cave[playerRow][playerCol + 1].ev != nullptr) 
            didHit += cave[playerRow][playerCol + 1].ev -> shootTarget ();
    }
    
    if (playerCol + 2 <= caveSize - 1) {
        if (cave[playerRow][playerCol + 2].ev != nullptr) 
            didHit += cave[playerRow][playerCol + 2].ev -> shootTarget ();
    }
    
    if (playerCol + 3 <= caveSize - 1) {
        if (cave[playerRow][playerCol + 3].ev != nullptr) 
            didHit += cave[playerRow][playerCol + 3].ev -> shootTarget ();   
    }
}

/*********************************************************************
** Function: hitChimera ()
** Description: removes chimera from cave when it's killed
** Parameters: none
** Pre-Conditions: Game class, user misses chimera
** Post-Conditions: chimera is replaced with nullptr
*********************************************************************/
void Game::hitChimera () {
    cout << endl << "• \u001b[7m\u001b[3mThe arrow enters the Chimera's room.             \x1b[0m" << endl;
    cout << "• \u001b[7m\u001b[3mIt pierces the monster's heart, killing it.      \x1b[0m" << endl << endl;
    isChimeraDead = 1;
    delete cave[chimeraRow][chimeraCol].ev;
    cave[chimeraRow][chimeraCol].ev = nullptr;

    string next;
    do {
        cout << "Press 0 to continue to the next round: ";
        cin >> next;
    } while (next != "0");
}

/*********************************************************************
** Function: missedChimera ()
** Description: prompts chimera movement when arrow is shot but doesn't hit chimera
** Parameters: none
** Pre-Conditions: Game class, user misses chimera
** Post-Conditions: chimera is awakened by arrow and moves to random empty room
*********************************************************************/
void Game::missedChimera () {
    cout << endl << "• \u001b[7m\u001b[3mYou do not successfully shoot the Chimera.       \x1b[0m" << endl;
    cout << "• \u001b[7m\u001b[3mWoken by the arrow, it flees to a random room.   \x1b[0m" << endl << endl;

    int eventX, eventY, okay = 0;
    do {
        eventX = rand () % caveSize;
        eventY = rand () % caveSize;

        if ((cave[eventX][eventY].ev == nullptr) && (eventX != playerRow && eventY != playerCol) && (eventX != ropeRow && eventY != ropeCol)) {
            cave[eventX][eventY].ev = cave[chimeraRow][chimeraCol].ev;
            cave[chimeraRow][chimeraCol].ev = nullptr;
            okay = 1;
        }
        
    } while (okay == 0);

    chimeraRow = eventX;
    chimeraCol = eventY;

    string next;
    do {
        cout << "Press 0 to continue to the next round: ";
        cin >> next;
    } while (next != "0");
}

/*********************************************************************
** Function: checkArrows ()
** Description: checks to see if user is out of arrows and chimera is alive
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: int; if user failed to kill chimera but ran out of arrows, return 1
*********************************************************************/
int Game::checkArrows () {
    if (numArrows == 0 && isChimeraDead == 0) {
        isPlayerDead = 1;
        cout << endl << "• \u001b[7m\u001b[3mYou're out of arrows to defend yourself.         \x1b[0m" << endl;
        cout << "• \u001b[7m\u001b[3mThe chimera finds you and eats you. Game over.   \x1b[0m" << endl;
        return 1;
    }
    else 
        return 0;
}

/*********************************************************************
** Function: checkEvent ()
** Description: when a player moves to a new room, intiates the event if any
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: calls event's encounter function and makes corresponding changes to member variables
*********************************************************************/
void Game::checkEvent () {
    int eventID;
    cout << endl;
    if (cave[playerRow][playerCol].ev != nullptr) {
        eventID = cave[playerRow][playerCol].ev -> encounter ();

        if (eventID == 1) 
            superBats ();
        else if (eventID == 2)
            isPlayerDead = 1;
        else if (eventID == 3) {
            takeGold = 1;
            delete cave[playerRow][playerCol].ev;
            cave[playerRow][playerCol].ev = nullptr;
        }
        else if (eventID == 4)
            isPlayerDead = 1;
    }

    else if (pastAction == 1) {
        cout << "• \u001b[7m\u001b[3mYou move to an empty room.                       \x1b[0m" << endl;
        cout << "• \u001b[7m\u001b[3mNothing happens.                                 \x1b[0m" << endl << endl;

        string next;
        do {
            cout << "Press 0 to continue to the next round: ";
            cin >> next;
        } while (next != "0");
    }
}

/*********************************************************************
** Function: superBats ()
** Description: allows the super bats to take the player to a random empty room
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: player moves to random empty room, bats return to their original room
*********************************************************************/
void Game::superBats () {
    int okay = 0;

    do {
        int tempPlayerRow = rand () % caveSize;
        int tempPlayerCol = rand () % caveSize;

        if ((cave[tempPlayerRow][tempPlayerCol].ev == nullptr) && (tempPlayerRow != playerRow && tempPlayerCol != playerCol) && (tempPlayerRow != ropeRow && tempPlayerCol != ropeCol)) {
            playerRow = tempPlayerRow;
            playerCol = tempPlayerCol;
            okay = 1;
        }

    } while (okay == 0);
}