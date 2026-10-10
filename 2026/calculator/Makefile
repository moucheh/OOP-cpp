COMPILER = g++

OBJS = build/main.o \
			 build/Calculator.o

all: ${OBJS}
	${COMPILER} ${OBJS} -o calc

build/Calculator.o: Calculator.cpp Calculator.hpp
	mkdir -p build
	${COMPILER} -c Calculator.cpp -o build/Calculator.o

build/main.o: main.cpp
	mkdir -p build
	${COMPILER} -c main.cpp -o build/main.o

.PHONY: clean run

run:
	./calc

clean:
	rm -r build calc
