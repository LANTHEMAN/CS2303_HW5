#ifndef ORGANISM_H
#define ORGANISM_H

class organism
{
public:
	organism();
	virtual move();
	~organism();
	
};

class ant: public organism
{
public:
	ant();
	move();
	~ant();
	
};

class doodleBug: public organism
{
public:
	doodleBug();
	move();
	~doodleBug();
}

#endif
