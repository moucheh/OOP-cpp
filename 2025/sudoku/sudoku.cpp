#include "sudoku.hpp"
#include <sstream>
#include <string>
#include <map>

sudoku::sudoku() : _game(9), num_of_nzero_cells(0), num_of_conflicts(0) {
  for (auto& row : _game)
    row.resize(9, {0, false, false, false});

  const std::string plus(1, '+');
  const std::string minus(3, '-');
  const std::string sub_separator =
      plus + minus + plus + minus + plus + minus + plus;

  separator = sub_separator + sub_separator + sub_separator;
}

void sudoku::readPuzzle(std::istream &is) {
  for (auto& row : _game)
    for (auto& col : row) {
      is >> col.value;
      if (col.value) {
        col.readonly = true;
        ++num_of_nzero_cells;
      }
    }
}

void sudoku::print(std::ostream &os) {
  os << "Cells filled: " << num_of_nzero_cells << "/81, conflicts: " << num_of_conflicts << std::endl;

  const auto check_if_multiple_of_3_or_last = [] (int val) {
    return (val + 1) % 3 == 0 && val != 8;
  };

  for (auto i = 0; i < 9; ++i) {
    os << separator << std::endl;
    for (auto j = 0; j < 9; ++j) {
      const cell &cell = _game[i][j];
      os << '|' << ' ' << (!cell.faulty ? ' ' : '*') << ' ';
      if (check_if_multiple_of_3_or_last(j))
        os << '|';
    }
    os << '|' << std::endl;

    for (auto j = 0; j < 9; ++j) {
      const cell &cell = _game[i][j];
      if (cell.user) {
        os << '|' << '(' << cell.value << ')';
        if (check_if_multiple_of_3_or_last(j))
          os << '|';
      } else {
        os << '|' << ' ' << (char)(cell.value ? cell.value + '0' : ' ') << ' ';
        if (check_if_multiple_of_3_or_last(j))
          os << '|';
      }
    }
    os << '|' << std::endl;
    if (check_if_multiple_of_3_or_last(i))
      os << separator << std::endl;
  }
  os << separator << std::endl;
}

void sudoku::play() {
  const auto check_range = [](int val) {
    return !std::cin || val > 9 || val < 1;
  };

  std::cout << "Enter your move(val: 1-9, row: 1-9, col: 1-9): ";

  int value, row, col;

  std::string input;

  std::getline(std::cin, input);

  std::istringstream is(input);

  is >> value;

  if (check_range(value)) {
    std::cout << "Invalid value, 1 through 9 only allowed!" << std::endl;
    return play();
  }

  is >> row;

  if (check_range(row)) {
    std::cout << "Invalid row, 1 through 9 only allowed!" << std::endl;
    return play();
  }

  is >> col;

  if (check_range(col)) {
    std::cout << "Invalid column, 1 through 9 only allowed!" << std::endl;
    return play();
  }
  auto &target_cell = _game[row - 1][col - 1];

  if (target_cell.readonly) {
    std::cout << "Readonly cell!" << std::endl;
    return play();
  }

  target_cell.value = value;
  target_cell.user = true;
  ++num_of_nzero_cells;
  

  validate(row - 1, col - 1);
}

void sudoku::check_row(int row) {
  std::map<int, int> m;

  for (const auto &cell : _game[row])
    if (cell.value)
      ++m[cell.value];

  int conflict = 0;

  for (const auto &[key, value] : m)
    if (value > 1)
      conflict = key;

  if (conflict) {
    for (auto &cell : _game[row])
      if (cell.value == conflict && cell.user && !cell.faulty) {
        cell.faulty = true;
        ++num_of_conflicts;
        break;
      }
  }
}

void sudoku::check_col(int col) {
  std::map<int, int> m;

  for (const auto row : _game)
    if (row[col].value)
      ++m[row[col].value];

  int conflict = 0;

  for (const auto &[key, value] : m)
    if (value > 1)
      conflict = key;

  if (conflict) {
    for (auto &row : _game)
      if (row[col].value == conflict && row[col].user && !row[col].faulty) {
        row[col].faulty = true;
        ++num_of_conflicts;
        break;
      }
  }
}

void sudoku::check_submatrix(int start_row, int start_col) {
  std::map<int, int> m;

  for (auto i = start_row; i < start_row + 3; ++i)
    for(auto j = start_col; j < start_col + 3; ++j)
    if (_game[i][j].value)
      ++m[_game[i][j].value];

  int conflict = 0;
 
  for (const auto &[key, value] : m)
    if (value > 1)
      conflict = key;

  if (conflict)
    for (auto i = start_row; i < start_row + 3; ++i)
      for(auto j = start_col; j < start_col + 3; ++j)
        if (_game[i][j].value == conflict && _game[i][j].user && !_game[i][j].faulty) {
          ++num_of_conflicts;
          _game[i][j].faulty = true;
          break;
        }
}

void sudoku::validate() {
  for (auto i = 0; i < 9; ++i)
    check_row(i);

  for (auto i = 0; i < 9; ++i)
    check_col(i);

  for (auto i = 0; i < 9; i += 3)
    for (auto j = 0; j < 9; j += 3)
      check_submatrix(i, j);
}

void sudoku::validate(int row, int col) {
  check_row(row);
  check_col(col);

  int row_to_check;
  int col_to_check;

  if (row < 3)
    row_to_check = 0;

  else if (row >= 3 && row < 6)
    row_to_check = 3;

  else if (row >= 6 && row < 9)
    row_to_check = 6;

  if (col < 3)
    col_to_check = 0;

  else if (col >= 3 && col < 6)
    col_to_check = 3;

  else if (col >= 6 && col < 9)
    col_to_check = 6;

  check_submatrix(row_to_check, col_to_check);
}

bool sudoku::won() {
  return !num_of_conflicts && num_of_nzero_cells == 81;
}
