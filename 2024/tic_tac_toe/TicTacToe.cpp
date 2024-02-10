#include "TicTacToe.hpp"
using std::cout, std::cin, std::endl;

void fix_cin() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void TicTacToe::draw_board() const {
	if (!get_win_state() && counter != 9)
		cout << current_player << "'s turn\n";
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

void TicTacToe::play() {
	u_int_16 row{}, col{};
	request_player_input(row, col);
	while (!update_board(row, col)) {
		cout << "Invalid move!\n";
		request_player_input(row, col);
	}
	change_player();
	check_win_state('X');
	check_win_state('O');
	++counter;
}

void TicTacToe::request_player_input(u_int_16& row, u_int_16& col) const {
	cout << "Enter row and column(0-2): ";
	input_number(row);
	input_number(col);
}

void TicTacToe::input_number(u_int_16& input) const {
	while (!(cin >> input)) {
		fix_cin();
		cout << "Invalid input!\nEnter new value(0-2): ";
	}
}

bool TicTacToe::update_board(u_int_16 row, u_int_16 col) {
	if (board[row][col] == '.') {
		board[row][col] = current_player;
		return true;
	}
	return false;
}

void TicTacToe::change_player() {
	if (current_player == 'X') {
		current_player = 'O';
		return;
	}
	current_player = 'X';
}

void TicTacToe::check_win_state(char player) {
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