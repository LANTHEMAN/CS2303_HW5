#include "organism.h"


Organism::Organism(int r, int c)
{
	row = r;
	colum = c;
}


class ant: public organism
{
public:
	ant();
	~ant();

};

class doodleBug: public organism
{
public:
	doodleBug();
	~doodleBug();
}

Organism::getRow(){
	return this.row;
}

Organism::getColumn(){
	return this.column;
}

virtual void move()
{

}

void ant::move()
{

}

organism::~organism(){}
ant::~ant(){}
doodleBug::~doodleBug(){}
