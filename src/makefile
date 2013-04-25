CC=gcc
CFLAGS=-I.
DEPS = Client.h Graph.h Map.h Zone.h Files.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: Client.o Main.o Map.o Zone.o
	g++ -o cal Client.o Main.o Map.o Zone.o -I.