#LIBS =  -L. -lChangeEngine -lSDL -lSDL_image
#DEPS = KeyboardController.hpp

#.PHONY: clean test run

#all: Galaxterminate

#%.o: %.cpp $(DEPS)
	#$(CC) -c -o $@ $< $(CFLAGS)

#Galaxterminate: main.cpp KeyboardController.o ChangeEngine.hpp KeyboardController.hpp libChangeEngine.a
	#g++ -I. -o $@ KeyboardController.o $< $(LIBS)

#clean:
	#rm -f Galaxterminate *.o

#run: ChangeEngineTester
	#./$<

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
OUT = Galaxterminate
DEP = $(SRC:.cpp=.d)

# includes
INCLUDES = -I.

# C++ compiler flags
CPPFLAGS = -g -Wall

# Compiler
CC = g++

#library paths
LIBS = -L. -lChangeEngine -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

# compiler flags
LDFLAGS = -g

.SUFFIXES: .cpp .hpp

.PHONY: clean

default: $(OUT)

all: $(OUT)

%.d: %.cpp
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(SRC:.cpp=.d)

.cpp.o:
	$(CC) $(INCLUDES) $(CPPFLAGS) -c $< -o $@

$(OUT): $(OBJ) $(DPN)
	$(CC) $(INCLUDES) -o $(OUT) $(OBJ) $(LIBS)

clean:
	rm -f $(DEP) $(OBJ) $(OUT) Makefile.bak
