#include <iostream>

#include "game.h"
#include "player.h"
#include "hand.h"
#include "deck.h"
#include "card.h"

using namespace std;

/*********************************************************************
** Function: Game () - default constructor
** Description: creates a new Game crazyEights
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: sets up game, intializes players, deals hands, prepares first targetCard
*********************************************************************/ 
Game::Game () {
    winner = -1;

    //intialize 2 hands of 7
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            players[i].addCardToHand(cards.getTopCard());
            cards.removeCardFromDeck();
        }
    }

    targetCard = cards.getTopCard();
    cards.removeCardFromDeck();
}

/*********************************************************************
** Function: preareGame ()
** Description: sets up player info
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: user can input manual names for players
*********************************************************************/ 
void Game::prepareGame () {
    string str;
    cout << endl << "------------------------------------------------" << endl << endl;
    cout << "SETTING UP GAME..." << endl;

    cout << "Enter your name: ";
    getline (cin, str);
    players[0].setName(str);

    players[1].setName("computer");
}

/*********************************************************************
** Function: playGame ()
** Description: facilitates game until there's a winner or the deck runs out of cards
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: will iterate thorugh rounds and will declare and announce a winner
*********************************************************************/ 
void Game::playGame () {
    prepareGame ();

    do {
        announceRound ();
        playHuman();
        if (winner == -1) {
            cout << endl << "---------" << endl << endl;
            playComputer();
        }
    } while (cards.getNumDeck() > 0 && winner == -1);

    announceWinner ();
}

/*********************************************************************
** Function: announceRound ()
** Description: declares the state of the cards before each round
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: outputs number of cards in deck and hands and the targetCard
*********************************************************************/ 
void Game::announceRound () {
    int numDeck = cards.getNumDeck();
    int yourDeck = players[0].getNumHand();
    int compDeck = players[1].getNumHand();

    cout << endl << "------------------------------------------------" << endl << endl;
    cout << "Number of cards left in deck: " << numDeck << endl;
    cout << "Number of cards left in your hand: " << yourDeck << endl;
    cout << "Number of cards left in opponent's hand: " << compDeck << endl << endl;

    displayHand();
    displayTargetCard();

    cout << "\u001b[1m[YOUR TURN]\x1b[0m" << endl;
}

/*********************************************************************
** Function: announceWinner ()
** Description: determines who's the winner and announces it
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: prints appropriate response
*********************************************************************/ 
void Game::announceWinner () {

    /* if run out of cards in deck, player with least amount of cards in deck wins */
    if (winner == -1) {
        if (players[0].getNumHand() < players[1].getNumHand())
            winner = 0;
        else    
            winner = 1;
    }

    /* human won */
    if (winner == 0) {         
        cout << endl << "------------------------------------------------" << endl << endl;
        cout << "\u001b[1m[YOU WON]! Congratulations, ";
        players[0].getPlayerName();
        cout << "!\x1b[0m" << endl << endl;
    }

    /* computer won */
    else if (winner == 1) {     
        cout << endl << "------------------------------------------------" << endl << endl;
        cout << "\u001b[1m[YOU LOST]! The ";
        players[1].getPlayerName();
        cout << " won. Better luck next time, ";
        players[0].getPlayerName();
        cout << ".\x1b[0m" << endl << endl;
    }
}

/*********************************************************************
** Function: displayHand ()
** Description: displays the human player's hand and possible cards they can play
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: prints all cards in hand; yellow = possible, gray = impossible
*********************************************************************/ 
void Game::displayHand () {
    printf("\u001b[4m");
    cout << "Your hand: " << endl;
    printf("\x1b[0m");

    for (int i = 0; i < players[0].getNumHand(); i++) {
        cout << i + 1 << ": ";
        
        /* if card is printed yellow, it can be played */
        if (possibleCards (players[0].getCard(i))) {
            printf("\u001b[33;1m"); 
            players[0].getCard(i)->displayCard();
            printf("\x1b[0m");
        }

        /* if card is printed gray, it cannot be played */
        else {
            printf("\u001b[30;1m");  
            players[0].getCard(i)->displayCard();
            printf("\x1b[0m");
        }
    }
}

/*********************************************************************
** Function: displayTargetCard ()
** Description: prints the card the player needs to match (the targetCard)
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: prints targetCard in inverted styles
*********************************************************************/ 
void Game::displayTargetCard () const {
    cout << "Card to match: ";

    printf("\u001b[7m");
    targetCard.displayCard();
    printf("\x1b[0m");

    cout << endl;
}

/*********************************************************************
** Function: playHuman ()
** Description: facilitates the human player's turn in a round
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: player will have made a move and will proceed to new player
*********************************************************************/ 
void Game::playHuman () {
    Card playCard;
    int choice;
    int yourDeck = players[0].getNumHand();

    promptHumanForCard ();
    cin >> choice;

    do {
        if (choice > yourDeck || choice < 0) {
            cout << "Please enter a valid option. " << endl;
            cin >> choice;
        }
    } while (choice > yourDeck || choice < 0);

    if (choice == 0 || choice > yourDeck)
        playCard = targetCard;
    else if ((choice > 0) && (choice <= yourDeck))
        playCard = (players[0].getHumanChoice(choice));
    
    errorHandle (choice, playCard, yourDeck);
    humanAction (choice, playCard);
}

/*********************************************************************
** Function: promptHumanForCard ()
** Description: tells player to choose a card and tells them to draw if no cards in hand are possible
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: prints appropriate response
*********************************************************************/ 
void Game::promptHumanForCard () {
    int track = 0;

    for (int i = 0; i < players[0].getNumHand(); i++) {
        if (possibleCards (players[0].getCard(i)))          //if no cards are possible, track = 0
            track = 1;
    }

    if (!(track == 1)) {
        cout << "You cannot play any cards. You must draw (enter 0)." << endl;
        cout << "► Type 0 here: ";
    }
    
    else {
        cout << "Which card would you like to play? Enter 0 to draw a card." << endl;
        cout << "► Type here: ";
    }
}

/*********************************************************************
** Function: humanAction ()
** Description: allows player to do an action (draw a card or play a card)
** Parameters: int choice, Card playCard
** Pre-Conditions: Game class
** Post-Conditions: if player plays a card, makes sure it's doable
*********************************************************************/ 
void Game::humanAction (int choice, Card playCard) {
    Card drawnCard;

    /* if human types 0, they draw a card */
    if (choice == 0)
        humanDrawCard (drawnCard);
    
    /* if human does not type 0, they play a card */
    else { 
        players[0].removeCardFromHand(choice);
        targetCard = playCard;
        cout << endl << "You play a: ";
        playCard.displayCard();
        humanPlayWild (playCard); 
    }

    /* if human's hand runs out of cards, they win */
    if (players[0].getNumHand() == 0)
        winner = 0;
}

/*********************************************************************
** Function: humanPlayWild ()
** Description: if human plays an 8, ask for and intiate next suit
** Parameters: Card playCard
** Pre-Conditions: Game class
** Post-Conditions: ask user for suit and change targetCard to that suit
*********************************************************************/ 
void Game::humanPlayWild (Card playCard) {
    int wild; 

    if (playCard.getRank() == 8) {
        cout << endl << "You played a wild 8. Choose the next rank." << endl;
        cout << "► Enter 0 for hearts." << endl;
        cout << "► Enter 1 for diamonds." << endl;
        cout << "► Enter 2 for spades." << endl;
        cout << "► Enter 3 for clubs." << endl;
        cin >> wild;

        while (!(wild >= 0 && wild <= 3)) {
            cout << "Please enter an integer from 0 to 4: ";
            cin >> wild;
        } 

        targetCard.changeSuit(wild);
    }
}

/*********************************************************************
** Function: humanDrawCard ()
** Description: human draws a card until they get a card they can play
** Parameters: Card drawnCard
** Pre-Conditions: Game class
** Post-Conditions: draws until possible, if wild, initiate wild prompt
*********************************************************************/ 
void Game::humanDrawCard (Card drawnCard) {
    cout << endl;
    do {
        drawnCard = cards.getTopCard();
        players[0].addCardToHand(cards.getTopCard());
        cards.removeCardFromDeck();
        cout << "You draw a: ";
        drawnCard.displayCard();
    } while(!checkCard(drawnCard));

    cout << endl << "You play a: ";
    drawnCard.displayCard();
    players[0].removeCardFromHand(players[0].getNumHand());
    targetCard = drawnCard;

    humanPlayWild (drawnCard);
}

/*********************************************************************
** Function: playComputer ()
** Description: facilitates the computer player's turn in a round
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: automatically plays a card for the computer and proceeds to next round
*********************************************************************/  
void Game::playComputer () {
    int track = 0;

    displayTargetCard ();
    cout << "\u001b[1m[COMPUTER'S TURN]\x1b[0m" << endl;
    computerPlayCard (track);

    if (track == 0)
        computerDrawCard ();

    if (players[1].getNumHand() == 0)   // comp wins if hand = 0
        winner = 1;
}

/*********************************************************************
** Function: computerPlayCard ()
** Description: iterates through comp's hand until there's a card it can play
** Parameters: int& track
** Pre-Conditions: Game class
** Post-Conditions: plays a card, if can't track = 0
*********************************************************************/ 
void Game::computerPlayCard (int& track) {
    int cardNum;
    Card playCard;

    for (int i = 0; i < players[1].getNumHand(); i++) {
        if (possibleCards (players[1].getCard(i))) {
            cardNum = i + 1;
            cout << "The computer plays a: ";
            players[1].getCard(i)->displayCard();

            playCard = (players[1].getHumanChoice(cardNum));
            players[1].removeCardFromHand(cardNum);
            targetCard = playCard;

            track = 1;
            break;
        }
    }
}

/*********************************************************************
** Function: computerDrawnCard ()
** Description: computer keeps drawing until gets possible card to play
** Parameters: none
** Pre-Conditions: Game class
** Post-Conditions: keeps drawing until possible and prints log of this
*********************************************************************/ 
void Game::computerDrawCard () {
    Card drawnCard;

    do {
        drawnCard = cards.getTopCard();
        players[1].addCardToHand(cards.getTopCard());
        cards.removeCardFromDeck();
        cout << "The computer draws a: ";
        drawnCard.displayCard();
    } while (!checkCard(drawnCard));

    cout << endl << "The computer plays a: ";
    drawnCard.displayCard();
    players[1].removeCardFromHand(players[1].getNumHand());
    targetCard = drawnCard;
}

/*********************************************************************
** Function: possibleCards ()
** Description: determines which cards in a hand can be played
** Parameters: Card* card
** Pre-Conditions: Game class
** Post-Conditions: returns true if possible, false if not
*********************************************************************/ 
bool Game::possibleCards (Card* card) const {
    /* wild card */
    if (card->getRank() == 8)  
        return true;
    
    /* same rank */
    else if (card->getRank() == targetCard.getRank())
        return true;
    
    /* same suit */
    else if (card->getSuit() == targetCard.getSuit()) 
        return true;
    
    /* else, not possible */
    else   
        return false;
}

/*********************************************************************
** Function: checkCard ()
** Description: determines if card player chose is possible
** Parameters: Card choice
** Pre-Conditions: Game class
** Post-Conditions: if possible, return true, if not return false
*********************************************************************/ 
bool Game::checkCard (Card choice) const {
    /* wild card */
    if (choice.getRank() == 8)
        return true;

    /* same rank */
    else if (choice.getRank() == targetCard.getRank()) 
        return true;

    /* same suit */
    else if (choice.getSuit() == targetCard.getSuit()) 
        return true;

    /* else, not possible */
    else 
        return false;
}

/*********************************************************************
** Function: errorHandle ()
** Description: error handle human player's responses
** Parameters: int choice, Card playCard, int yourDeck
** Pre-Conditions: Game class
** Post-Conditions: continue to reprompt while input is invalid
*********************************************************************/ 
void Game::errorHandle (int choice, Card playCard, int yourDeck) {
    bool check = checkCard(playCard);

    if (choice == 0);
    else if (check == false) {
        
        do {
            cout << "You cannot play this card. Please try again." << endl;
            cin >> choice;

            if (choice == 0 || choice > yourDeck);
            else {
                playCard = (players[0].getHumanChoice(choice));
                check = checkCard(playCard);
            }        

        } while (check == false && !(choice == 0));
    }
}