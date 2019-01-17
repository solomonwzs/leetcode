# vim: noet:

.SUFFIXES: 	.cpp

CC 			= g++
CFLAGS 		= -Wall -fpic -g -c -std=gnu++11

UTILS 		= cpp/utils.cpp

LIB_PATH 	= $(shell pwd)/build

ALL_SOURCES	= $(wildcard ./cpp/*.cpp)
SOURCES 	= $(filter-out $(UTILS), $(ALL_SOURCES))
OBJECTS 	= $(SOURCES:%.cpp=%.o)

VALGRIND	= valgrind


.cpp.o:
	@echo -e "\033[01;33m[Compile]\033[0m $< ... "
	@$(CC) $(CFLAGS) $< -o $@
	@if [ "$<" != "$(UTILS)" ]; then \
		$(CC) $@ -o $(patsubst cpp/%.cpp,build/%,$<) -L$(LIB_PATH) \
			-l$(UTILS:cpp/%.cpp=%) -Wl,-R$(LIB_PATH); \
	else \
		$(CC) -shared -Wl,-soname,lib$(patsubst cpp/%.cpp,%,$<).so \
			-o $(patsubst cpp/%.cpp,build/lib%.so,$<) \
			$(patsubst %.cpp,%.o,$<); \
	fi
	@echo -e "\033[01;32m[OK]\033[0m $(patsubst cpp/%.cpp,%,$<)"

all:pre $(UTILS:%.cpp=%.o) $(OBJECTS)

clean:
	@rm $(OBJECTS) ./build/* 2>/dev/null

pre:
	@[ -d build ] || mkdir build

mem_check: all
	$(VALGRIND) \
		--tool=memcheck \
		--leak-check=yes \
		--show-reachable=yes \
		--num-callers=20 \
		--track-fds=yes \
		./build/implement_magic_dictionary
