#include "TicTacToe.hpp"
using std::cout, std::cin, std::endl;

void fix_cin() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

u_int_16 Board::menu() {
	u_int_16 choice;
	cout << "Enter game mode: \n"
		 << "1. Player vs Player\n"
		 << "2. Player vs CPU\n"
		 << "3. CPU vs Player\n"
		 << "Choice: ";
	Board::input_number(choice);
	return choice;
}

void Board::set_game_mode(int g) {
	if (g == 1)
		swap_player() = [&]() {
		if (current_player == &get_player_one())
			current_player = &get_player_two();
		else
			current_player = &get_player_one();
	};
	if (g == 2)
		swap_player() = [&]() {
		if (current_player == &get_player_one())
			current_player = &get_cpu();
		else
			current_player = &get_player_one();
	};
	if (g == 3) {
		current_player = &get_cpu();
		cpu.symbol = 'X';
		player_two.symbol = 'O';
		swap_player() = [&]() {
			if (current_player == &get_cpu())
				current_player = &get_player_two();
			else
				current_player = &get_cpu();
		};
	}
}


void Board::draw_board(char p) const {
	cout << '\n';
	if (!get_win_state() && _counter != 9)
		cout << p << "'s turn\n";
	cout << "  " << std::string(15, '-') << '\n';
	for (auto i = 0; i < 3; i++) {
		cout << i << ": | ";
		for (auto j = 0; j < 3; j++) {
			cout << board[i][j] << " | ";
		}
		cout << "\n  " << std::string(15, '-') << '\n';
	}
	cout << "     0   1   2" << endl;
}

void Board::HumanPlayer::play() {
	u_int_16 row{}, col{};
	request_player_input(row, col);
	while (!update_board(row, col)) {
		cout << "Invalid move!\n";
		request_player_input(row, col);
	}
	ptr->check_win_state(symbol);
	++ptr->counter();
}

void Board::MachinePlayer::play() {
	srand(time(NULL));
	u_int_16 row, col;
	do {
		row = rand() % 3;
		col = rand() % 3;
	} while (!update_board(row, col));
	ptr->check_win_state(symbol);
	++ptr->counter();
}

void Board::request_player_input(u_int_16& row, u_int_16& col) {
	cout << "Enter row and column(0-2): ";
	input_number(row);
	input_number(col);
}

void Board::input_number(u_int_16& input) {
	while (!(cin >> input)) {
		fix_cin();
		cout << "Invalid input!\nEnter new value(0-2): ";
	}
}

bool Board::Player::update_board(u_int_16 row, u_int_16 col) {
	if (ptr->get_board()[row][col] == '.') {
		ptr->get_board()[row][col] = symbol;
		return true;
	}
	return false;
}

void Board::check_win_state(char player) {
	if (board[0][0] == board[0][1] &&
			board[0][1] == board[0][2] &&
			board[0][2] == player) {
		win_state = true;
	} else if (board[1][0] == board[1][1] &&
			   board[1][1] == board[1][2] &&
			   board[1][2] == player) {
		win_state = true;
	} else if (board[2][0] == board[2][1] &&
			   board[2][1] == board[2][2] &&
			   board[2][2] == player) {
		win_state = true;
	} else if (board[0][0] == board[1][0] &&
			   board[1][0] == board[2][0] &&
			   board[2][0] == player) {
		win_state = true;
	} else if (board[0][1] == board[1][1] &&
			   board[1][1] == board[2][1] &&
			   board[2][1] == player) {
		win_state = true;
	} else if (board[0][2] == board[1][2] &&
			   board[1][2] == board[2][2] &&
			   board[2][2] == player) {
		win_state = true;
	} else if (board[0][0] == board[1][1] &&
			   board[1][1] == board[2][2] &&
			   board[2][2] == player) {
		win_state = true;
	} else if (board[0][2] == board[1][1] &&
			   board[1][1] == board[2][0] &&
			   board[2][0] == player) {
		win_state = true;
	}
}