#include "organism.h"


organism::organism(int r, int c)
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


virtual void move()
{

}

void ant::move()
{

}

organism::~organism(){}
ant::~ant(){}
doodleBug::~doodleBug(){}