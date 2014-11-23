# vim: noet:

.SUFFIXES: 	.cpp

CC 			=g++
CFLAGS 		=-Wall -g -c -std=gnu++11

SOURCES		=$(wildcard ./cpp/*.cpp)
OBJECTS 	=$(SOURCES:%.cpp=%.o)


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	$(CC) $@ -o $(patsubst cpp/%.cpp,bin/%,$<)

all:$(OBJECTS)

clean:
	rm $(OBJECTS) ./bin/*
