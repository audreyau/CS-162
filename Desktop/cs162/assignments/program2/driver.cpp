/******************************************************
** Program: driver.cpp
** Author: Audrey Au
** Date: 07/08/2022
** Description: This is the main/driver file for program2, the Crazy Eights program. In this assignment, I developed a game of Crazy Eights that can be played with the user (human player) against a computer player. This card uses a deck of 52 and deals 7 cards initially to both players. The game keeps going until there's a winner or the deck runs out of cards. There is a target card to match. The human will go first, then the computer. During a player's turn, if they have a card in their hand that matches the target card's suit or rank or they have a wild card (any card with rank 8), they can play the card. If they do not have a card, they must draw from the deck until they get a card they can play. The aim of the game is to get rid of all cards. AT the end, the program announces the winner and asks if the user would liek to play again.
** Extra credit: indicate to the user which cards in their hand are valid options to be played (I labeled these cards yellow!)
** Input: no command line arguments; user inputs int choice (which card they want to play), int wild (which suit they want next), and int again (if they want to play again)
** Output: a fun game of Crazy Eights (complete with instructions, narrations, and guides)!
******************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "game.h"

using namespace std;

void announceInstructions ();

int main () {
    srand(time(0));
    int again = 1;

    announceInstructions();

    while (again == 1) {
        Game crazyEights;
        crazyEights.playGame();

        cout << "Would you like to play again? (0 - no, 1 - yes)" << endl;
        do {
            cout << "► Type here: ";
            cin >> again;
        } while (!(again == 0 || again == 1));

    }

    cout << endl;
    return 0;
}

/*********************************************************************
** Function: announceInstructions ()
** Description: states the instructions prior to the game starting
** Parameters: none
** Pre-Conditions: start program
** Post-Conditions: prints the instructions for the game and when user presses enter, game starts
*********************************************************************/ 
void announceInstructions () {
    cout << endl << "\n\n\n\n\n\n------------------------------------------------" << endl << endl;
    cout << "WELCOME TO THE CRAZY EIGHTS SIMULATION!" << endl << endl;
    cout << "A few housekeeping notes..." << endl;
    
    cout << "• We will print the number of cards in the deck, your hand, and the computer's hand during each round." << endl;
    cout << "• We will display cards that you can play in " << "\u001b[33;1myellow\x1b[0m" << " (this is the extra credit)." << endl;
    cout << "• Cards you cannot play will be darkened and colored in " << "\u001b[30;1mgray\x1b[0m" << endl;
    cout << "• The card you must respond to will be " << "\u001b[7mshaded\x1b[0m" << endl;

    cout << endl << "With that, hit enter to begin!" << endl;
    cin.ignore();
}