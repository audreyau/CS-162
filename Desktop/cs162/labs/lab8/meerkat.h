/*
	Meerkat Class
*/
#ifndef Meerkat_H
#define Meerkat_H

#include <iostream>
#include "animal.h"

class Meerkat : public Animal {
public:
	Meerkat();
	Meerkat(std::string);
	~Meerkat();

	virtual void make_noise();

private:
};
#endif
