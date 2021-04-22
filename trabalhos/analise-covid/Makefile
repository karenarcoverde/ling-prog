CPP = g++
CPPFLAGS = -Wall
LD = g++

PROGRAM = covid
OBJS = covid-analise.o Nacional.o Estadual.o

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(LD) $(OBJS) -o $@

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<

clean:
	rm -f *.o $(PROGRAM)