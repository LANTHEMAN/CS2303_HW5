#include "organism.h"


Organism::Organism(int r, int c)
{
	row = r;
	column = c;
}


Ant::Ant(int r, int c) : Organism(r,c)
{

}

DoodleBug::DoodleBug(int r, int c) : Organism(r,c)
{

}

int Organism::getRow(){
	return this->row;
}

int Organism::getColumn(){
	return this->column;
}

void Organism::move()
{

}

void Ant::move()
{

}

void DoodleBug::move()
{

}

Organism::~Organism(){}
Ant::~Ant(){}
DoodleBug::~DoodleBug(){}
