S=src
B=bin
O=obj


all: $(B)/monprog.out

$(B)/monprog.out: $(O)/main.o $(O)/Graphe.o
	g++ -g $(O)/main.o $(O)/Graphe.o -o $(B)/monprog.out

$(O)/main.o: $(S)/main.cpp $(S)/Graphe.h
	g++ -g -Wall -c -Wfatal-errors $(S)/main.cpp

$(O)/Graphe.o: $(S)/Graphe.h $(S)/Graphe.cpp $(S)/Graphe.h
	g++ -g -Wall -c -Wfatal-errors $(S)/Graphe.cpp

clean:
	rm $(O)/*.o

veryclean: clean
	rm $(S)/*.out
