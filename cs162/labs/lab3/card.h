/*
    This file describes the Card class
*/ 

#ifndef CARD_H     //want header guard on all .h files
#define CARD_H

class Card {
  private:
    int rank;  // Should be in the range 0-12.
    /*
      0 = jack            7 = 7 
      1 = ace             8 = 8      
      2 = 2               9 = 9
      3 = 3               10 = 10
      4 = 4               11 = queen
      5 = 5               12 = king
      6 = 6            
    */
    int suit;  // Should be in the range 0-3.
    /*
      0 = hearts
      1 = diamonds
      2 = spades
      3 = clubs
    */
    int number;
  public:
    void setContent (int, int, int);
    void display ();  //rank + suit built into class
};

#endif