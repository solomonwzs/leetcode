# vim: noet:

.SUFFIXES: 	.cpp

CC 			=g++
CFLAGS 		=-Wall -fpic -g -c -std=gnu++11

UTILS 		=cpp/utils.cpp

ALL_SOURCES	=$(wildcard ./cpp/*.cpp)
SOURCES 	=$(filter-out $(UTILS), $(ALL_SOURCES))
OBJECTS 	=$(SOURCES:%.cpp=%.o)


.cpp.o:
	@echo -e "\033[01;33m[Compile]\033[0m $< ... "
	@$(CC) $(CFLAGS) $< -o $@
	@if [ "$<" != "$(UTILS)" ]; then \
		$(CC) $@ $(UTILS:%.cpp=%.o) -o $(patsubst cpp/%.cpp,bin/%,$<); \
	fi
	@echo -e "\033[01;32m[OK]\033[0m $(patsubst cpp/%.cpp,%,$<)"

all:$(UTILS:%.cpp=%.o) $(OBJECTS)

clean:
	@rm $(OBJECTS) ./bin/* 2>/dev/null
