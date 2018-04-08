CC = gcc 
CFLAGS = -Wall -g

HEADERS = fractal.h

#every .c file in directory
SRCS = fractal.c #tools.c

#adds a .o file for every header file and .c file
OBJECTS =  $(patsubst %.h %.c, %.o,$(SRCS) $(HEADERS) ) 

#libraries to include
LIBS = -pthread -lSDL

TARGET = libfractal

default: $(TARGET)

#compile every object files into the target executable
$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@ $(CFLAGS)

#compile every .c and .h file into object files
%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@ $(CFALGS)

.PHONY: clean rmall

clean:
	$(RM) *.o 
rmall:
	$(RM) *.o $(TARGET)