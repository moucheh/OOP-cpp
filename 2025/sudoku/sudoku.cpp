#include "sudoku.hpp"
#include <map>
#include <sstream>
#include <string>

sudoku::sudoku() : _game(9), num_of_nzero_cells(0), num_of_conflicts(0) {
  for (auto &row : _game)
    row.resize(9, {0, false, false, false});

  const std::string plus(1, '+');
  const std::string minus(3, '-');
  const std::string sub_separator =
      plus + minus + plus + minus + plus + minus + plus;

  separator = sub_separator + sub_separator + sub_separator;
}

void sudoku::readPuzzle(std::istream &is) {
  for (auto &row : _game)
    for (auto &col : row) {
      is >> col.value;
      if (col.value) {
        col.readonly = true;
        ++num_of_nzero_cells;
      }
    }
}

void sudoku::print(std::ostream &os) {
  os << std::endl
     << "Cells filled: " << num_of_nzero_cells
     << "/81, conflicts: " << num_of_conflicts << std::endl;

  const auto check_if_multiple_of_3_or_last = [](int val) {
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

  std::cout << "Enter your move in one line(val: 1-9, row: 1-9, col: 1-9): ";

  int value, row, col;

  std::string input;

  std::getline(std::cin, input);

  std::istringstream is(input);

  is >> value;

  if (check_range(value) && value != 0) {
    std::cout << "Invalid value, 1 through 9 only allowed, or 0 for erase!"
              << std::endl;
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

  if (value == 0) {
    if (target_cell.value)
      --num_of_nzero_cells;

    target_cell.value = 0;
    target_cell.user = false;
    validate(row - 1, col - 1);
    return;
  }

  if (!target_cell.value && target_cell.value != value)
    ++num_of_nzero_cells;

  target_cell.value = value;
  target_cell.user = true;

  validate(row - 1, col - 1);
}

bool sudoku::check_row(int row) {
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
      if (cell.value == conflict && !cell.faulty) {
        cell.faulty = true;
        ++num_of_conflicts;
      }
  }
  return conflict;
}

bool sudoku::check_col(int col) {
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
      if (row[col].value == conflict && !row[col].faulty) {
        row[col].faulty = true;
        ++num_of_conflicts;
      }
  }
  return conflict;
}

bool sudoku::check_submatrix(int start_row, int start_col) {
  std::map<int, int> m;

  for (auto i = start_row; i < start_row + 3; ++i)
    for (auto j = start_col; j < start_col + 3; ++j)
      if (_game[i][j].value)
        ++m[_game[i][j].value];

  int conflict = 0;

  for (const auto &[key, value] : m)
    if (value > 1)
      conflict = key;

  if (conflict)
    for (auto i = start_row; i < start_row + 3; ++i)
      for (auto j = start_col; j < start_col + 3; ++j)
        if (_game[i][j].value == conflict && !_game[i][j].faulty) {
          ++num_of_conflicts;
          _game[i][j].faulty = true;
        }
  return conflict;
}

void sudoku::validate(int row, int col) {
  auto [srow, scol] = get_submatrix_start_indexes(col, col);

  bool res1 = check_row(row);
  bool res2 = check_col(col);
  bool res3 = check_submatrix(srow, scol);

  if (!res1 && !res2 && !res3)
    remove_conflicts(row, col);
}

bool sudoku::won() { return !num_of_conflicts && num_of_nzero_cells == 81; }

void sudoku::remove_conflicts(int row, int col) {
  if (row < 0 || row > 9)
    return;
  if (col < 0 || col > 9)
    return;

  for (auto &cell : _game[row]) {
    if (cell.faulty)
      --num_of_conflicts;
    cell.faulty = false;
  }

  for (auto &row : _game) {
    if (row[col].faulty)
      --num_of_conflicts;
    row[col].faulty = false;
  }

  auto [srow, scol] = get_submatrix_start_indexes(row, col);

  for (auto i = srow; i < srow + 3; ++i)
    for (auto j = scol; j < scol + 3; ++j) {
      if (_game[i][j].faulty)
        --num_of_conflicts;
      _game[i][j].faulty = false;
    }
}

std::pair<int, int> sudoku::get_submatrix_start_indexes(int row, int col) {
  int srow;
  int scol;

  if (row < 3)
    srow = 0;

  else if (row >= 3 && row < 6)
    srow = 3;

  else if (row >= 6 && row < 9)
    srow = 6;

  if (col < 3)
    scol = 0;

  else if (col >= 3 && col < 6)
    scol = 3;

  else if (col >= 6 && col < 9)
    scol = 6;

  return {srow, scol};
}
