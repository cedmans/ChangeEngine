SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
OUT = libChangeEngine.a
DEP = $(SRC:.cpp=.d)

# includes
INCLUDES = -I.

# C++ compiler flags
CPPFLAGS = -g -Wall

# Compiler
CC = g++

#library paths
LIBS = -lSDL

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
	ar rcs $(OUT) $(OBJ)

clean:
	rm -f $(DEP) $(OBJ) $(OUT) Makefile.bak
