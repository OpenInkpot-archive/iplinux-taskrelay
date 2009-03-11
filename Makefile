CFLAGS=-O2 -g -std=c99

PROGRAMS=runtask

all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS)
