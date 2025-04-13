#pragma once
#include <iostream>
#include <string>
#include <vector>

struct cell {
  int value;
  bool user;
  bool faulty;
  bool readonly;
};

class sudoku{
public:
  sudoku();
  void readPuzzle(std::istream&);
  void print(std::ostream&);
  void play();
  void validate();
  void validate(int row, int col);
  bool won();

private:
  void check_row(int row);
  void check_col(int col);
  void check_submatrix(int start_row, int start_col);

private: 
  std::vector<std::vector<cell>> _game;
  int num_of_nzero_cells;
  int num_of_conflicts;
  std::string separator;
};
