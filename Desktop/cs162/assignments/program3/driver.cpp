/******************************************************
** Program: driver.cpp - Zoo Tycoon
** Author: Audrey Au
** Date: 07/22/22
** Description: This Zoo Tycoon simulator allows the user to make decisions with the goal of taking care of their animals and generating the most revenue as possible. Each week, a special random event occurs (sickness, birth, boost in attendance, or nothing), the weekly revenue is collected, the user can purchase more animals from the shop, the user pays for the animals' feeding costs, and the animals age by 1 week. The user can choose to exit whenever, but the game will exit if the user goes bankrupt.
** Input: int purchase (would you like to purchase?), int type (what type to purchase?), int numToPurchase (how many to purchase?), int again (would you like to continue?) 
** Output: displays weekly info (week number, bank amount, num animals, table of animals), narrates random events, announces revenue, guides user through the purchasing process, narrates feeding process, asks questions
******************************************************/

#include <iostream>
#include <cstdlib>

#include "zoo.h"
#include "animal.h"
#include "monkey.h"
#include "seaotter.h"
#include "meerkat.h"

using namespace std;

int main () {
    srand(time(0));
    
    Zoo game;
    game.zooTycoon ();

    return 0;
}
