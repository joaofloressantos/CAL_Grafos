CC=g++
CFLAGS=-I.
DEPS = Client.h Graph.h Map.h Zone.h Files.h Connection.h Edgetype.h Graphviewer.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: Client.o Main.o Map.o Zone.o Connection.o Graphviewer.o
	g++ -o cal Client.o Main.o Map.o Zone.o Connection.o Graphviewer.o -I.