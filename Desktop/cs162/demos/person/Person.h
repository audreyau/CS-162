/*
	Person Class
*/
#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person {
public:
	Person(); // default constructor
	Person(std::string);
	std::string getName();
	std::string getRank();

protected:
	std::string name;
	int id;
	std::string email;
	std::string phone;

private:
	int ssn;

};
#endif
