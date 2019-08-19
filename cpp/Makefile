# vim: noet:

.SUFFIXES: 	.cpp

CC		= g++
CFLAGS	= -Wall -fpic -g -c -std=gnu++11

SOURCES	= $(wildcard ./src/*.cpp)

OBJ	= $(SOURCES:./src/%.cpp=./build/%.o)
DEP	= $(OBJ:%.o=%.d)

X_OBJ	= $(filter-out ./build/leetcode.o, $(OBJ))
X_FIL	= $(X_OBJ:%.o=%.x)

VALGRIND	= valgrind


.PHONY: all
all:./build ./build/libleetcode.so $(X_FIL)

-include $(DEP)

.SECONDARY:
./build/%.o: ./src/%.cpp
	@echo -e "\033[0;33m*\033[0m $@"
	@$(CC) $(CFLAGS) -MMD $< -o $@

./build/%.x: ./build/%.o ./build/libleetcode.so
	@echo -e "\033[0;33m*\033[0m $@"
	@$(CC) $< -o $@ -L./build -lleetcode -Wl,-R./build

./build/libleetcode.so: ./build/leetcode.o
	@echo -e "\033[0;33m*\033[0m $@"
	@$(CC) -shared -Wl,-soname,libleetcode.so $< -o $@

./build:
	@[ -d $@ ] || mkdir $@

mem_check: all
	$(VALGRIND) \
		--tool=memcheck \
		--leak-check=yes \
		--show-reachable=yes \
		--num-callers=20 \
		--track-fds=yes \
		./build/implement_magic_dictionary

.PHONY: clean
clean:
	@rm -r ./build
