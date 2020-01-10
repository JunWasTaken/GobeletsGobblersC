#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "board.h"


int testScore(board game, player pl){
	int score = 0;

	player winner = get_winner(game);
	if (winner == pl){
		score += 100;
	}
	else if (winner == next_player(pl)){
		score -= 100;
	}

	for (int i = 0; i < 3; i++){
		int cnt = 0;
		int placePl;
		for (int j = 0; j < 3; j++){
			placePl = get_place_holder(game, i, j);
			if (placePl == pl)
				cnt++;
			else if (placePl == next_player(pl))
				cnt--;
		}
		if (cnt > 1)
			score += cnt;
	}

	return score;
}


board testMove(board game, player pl, int depth){
	board newGame = new_game();

	if (depth){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (get_place_holder(game, i, j) != pl){
					if (get_piece_size(game, i, j) < 3){
						for (int k = 1; k <= 3; k++){
							board test = copy_game(game);
							if (place_piece(test, pl, k, i, j) == 0){
								int score = testScore(game, pl);

								test = testMove(test, next_player(pl), depth-1);
								int newScore = testScore(test, next_player(pl));
								
								if (newScore >= score){
									newGame = test;
								}
								else {
									destroy_game(test);
								}
							}
							else{
								newGame = game;
							}
						}
					}
				}
				//else --> déplacement
			}
		}
	}
	else{
		newGame = game;
	}

	return newGame;
}


int botPlay(board game, player pl){
	int depth = 2;
	srand(time(NULL));
	
	game = testMove(game, pl, depth);

	return 0;
}