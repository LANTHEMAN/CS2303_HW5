//Author: LMAO RWITTENBURG
#include <cstdlib>
#include <iostream>
#include "board.h"
/*PA5 gridSize #doodlebugs #ants #time_steps seed pause*/
int main(int argc, char* argv[])
{

    int gridSize = 20;
    int numBug = 5;
    int numAnt = 100;
    int steps = 1000;
    int seed = 1;
    int pause = 0;
  switch(argc)
  {
    case 1:
    gridSize = 20;
    numBug = 5;
    numAnt = 100;
    steps = 1000;
    seed = 1;
    pause = 0;
    break;

    case 2:
    gridSize = atoi(argv[1]);
    numBug = 5;
    numAnt = 100;
    steps = 1000;
    seed = 1;
    pause = 0;
    break;

    case 3:
    gridSize = atoi(argv[1]);
    numBug = atoi(argv[2]);
    numAnt = 100;
    steps = 1000;
    seed = 1;
    pause = 0;
    break;

    case 4:
    gridSize = atoi(argv[1]);
    numBug = atoi(argv[2]);
    numAnt = atoi(argv[3]);
    steps = 1000;
    seed = 1;
    pause = 0;
    break;

    case 5:
    gridSize = atoi(argv[1]);
    numBug = atoi(argv[2]);
    numAnt = atoi(argv[3]);
    steps = atoi(argv[4]);
    seed = 1;
    pause = 0;
    break;

    case 6:
    gridSize = atoi(argv[1]);
    numBug = atoi(argv[2]);
    numAnt = atoi(argv[3]);
    steps = atoi(argv[4]);
    seed = atoi(argv[6]);
    pause = 0;
    break;

    case 7:
    gridSize = atoi(argv[1]);//
    numBug = atoi(argv[2]);//
    numAnt = atoi(argv[3]);//
    steps = atoi(argv[4]);//
    seed = atoi(argv[5]);
    pause = atoi(argv[6]);
    break;
  }

    Board* board = new Board(gridSize);
    Organism*** boardValues = board->getValues();

    printf("loading doodlebugs\n");
    for(int i=0; i<numBug; i++){
      bool added = false;
      int count =0;
      do{
        printf("empty cell\n");
        int rowD = gridSize*rand()/int(RAND_MAX);
        int columnD = gridSize*rand()/int(RAND_MAX);
        if(!boardValues[rowD][columnD]){
          DoodleBug* d = new DoodleBug(rowD, columnD);
          board->addOrganism(d);
          added=true;
        }else{
          printf("cell occupied\n");
          count++;
        }
      }while(!added && count<4);
    }

    printf("loading ants\n");
    for(int i=0; i<numAnt; i++){
      printf("empty cell\n");
      bool added = false;
      int count =0;
      do{
        int rowA = gridSize*rand()/int(RAND_MAX);
        int columnA = gridSize*rand()/int(RAND_MAX);
        if(!boardValues[rowA][columnA]){
          Ant* a = new Ant(rowA, columnA);
          board->addOrganism(a);
          added=true;
        }else{
          printf("repeating cell\n");
          count++;
        }
      }while(!added && count<4);
    }


}
