CC       = g++
CCFLAGS  = 
ACCFLAGS = 

BIN =  Jacobi_seq GS_seq

all: $(BIN)

GS_seq: GS_seq.cpp
		$(CC) $(CCFLAGS) $(ACCFLAGS) -o $@ $<

Jacobi_seq: Jacobi_seq.cpp
		$(CC) $(CCFLAGS) $(OMPFLAGS) -o $@ $<

clean:
		$(RM) $(BIN)
