# Lab 4: Getting Familiar with Classes (Object-oriented Programming)
*You must attend the lab in order to earn points. You will automatically receive 7 points for attending/participating and you will receive the remaining 3 points after submitting your tar file to Canvas (prior to next week's lab). For extenuating circumstances, contact your lab TA or the instructor.*

In this lab you will be writing the core code which will allow us to create games using a standard 52 card deck of playing cards. You may work with a partner of your choice.
Note: the following classes are referring to the starter code that was provided with Program #2.

## Card Class
Design and create the .h and .cpp files with accessors and mutators for a Card class. Cards have two properties, **suit** and **rank**. The four possible suits are diamonds, clubs, hearts, and spades. There are 13 possible ranks:
- the numbers 2-10
- Jack (J)
- Queen (Q)
- King (K)
- Ace (A)

## Deck Class
Design and create the .h and .cpp files with accessors and mutators for a Deck class. Decks are made up of 52 Cards. The Deck class should have functions for creating the deck (filling it with the traditional 52 cards), shuffling the cards, and displaying the entire deck to the user.

## Implementation
Now, create a driver.cpp file that:
- creates a deck
- shuffles the cards
- prints out the results in a human-friendly format

## Makefile
Add a Makefile that compiles all of your .cpp and .h files and generates an executable named **deck_shuffle**. You are allowed to write your own Makefile or you can adapt one from the lecture samples.

## Submission
Create a tar file that contains your Makefile, .cpp files, and .h files. Submit your tar file to Canvas.
```
tar -cvf assign2.tar list_of_all_the_.h_and_.cpp_files Makefile
```
*Remember, you will not receive any lab credit if you do not attend lab. Once you have a zero on a lab, then it cannot be changed because we have no way of knowing if you were there or not!*
