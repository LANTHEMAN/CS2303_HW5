#ifndef ORGANISM_H
#define ORGANISM_H

class Organism
{
public:
Organism(int r, int c);
	virtual void move(Organism*** boardRange, int size) = 0;
	virtual ~Organism();
	int getRow();
	int getColumn();
	virtual int isAnt();
	void survive();
	int getSurvived();
	int getStarvation();
  void setStarvation();

protected:
	int starvation;
	int survived;
	int row;
	int column;

protected:
	void moveToRandomAdjacent(Organism*** b, int s);
};

class Ant: public Organism
{
public:
	Ant(int r, int c);
	void move(Organism*** boardRange, int size);
	~Ant();
	int isAnt();

};

class DoodleBug: public Organism
{
public:
	DoodleBug(int r, int c);
	void move(Organism*** boardRange, int size);
	~DoodleBug();
	int isAnt();
	void eat();

};

#endif
