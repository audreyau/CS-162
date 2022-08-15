/*
	Goat Class
*/
#ifndef GOAT_H
#define GOAT_H

#include <iostream>
#include "animal.h"

class Goat : public Animal {
public:
	Goat();
	Goat(std::string);
	~Goat();

	virtual void make_noise() override;

private:
};
#endif
