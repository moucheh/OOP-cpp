#include "TicTacToe.hpp"
#include <functional>
using std::cout, std::endl;

u_int_16 menu() {
	u_int_16 choice;
	cout << "Enter game mode: \n"
		 << "1. Player vs Player\n"
		 << "2. Player vs CPU\n"
		 << "Choice: ";
	TicTacToe::input_number(choice);
	return choice;
}

int main() {
	TicTacToe game;
	TicTacToe::Player* p = &game.get_player_one();
	u_int_16 choice = menu();
	std::function<void()> lambda;
	if (choice == 1)
		lambda = [&]() {
		if (p == &game.get_player_one())
			p = &game.get_player_two();
		else
			p = &game.get_player_one();
	};
	if (choice == 2) {
		lambda = [&]() {
			if (p == &game.get_player_one())
				p = &game.get_cpu();
			else
				p = &game.get_player_one();
		};
	}
	for (auto i = 0; i < 9; i++) {
		game.draw_board(p->symbol);
		p->play();
		if (game.get_win_state()) {
			game.draw_board(game.get_player_one().symbol);
			cout << "Game finished, "
				 << game.get_player_one().symbol
				 << " won!" << endl;
			break;
		}
		if (!game.get_win_state() && game.get_counter() == 9) {
			game.draw_board(' ');
			cout << "Game finished in a draw!" << endl;
		}
		lambda();
	}
	return 0;
}