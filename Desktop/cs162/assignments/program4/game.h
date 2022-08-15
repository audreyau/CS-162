/*
    This file describes the Game class
*/ 

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

#include "room.h"
#include "event.h"
#include "bats.h"
#include "chimera.h"
#include "lava.h"
#include "gold.h"

class Game {
    public: 
        //constructor & destructor  
        Game (int, char[]);
        ~Game ();
        
        //play functions
        int play ();
        int resetConfig ();
    
    private:
        //game settings
        int caveSize;
        int gameMode;
        std::vector<std::vector<Room>> cave;
        int numArrows;
        int pastAction;

        //objective statuses
        int isChimeraDead; 
        int takeGold;
        int isPlayerDead;
        int escape;

        //locations
        int playerRow, playerCol;
        int ropeRow, ropeCol;
        int chimeraRow, chimeraCol;
        
        //housekeeping functions
        void intialize (); 
        void detectWinStatus ();
        void died ();
        void won ();
        
        //display functions
        void displayObjectives ();
        void displayCave ();
        void displayTopBar ();
        void displayDebugMode (int, int);
        void displayPercepts ();
        void displayIndividualPercepts (int&);
        
        //user action functions
        void takeUserAction ();
        void stopArrow (std::string&);

        //move functions
        void move ();
        void verifyMovement (int&, int&, std::string&);

        //shoot functions
        void shootArrow ();
        void arrowDirection (std::string&);
        void shootNorth (int&);
        void shootEast (int&);
        void shootSouth (int&);
        void shootWest (int&);
        void hitChimera ();
        void missedChimera ();
        int checkArrows ();
    
        //event functions
        void checkEvent ();
        void superBats ();
};

#endif