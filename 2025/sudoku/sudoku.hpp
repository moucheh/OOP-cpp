#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>

struct cell {
  int value;
  bool user;
  bool faulty;
  bool readonly;
};

class sudoku {
public:
  sudoku();
  void readPuzzle(std::istream&);
  void print(std::ostream&) const;
  void play();
  void validate(int row, int col);
  bool won() const;

private:
  bool check_row(int row);
  bool check_col(int col);
  bool check_submatrix(int start_row, int start_col);
  void remove_conflicts(int row, int col);
  std::pair<int, int> get_submatrix_start_indexes(int row, int col) const;

private:
  std::vector<std::vector<cell>> _game;
  int num_of_nzero_cells;
  int num_of_conflicts;
  std::string separator;
};

std::ostream& operator<<(std::ostream& os, const sudoku& s);
