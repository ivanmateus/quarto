#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "player.h"
#include "ai.h"
#include "game.h"

int main(int argc, char **argv){

	void InitBoard(int Board[MAXBOARD][MAXBOARD][NOFPOS]);
	int Board[MAXBOARD][MAXBOARD][NOFPOS];
	InitBoard(Board);
	
	if(argc == 1){
		void Quarto(int Board[MAXBOARD][MAXBOARD][NOFPOS]);
		
		Quarto(Board);
		return 0;
	}else{
		if(strcmp(argv[1], ¨-test¨) == 0){
			int AIMovewMiniMax(Board[MAXBOARD][MAXBOARD][NOFPOS], int Number, int NumberArray[MAXBOARD*MAXBOARD], int PlayedNumbers[MAXBOARD*MAXBOARD], int NofPlydNbrs)
			int NumberArray[MAXBOARD*MAXBOARD];
			int PlayedNumbers[MAXBOARD*MAXBOARD];
			int Position = -1;
			int NofPNumbers = 0;
				
			NArray(NumberArray);
			InitArray(PlayedNumbers);
			
			
			Position = AIMovewMiniMax(Board, Number, NumberArray, PlayedNumbers, NofPNumbers);
				
		}
	}

	return 0;
}
