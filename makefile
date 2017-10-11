
CFLAGS=-g

all: PA5

docs:
	doxygen

PA5: main.o board.o organism.o
	g++ $(CFLAGS) -Wall main.o board.o organism.o -o PA5

main.o: main.cpp board.h
	g++ -c -Wall main.cpp

board.o: board.cpp board.h
	g++ -c -Wall board.cpp

organism.o: organism.cpp organism.h
	g++ -c -Wall organism.cpp




clean:
	rm   -f  *.o PA5