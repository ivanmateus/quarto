#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "player.h"
#include "ai.h"
#include "game.h"

int main(int argc, char *argv[]){

	void InitBoard(int Board[MAXBOARD][MAXBOARD][NOFPOS]);
	int Board[MAXBOARD][MAXBOARD][NOFPOS];
	InitBoard(Board);

	if(argc == 1){
		void Quarto(int Board[MAXBOARD][MAXBOARD][NOFPOS]);

		Quarto(Board);
		return 0;
	}else{
		if(strcmp (argv[1], "-test") == 0){
		void Test(int Board[MAXBOARD][MAXBOARD][NOFPOS]);

		Test(Board);
		return 0;
		}
	}
	return 0;
}

