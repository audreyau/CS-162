/*
	This file describes the Cart class.
*/
#ifndef CART_H
#define CART_H

#include <iostream>
#include "Laptop.h"

#define MAXNUMLAPTOPS 10

class Cart {
  private:
    Laptop laptops[MAXNUMLAPTOPS];
    int numLaptops; // how many laptops does the cart currently contain?

  public:
	void initialize();
	void display();
	Laptop grabLaptop();

};

#endif
