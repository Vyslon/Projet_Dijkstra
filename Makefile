all: monprog.out

monprog.out: main.o Graphe.o
	g++ -g main.o Graphe.o -o monprog.out

main.o: main.cpp Graphe.h
	g++ -g -Wall -c -Wfatal-errors main.cpp

Graphe.o: Graphe.h Graphe.cpp Graphe.h
	g++ -g -Wall -c -Wfatal-errors Graphe.cpp

clean:
	rm *.o

veryclean: clean
	rm *.out
