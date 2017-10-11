#ifndef ORGANISM_H
#define ORGANISM_H

class organism
{
public:
	organism(int r, int c);
	virtual void move();
	~organism();

private:
	int row;
	int colum;	
};

class ant: public organism
{
public:
	ant():organism(r,c);
	void move();
	~ant();

};

class doodleBug: public organism
{
public:
	doodleBug():organism(r,c);
	void move();
	~doodleBug();

}

#endif
