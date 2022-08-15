/*
    This file describes the Game class
*/ 

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "deck.h"
#include "player.h"

class Game {
    private:
        Deck cards;
        Player players[2];
        Card targetCard;
        int winner;

    public:
        //constructor and game initiation
        Game ();
        void prepareGame ();
        void playGame ();
        
        //narrate gameplay
        void announceRound ();
        void announceWinner ();

        //accessors
        void displayHand ();
        void displayTargetCard () const; 

        //mutators for human (player 0)
        void playHuman ();
        void promptHumanForCard ();
        void humanAction (int, Card);
        void humanPlayWild (Card);
        void humanDrawCard (Card);

        //mutators for computer (player 1)
        void playComputer ();
        void computerPlayCard (int&);
        void computerDrawCard ();

        //verification and error handling
        bool possibleCards (Card*) const;
        bool checkCard (Card) const;
        void errorHandle (int, Card, int);
};

#endif