CC=gcc
CFLAGS = -Wall -g

HEADERS = $(wildcard *.h)

#every .c file in directory
SRCS = $(wildcard *.c)

#adds a .o file for every source file
OBJECTS =  $(SRCS:.c=.o)

#libraries to include
LIBS = -pthread -lSDL

TARGETS =$(SRCS:%.c=%)

default: $(TARGETS)

#compilation of each c file into an object file
%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

#individual compilation of each object file
$(TARGETS): $(OBJECTS)
	$(CC) -o $@ $(@:%=%.o) $(CFLAGS)
	./$@

.PHONY: clean

clean:
	$(RM) *.o $(TARGETS)
