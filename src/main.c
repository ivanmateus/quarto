#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
			
			int AIMovewMiniMax(int Board[MAXBOARD][MAXBOARD][NOFPOS], int Number, int NumberArray[MAXBOARD*MAXBOARD], int PlayedNumbers[MAXBOARD*MAXBOARD], int NofPlydNbrs);
			void PutNumber(int Board[MAXBOARD][MAXBOARD][NOFPOS], int Position, int Number);
			void PrintBoard(int Board[MAXBOARD][MAXBOARD][NOFPOS]);			
			int NumberArray[MAXBOARD*MAXBOARD];
			int PlayedNumbers[MAXBOARD*MAXBOARD];
			int Position = -1;
			int NofPNumbers = 0;	
			NArray(NumberArray);
			InitArray(PlayedNumbers);
			
			printf("Test input:\n\n");

			PutNumber(Board, 1, 0);
			PutNumber(Board, 2, 1);
			PutNumber(Board, 5, 2);
			PutNumber(Board, 6, 15);
			PutNumber(Board, 12, 10);
			PutNumber(Board, 4, 13);
			NofPNumbers = 6;
			PlayedNumbers[0] = 0;
			PlayedNumbers[1] = 1;
			PlayedNumbers[2] = 2;
			PlayedNumbers[3] = 15;
			PlayedNumbers[4] = 10;
			PlayedNumbers[5] = 13;
			PrintBoard(Board);
			
			printf("\nChecking for the optimized position:\n\n");
			
			Position = AIMovewMiniMax(Board, 3, NumberArray, PlayedNumbers, NofPNumbers);
			PutNumber(Board, Position, 3);
			PrintBoard(Board);

			return 0;
		}
	}
	return 0;
}
