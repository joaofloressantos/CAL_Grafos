CC=gcc
CFLAGS=-I.
DEPS = Client.h Graph.h Map.h Zone.h Files.h connection.h edgetype.h graphviewer.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: Client.o Main.o Map.o Zone.o connection.o graphviewer.o
	g++ -o cal Client.o Main.o Map.o Zone.o connection.o graphviewer.o -I.