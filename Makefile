CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic	
LDFLAGS=

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES: .c=.o)
EXECUTABLES=goblers 

all:$(EXECUTABLES)
	./$(EXECUTABLES)

$(EXECUTABLES): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLES)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del -f *.o *.exe 