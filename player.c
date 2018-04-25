#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "player.h"
#include "ai.h"
#include "game.h"

int WhichPlayer(int Player){
	if(Player == P1){
		return 1;
	}else{
		return 2;
	}
}

int TypeNext(int CurrentPlayer, int NumberofMoves, int PlayedNumbers[MAXBOARD*MAXBOARD]){

	char HexNumber = '0';

	if(NumberofMoves == 0){
		printf("(Player %d) Type in the first number in hexadecimal: ", WhichPlayer(CurrentPlayer));
		scanf(" %c", &HexNumber);
		int ConvertedNumber = DecConversion(HexNumber);
		ConvertedNumber = CheckNumber(PlayedNumbers, ConvertedNumber);
		return ConvertedNumber;
	}else{
		printf("(Player %d) Type in the next number in hexadecimal: ", WhichPlayer(CurrentPlayer));
		scanf(" %c", &HexNumber);
		int ConvertedNumber = DecConversion(HexNumber);
		ConvertedNumber = CheckNumber(PlayedNumbers, ConvertedNumber);
		return ConvertedNumber;
	}
}
