vpath ChangeEngine.hpp ../ChangeEngine
vpath libChangeEngine.a ../ChangeEngine

LIBS =  -L../ChangeEngine -lChangeEngine -lSDL

.PHONY: clean test run

all: ChangeEngineTester

ChangeEngineTester: main.cpp ChangeEngine.hpp libChangeEngine.a
	g++ -I../ChangeEngine -o $@ $< $(LIBS)

clean:
	rm -f ChangeEngineTester

test: ChangeEngineTester
	valgrind ./ChangeEngineTester

run: ChangeEngineTester
	./$<
