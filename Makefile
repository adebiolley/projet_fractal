CC = gcc 
CFLAGS = -Wall -g

#every .h file in directory
HEADERS = $(wildcard *.h) 

#every .c file in directory
SRCS = $(wildcard *.c) 

#adds a .o file for every header file and .c file
OBJECTS =  $(patsubst %.h %.c, %.o,$(SRCS) $(HEADERS) ) 

#libraries to include
LIBS = -pthread -lSDL

LIBFRAC =

TARGET = main

default: $(TARGET)

#compile every object files into the target executable
$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@ $(CFLAGS)

#compile every .c and .h file into object files
%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@ $(CFALGS)

.PHONY: clean lib test

clean:
	$(RM) *.o $(TARGET)
	
test:

lib:
