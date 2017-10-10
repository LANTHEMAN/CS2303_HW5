#ifndef ORGANISM_H
#define ORGANISM_H

class organism
{
public:
	organism(int );
	virtual void move();
	~organism();
	
};

class ant: public organism
{
public:
	ant();
	void move();
	~ant();
	
};

class doodleBug: public organism
{
public:
	doodleBug();
	void move();
	~doodleBug();
}

#endif
