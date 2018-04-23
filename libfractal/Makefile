CC = gcc 
CFLAGS = -Wall -g

#C headers in directory
HEADERS = $(wildcard *.h)

#every .c file in directory
SRCS = $(wildcard *.c)

#adds a .o file for every source file
OBJECTS =  $(SRCS:.c=.o)

#libraries to include
LIBS = -pthread -lSDL 

TARGET = libfractal.a

default: $(TARGET)

#compile every object files into a library file
$(TARGET): $(OBJECTS)
	ar -rcs -o $@ $^ $(LIBS)

#compile every .c and .h file into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFALGS) -c $< -o $@  $(LIBS)

.PHONY:clean rmall

clean:
	$(RM) *.o 
rmall:
	$(RM) *.o $(TARGET)
