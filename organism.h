#ifndef ORGANISM_H
#define ORGANISM_H

class Organism
{
public:
Organism(int r, int c);
	virtual void move();
	~Organism();
	int getRow();
	int getColumn();
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
