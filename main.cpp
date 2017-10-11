//Author: LMAO RWWITTENBERG
#include <cstdlib>
#include <iostream>
#include "board.h"
/*PA5 gridSize #doodlebugs #ants #time_steps seed pause*/

void printAddresses(Organism*** o, int size){
  for(int i=0; i<size; i++){
    for(int j=0 ; j<size; j++){
      printf("%p  ", o[i][j]);
    }
    printf("\n");
  }
}

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

    const int s= gridSize;
    Board* board = new Board(s);
    Organism*** boardValues = board->getValues();

    printAddresses(boardValues, gridSize);

    printf("loading doodlebugs\n");
    for(int i=0; i<numBug; i++){
      bool added = false;
      do{

        int rowD = rand() % gridSize;
        int columnD = rand() % gridSize;
        printf("empty cell   %i, %i\n", rowD, columnD);
        printf("%p\n", boardValues[rowD][columnD]);
        if(!boardValues[rowD][columnD]){
          DoodleBug* d = new DoodleBug(rowD, columnD);
          printf("new doodlebug in   %i    %i\n", rowD, columnD);
          board->addOrganism(d);
          added=true;
        }else{
          printf("cell occupied\n");
        }
      }while(!added);
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

    printf("done loading\n");
    for(int i=0; i<steps; i++){
      board->step();
    }


}
