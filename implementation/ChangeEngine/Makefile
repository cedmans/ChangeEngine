SRC = ChangeEngine.cpp GameWindow.cpp
OBJ = $(SRC:.cpp=.o)
OUT = libChangeEngine.a

# includes
INCLUDES = -I.

# C++ compiler flags
CPPFLAGS = -g -Wall

# Compiler
CC = g++

#library paths
LIBS =

# compiler flags
LDFLAGS = -g

.SUFFIXES: .cpp .hpp

.PHONY: clean

default: $(OUT)

all: $(OUT)

%.d: %.cpp
	set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(SRC:.cpp=.d)

.cpp.o:
	$(CC) $(INCLUDES) $(CPPFLAGS) -c $< -o $@

$(OUT): $(OBJ) $(DPN)
	ar rcs $(OUT) $(OBJ)

clean:
	rm -f *.d $(OBJ) $(OUT) Makefile.bak
