LIBS =  -L. -lChangeEngine -lSDL -lSDL_image

.PHONY: clean test run

all: Galaxterminate

Galaxterminate: main.cpp ChangeEngine.hpp libChangeEngine.a
	g++ -I../ChangeEngine -o $@ $< $(LIBS)

clean:
	rm -f Galaxterminate *.o

run: ChangeEngineTester
	./$<
