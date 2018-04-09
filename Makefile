CC = gcc 
CFLAGS = -Wall -g

#every .h file in directory
HEADERS = $(wildcard *.h) 

#every .c file in directory
SRCS = $(wildcard *.c) 

#adds a .o file for every header file and .c file
OBJECTS =  $(SRCS:.c=.o)

#libraries to include
LIBS = -pthread -lSDL -L./libfractal -lfractal

TEST= -I./tests

TARGET = main

default: lib
	$(MAKE) $(TARGET)
	
#compile every object files into the target executable
$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

#compile every .c and .h file into object files
%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@ $(CFALGS)

.PHONY: clean lib test 

clean:
	$(RM) *.o $(TARGET)
	(cd libfractal; make rmall)
	(cd tests; make clean)
	
#compiles and runs all test files in ./tests
test:
	$(MAKE) -C tests

#compiles the fractal library in ./libfractal
lib:
	$(MAKE) -C libfractal
	
