CPP = g++
CPPFLAGS = -Wall
LD = g++

PROGRAM = filmes
OBJS = main.o filme.o catalogo.o

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(LD) $(OBJS) -o $@

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<

clean:
	rm -f *.o $(PROGRAM)
