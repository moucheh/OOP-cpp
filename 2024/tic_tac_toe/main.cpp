#include "TicTacToe.hpp"
using std::cout, std::endl;

int main() {
	TicTacToe game;
	while (true) {
		game.draw_board();
		game.play();
		if (game.get_win_state()) {
			game.draw_board();
			cout << "Game finished, "
				 << ((game.get_player() == 'X') ? 'O' : 'X')
				 << " won!" << endl;
			break;
		}
		if (!game.get_win_state() && game.get_counter() == 9) {
			game.draw_board();
			cout << "Game finished in a draw!" << endl;
			break;
		}
	}
	return 0;
}