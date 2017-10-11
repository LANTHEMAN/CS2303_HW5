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
	int column;
};

class Ant: public Organism
{
public:
	Ant(int r, int c);
	void move();
	~Ant();

};

class DoodleBug: public Organism
{
public:
	DoodleBug(int r, int c);
	void move();
	~DoodleBug();

};

#endif
