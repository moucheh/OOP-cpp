#pragma once
#include <iostream>
#include <array>
#include <string>
#include <limits>
#include <random>
#include <cstdlib>
#include <ctime>
#include <functional>

using u_int_16 = unsigned short;
using matrix = std::array<std::array<char, 3>, 3>;

void fix_cin();

class Board {
public:
	struct Player {
		Player(char c, Board* p) : symbol{c}, ptr{p} {}
		char symbol;
		Board* ptr{nullptr};
		virtual void play() = 0;
		bool update_board(u_int_16 row, u_int_16 col);
		virtual ~Player() {}
	};

	struct HumanPlayer : Player {
		HumanPlayer(char c, Board* p) : Player{c, p} {}
		void play();
	};

	struct MachinePlayer : Player {
		MachinePlayer(char c, Board* p) : Player{c, p} {}
		void play();
	};

	void draw_board(char p) const;
	void play();
	bool get_win_state() const { return win_state; }
	matrix& get_board() { return board; }

	Player& get_player_one() { return player_one; }
	Player& get_player_two() { return player_two; }
	Player& get_cpu() { return cpu; }
	Player* get_current_player() { return current_player; }

	u_int_16 get_counter() const { return _counter; }

	u_int_16& counter() { return _counter; }

	void change_player();

	static void request_player_input(u_int_16& row, u_int_16& col);

	static void input_number(u_int_16& input);

	static u_int_16 menu();

	bool update_board(u_int_16 row, u_int_16 col);

	void check_win_state(char player);

	void set_game_mode(int g);

	std::function<void()>& swap_player() { return game_mode; }
private:
	matrix board{'.', '.', '.', '.', '.', '.', '.', '.', '.'};
	HumanPlayer player_one{'X', this};
	HumanPlayer player_two{'O', this};
	MachinePlayer cpu{'O', this};
	bool win_state{false};
	u_int_16 _counter{};
	std::function<void()> game_mode;
	Player* current_player{&get_player_one()};
};

