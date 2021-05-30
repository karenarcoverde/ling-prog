CPP = g++
CPPFLAGS = -Wall
LD = g++

PROGRAM = pacientes
OBJS = main.o cadastro.o paciente.o

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(LD) $(OBJS) -o $@

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<

clean:
	rm -f *.o $(PROGRAM)
