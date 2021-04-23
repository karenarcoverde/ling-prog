CPP = g++
CPPFLAGS = -Wall
LD = g++

PROGRAM = covid
OBJS = analise-covid.o Nacional.o Estadual.o

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(LD) $(OBJS) -o $@

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<

clean:
	rm -f *.o $(PROGRAM)
