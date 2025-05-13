#pragma once
#include "iostream"
#include <array>
#include <string>
#include <limits>

using u_int_16 = unsigned short;
using matrix = std::array<std::array<char, 3>, 3>;

void fix_cin();

class TicTacToe {
public:
	void draw_board() const;
	void play();
	bool get_win_state() const { return win_state; }
	char get_player() const { return current_player; }
	u_int_16 get_counter() const { return counter; }
private:
	void change_player();

	static void request_player_input(u_int_16& row, u_int_16& col);

	static void input_number(u_int_16& input);

	bool update_board(u_int_16 row, u_int_16 col);

	void check_win_state(char player);
private:
	matrix board{'.', '.', '.', '.', '.', '.', '.', '.', '.'};
	char current_player{'X'};
	bool win_state{false};
	u_int_16 counter{};
};