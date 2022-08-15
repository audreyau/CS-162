/*
	This file describes the Laptop class.
*/
#ifndef LAPTOP_H
#define LAPTOP_H

class Laptop {
  private:
	int ramSpace;
	int hddSpace;
	double screenSize;
	int id;

  public:
	void randomize();
	void display();
};

#endif
