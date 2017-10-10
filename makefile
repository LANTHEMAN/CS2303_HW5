
CFLAGS=-g

all: PA5

docs:
	doxygen

PA5: main.o board.o
	g++ $(CFLAGS) -Wall main.o board.o -o PA5

main.o: main.cpp board.h
	g++ -c -Wall main.cpp

board.o: board.cpp board.h
	g++ -c -Wall board.cpp





clean:
	rm   -f  *.o PA5