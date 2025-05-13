#include "TicTacToe.hpp"
using std::cout, std::endl;

int main() {
	Board game;
	u_int_16 choice = game.menu();
	while (choice != 1 && choice != 2 && choice != 3) {
		cout << "Invalid input, your options are 1, 2 and 3!\n";
		choice = game.menu();
	}
	game.set_game_mode(choice);
	for (auto i = 0; i < 9; i++) {
		if (game.get_current_player() != &game.get_cpu())
			game.draw_board(game.get_current_player()->symbol);
		game.get_current_player()->play();
		if (game.get_win_state()) {
			game.draw_board(game.get_current_player()->symbol);
			cout << "Game finished, "
				 << game.get_current_player()->symbol
				 << " won!" << endl;
			break;
		}
		if (!game.get_win_state() && game.get_counter() == 9) {
			game.draw_board(' ');
			cout << "Game finished in a draw!" << endl;
		}
		game.swap_player()();
	}
	return 0;
}