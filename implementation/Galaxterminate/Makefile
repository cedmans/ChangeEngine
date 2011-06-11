LIBS =  -L. -lChangeEngine -lSDL -lSDL_image
DEPS = KeyboardController.hpp

.PHONY: clean test run

all: Galaxterminate

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Galaxterminate: main.cpp KeyboardController.o ChangeEngine.hpp KeyboardController.hpp libChangeEngine.a
	g++ -I. -o $@ KeyboardController.o $< $(LIBS)

clean:
	rm -f Galaxterminate *.o

run: ChangeEngineTester
	./$<
