#include <iostream>
#include "Musician.h"
using namespace std;

Musician::Musician() : fName(""), lName(""), role("")
{
}

Musician::Musician(string fName, string lName, string role)
{
	this->fName = fName;
	this->lName = lName;
	this->role = role;
}

Musician::Musician(const Musician & muToCopy)
{
	this->fName = muToCopy.fName;
	this->lName = muToCopy.lName;
	this->role = muToCopy.role;
}

Musician::~Musician()
{
}

void Musician::operator=(const Musician & muToCopy)
{
	this->fName = muToCopy.fName;
	this->lName = muToCopy.lName;
	this->role = muToCopy.role;
}

void Musician::setFirstName(string fName)
{
	this->fName = fName;
}

void Musician::setLastName(string lName)
{
	this->lName = lName;
}

void Musician::setRole(string role)
{
	this->role = role;
}

string Musician::getFirstName() const
{
	return fName;
}

string Musician::getLastName() const
{
	return lName;
}

string Musician::getRole() const
{
	return role;
}