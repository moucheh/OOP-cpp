#include <fstream>
#include <iostream>

#include "sudoku.hpp"

int main(int argc, char* argv[]) {
  sudoku s;
  std::ifstream f("input.txt");

  s.readPuzzle(f);
  s.print(std::cout);

  while (true) {
    s.play();
    if (s.won())
      break;
    std::cout << s;
  }

  std::cout << s;
  std::cout << "Congrats, you completed the game!" << std::endl;
  return 0;
}
