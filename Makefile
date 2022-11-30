S=src
B=bin
O=obj


all: $(B)/monprog.out

$(B)/monprog.out: $(O)/main.o $(O)/graphe.o
	g++ -g $(O)/main.o $(O)/graphe.o -o $(B)/monprog.out

$(O)/main.o: $(S)/main.cpp $(S)/graphe.h
	g++ -g -Wall -c -Wfatal-errors $(S)/main.cpp -o $(O)/main.o

$(O)/graphe.o: $(S)/graphe.h $(S)/graphe.cpp $(S)/graphe.h $(S)/distPred.h
	g++ -g -Wall -c -Wfatal-errors $(S)/graphe.cpp -o $(O)/graphe.o

clean:
	rm $(O)/*.o

veryclean: clean
	rm $(S)/*.out
