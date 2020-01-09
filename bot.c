#include <stdio.h>
#include "board.h"


int testScore(board game, player pl, int max){
	int score = 0;

	player winner = get_winner(game);
	if (winner == pl){
		score += 10;
	}
	else if (winner == next_player(pl)){
		score -= 10;
	}

	for (int i = 0; i < 3; i++){
		
	}

	return score;
}


int testMove(board game, player pl, int depth, int max){
	int score;

	if (depth){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (get_place_holder(game, i, j) != pl){
					if (get_piece_size(game, i, j) < 3){
						for (int k = 1; k <= 3; k++){
							board test = copy_game(game);

							if (place_piece(test, pl, k, i, j)){
								score = testMove(test, next_player(pl), depth-1, 1-max);
								
							}

							destroy_game(test);
						}
					}
				}
				//else --> déplacement
			}
		}

		int new_score = testScore(game, pl, max);
		if (new_score > score)
			score = new_score;
	}
	else{
		score = testScore(game, pl, max);
	}

	return score;
}


int botPlay(board game, player pl){
	int depth = 2;
	testMove(game, pl, depth, 1);

	return 0;
}
