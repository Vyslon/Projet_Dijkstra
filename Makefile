S=src
B=bin
O=obj

all: $(B)/monprog.out

$(B)/monprog.out: $(O)/main.o $(O)/graphe.o $(O)/distPred.o
	g++ -g $(O)/main.o $(O)/graphe.o $(O)/distPred.o -o $(B)/monprog.out

$(O)/main.o: $(S)/main.cpp $(S)/graphe.h
	g++ -g -Wall -c -Wfatal-errors $(S)/main.cpp -o $(O)/main.o --std=c++11

$(O)/graphe.o: $(S)/graphe.h $(S)/graphe.cpp $(S)/graphe.h $(S)/distPred.h
	g++ -std=c++17 -g -Wall -c -Wfatal-errors $(S)/graphe.cpp -o $(O)/graphe.o

$(O)/distPred.o : $(S)/distPred.h $(S)/distPred.cpp 
	g++ -std=c++17 -g -Wall -c -Wfatal-errors $(S)/distPred.cpp -o $(O)/distPred.o

clean:
	rm $(O)/*.o

veryclean: clean
	rm $(B)/*.out

