all: sudoku.o main.o
	clang++ main.o sudoku.o -o main

sudoku.o: sudoku.cpp
	clang++ -c sudoku.cpp

main.o: main.cpp
	clang++ -c main.cpp

clean:
	rm *.o main
