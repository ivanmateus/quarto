#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "player.h"
#include "ai.h"
#include "game.h"

int main(void){

	void InitBoard(int Board[MAXBOARD][MAXBOARD][NOFPOS]);
	void Quarto(int Board[MAXBOARD][MAXBOARD][NOFPOS]);

	int Board[MAXBOARD][MAXBOARD][NOFPOS];
	InitBoard(Board);

	Quarto(Board);

	return 0;
}
