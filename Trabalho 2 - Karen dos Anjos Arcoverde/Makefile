CPP = g++
CPPFLAGS = -Wall
LD = g++

PROGRAM = grafo
OBJS = main.o vertice.o aresta.o grafo.o

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(LD) $(OBJS) -o $@

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<

clean:
	rm -f *.o $(PROGRAM)
