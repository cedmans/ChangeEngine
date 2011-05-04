SRC = ChangeEngine.cpp GameWindow.cpp
OBJ = $(SRC:.cpp=.o)
DPN = $(SRC:.cpp=.d)
OUT = libChangeEngine.a

# includes
INCLUDES = -I.

# C++ compiler flags
CCFLAGS = -g -Wall

# Compiler
CC = g++

#library paths
LIBS =

# compiler flags
LDFLAGS = -g

.SUFFIXES: .cpp .hpp

default: $(OUT)

.cpp.d:
	g++ -MM $< | sed 's!%$(<:.cpp=.o):!$(<:.cpp=.o) $(<:.cpp=.d):!' > $@

.cpp.o:
	$(CC) $(INCLUDES) $(CCFLAGS) -c $< -o $@

$(OUT): $(OBJ) $(DPN)
	ar rcs $(OUT) $(OBJ)

clean:
	rm -f $(OBJ) $(OUT) Makefile.bak
