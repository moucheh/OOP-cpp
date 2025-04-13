#include <iostream>
#include <fstream>
#include <vector>
#include "sudoku.h"

int main(int argc, char *argv[]) {
  sudoku s;
  std::ifstream f("input.txt");

  s.readPuzzle(f);
  s.print(std::cout);

  while(true) {
    s.play();
    s.validate();
    s.print(std::cout);
  }
  return 0;
}
