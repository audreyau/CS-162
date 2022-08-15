/*
	Fish Class
*/
#ifndef FISH_H
#define FISH_H

#include <iostream>
#include "animal.h"

class Fish : public Animal {
public:
	Fish();
	~Fish();

	virtual void make_noise() override;

private:
};
#endif
