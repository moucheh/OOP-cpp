#include "sudoku.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  sudoku s;
  std::ifstream f("input.txt");

  s.readPuzzle(f);
  s.print(std::cout);

  while (true) {
    s.play();
    if (s.won())
      break;
    s.print(std::cout);
  }

  s.print(std::cout);
  std::cout << "Congrats, you completed the game!" << std::endl;
  return 0;
}
