#include <stdio.h>
#include "board.h"
#include "player.h"
#include "ai.h"
#include "game.h"

void InitBoard(int Board[MAXBOARD][MAXBOARD][NOFPOS]){

  	int *AuxBoard = &Board[0][0][0];
  	int Counter = 0;

  	while(Counter < (MAXBOARD*MAXBOARD*NOFPOS)){
      	*AuxBoard = EMPTY;
      	++AuxBoard;
      	++Counter;
  	}
}

void PrintBoard(int Board[MAXBOARD][MAXBOARD][NOFPOS]){

	int Counter0 = 0;

	while(Counter0 < MAXBOARD){
		int Counter1 = 0;
      	while (Counter1 < MAXBOARD){
			int Counter2 = NOFPOS - 1;
			while (Counter2 >= 0){
				if((Counter2 == 0) && (Counter1 != MAXBOARD - 1)){
					if(Board[Counter0][Counter1][Counter2] == -1){
						printf(" |");
						--Counter2;
					}else{
			        	printf("%d|", Board[Counter0][Counter1][Counter2]);
		        		--Counter2;
					}
				}else{
					if((Counter2 == 0) && (Counter1 == MAXBOARD - 1)){
						if(Board[Counter0][Counter1][Counter2] == -1){
							printf(" ");
							--Counter2;
						}else{
				        	printf("%d", Board[Counter0][Counter1][Counter2]);
			        		--Counter2;
						}
					}else{
						if(Board[Counter0][Counter1][Counter2] == -1){
							printf(" ");
							--Counter2;
						}else{
					 		printf("%d", Board[Counter0][Counter1][Counter2]);
			        		--Counter2;
						}
					}
				}
	      	}
			++Counter1;
      	}
		if(Counter0 != MAXBOARD - 1){
			printf("\n--------------------\n");
		}else{
			printf("\n");
		}
		++Counter0;
  	}
}

int AnyWinner(int Board[MAXBOARD][MAXBOARD][NOFPOS], int CurrentPlayer){

	int i = 0;
	int j = 0;
	int k = 0;
	int Result = TRUE;

	//Horizontal win
	while (i < MAXBOARD){
		k = 0;
		while (k < NOFPOS){
			j = 0;
	      	Result = TRUE;
			while(j < MAXBOARD - 1){
				if(((Board[i][j][k] == Board[i][j + 1][k]) && Board[i][j][k] != EMPTY) && (Result == TRUE)){
					Result = TRUE;
				}
				if((((Board[i][j][k] == Board[i][j + 1][k]) && Board[i][j][k] == EMPTY)) || (Board[i][j][k] != Board[i][j + 1][k])){
					Result = FALSE;
				}
				if(((Board[i][j][k] == Board[i][j + 1][k]) && Board[i][j][k] != EMPTY) && (Result == FALSE)){
					Result = FALSE;
				}
				++j;
			}
			if(Result == TRUE){
				return CurrentPlayer;
			}
			++k;
		}
		++i;
	}

	//Vertical win
	if(Result == FALSE){
	    j = 0;
		while (j < MAXBOARD){
		   	k = 0;
		    while (k < NOFPOS){
			   	i = 0;
		      	Result = TRUE;
				while(i < MAXBOARD - 1){
			      	if(((Board[i][j][k] == Board[i + 1][j][k]) && Board[i][j][k] != EMPTY) && (Result == TRUE)){
						Result = TRUE;
			    	}
			      	if((((Board[i][j][k] == Board[i + 1][j][k]) && (Board[i][j][k] == EMPTY)) || (Board[i][j][k] != Board[i + 1][j][k]))){
						Result = FALSE;
			    	}
					if(((Board[i][j][k] == Board[i + 1][j][k]) && Board[i][j][k] != EMPTY) && (Result == FALSE)){
						Result = FALSE;
					}
					++i;
				}
				if(Result == TRUE){
					return CurrentPlayer;
				}
		      	++k;
		    }
		    ++j;
		}

	    //Main diagonal win
	    if(Result == FALSE){
			k = 0;
			while(k < NOFPOS){
				i = 0;
		      	Result = TRUE;
		      	while(i < MAXBOARD - 1){
				    if(((Board[i][i][k] == Board[i + 1][i + 1][k]) && Board[i][i][k] != EMPTY) && (Result == TRUE)){
						Result = TRUE;
		        	}
		        	if(((Board[i][i][k] == Board[i + 1][i + 1][k]) && Board[i][i][k] == EMPTY) || (Board[i][i][k] != Board[i + 1][i + 1][k])){
						Result = FALSE;
		        	}
					if(((Board[i][j][k] == Board[i + 1][i + 1][k]) && Board[i][i][k] != EMPTY) && (Result == FALSE)){
						Result = FALSE;
					}
		        	++i;
		      	}
				if(Result == TRUE){
					return CurrentPlayer;
				}
				++k;
			}

	      	//Antidiagonal diagonal win
	      	if(Result == 0){
				k = 0;
				while(k < NOFPOS){
					i = 0;
	        		j = MAXBOARD - 1;
		        	Result = TRUE;
		        	while (j > 0) {

		          		if(((Board[i][j][k] == Board[i + 1][j - 1][k]) && Board[i][j][k] != EMPTY) && (Result == TRUE)){
		            		Result = TRUE;
		          		}
		          		if(((Board[i][j][k] == Board[i + 1][j - 1][k]) && Board[i][j][k] == EMPTY) || (Board[i][j][k] != Board[i + 1][j - 1][k])){
		            		Result = FALSE;
		          		}
						if(((Board[i][j][k] == Board[i + 1][j - 1][k]) && Board[i][j][k] != EMPTY) && (Result == FALSE)){
							Result = FALSE;
						}
		          		i++;
		          		j--;
		        	}
					if(Result == TRUE){
						return CurrentPlayer;
					}
					++k;
				}
				return FALSE;
	      	}
			return FALSE;
	    }
		return FALSE;
	}
	return FALSE;
}

void InitArray(int Array[MAXBOARD*MAXBOARD]){

  	int Counter = 0;
  	int *PArray = &Array[0];

  	while(Counter < MAXBOARD*MAXBOARD){
    	*PArray = -1;
		++PArray;
    	++Counter;
  	}
}

int OccupiedPos(int Moves[MAXBOARD*MAXBOARD], char Position){

  	int Counter = 0;
  	char NewPos = '0';
	int AuxPos = -1;

	AuxPos = DecConversion(Position);
	++AuxPos;

  	while(Counter < (MAXBOARD*MAXBOARD)){
      	if(Moves[Counter] == AuxPos){
        	printf("This position is already occupied; choose another one: ");
        	scanf(" %c", &NewPos);
        	AuxPos = OccupiedPos(Moves, NewPos);
        	return AuxPos;
      	}
      	Counter++;
  	}
  	return AuxPos;
}

int DecConversion(char HexNumber){

	int Converted = -1;
	char AuxConv = '0';

	if(HexNumber >= '0' && HexNumber <= '9'){
		Converted = HexNumber - '0';
		return Converted;
	}else{
		if(HexNumber >= 'a' && HexNumber <= 'f'){
			Converted = HexNumber - 'a' + 10;
			return Converted;
		}else{
			if(HexNumber >= 'A' && HexNumber <= 'F'){
				Converted = HexNumber - 'A' + 10;
				return Converted;
			}else{
				printf("Invalid number; type in again: ");
				scanf(" %c", &AuxConv);
				Converted = DecConversion(AuxConv);
				return Converted;
			}
		}
	}
}

char HexConversion(int ConvNumber){

	char Hex = '0';

	if(ConvNumber >= 0 && ConvNumber <= 9){
		Hex = ConvNumber + '0';
		return Hex;
	}
	Hex = ConvNumber + 'A' - 10;
	return Hex;
}

void Convert2BinAndPut(int Board[MAXBOARD][MAXBOARD][NOFPOS], int i, int j, int Number){

	int Counter = 0;
	int AuxNumber = Number;

	if(Number != EMPTY){
		while(Counter < NOFPOS){
			Board[i][j][Counter] = AuxNumber % 2;
			AuxNumber = AuxNumber / 2;
			++Counter;
		}
	}else{
		while(Counter < NOFPOS){
			Board[i][j][Counter] = EMPTY;
			++Counter;
		}
	}
}

void PutNumber(int Board[MAXBOARD][MAXBOARD][NOFPOS], int Position, int Number){

	int NewPos = Position;
  	int i = -1;
  	int j = -1;

	while((Position < 1) || (Position > MAXBOARD*MAXBOARD)){
	    printf("Invalid position; choose another one: ");
	    scanf("%d", &NewPos);
	    Position = NewPos;
	}

	i = (NewPos - 1)/MAXBOARD;
	j = NewPos - MAXBOARD*i - 1;

	Convert2BinAndPut(Board, i, j, Number);
}

int CheckAndPut(int Board[MAXBOARD][MAXBOARD][NOFPOS], int PlayedNumbers[MAXBOARD*MAXBOARD], int Moves[MAXBOARD*MAXBOARD], int CurrentPlayer, int Number){

	char Position = '0';
	int AuxPos = -1;

	Number = CheckNumber(PlayedNumbers, Number);
	printf("(Player %d) Choose a position from 0 - F: ", WhichPlayer(CurrentPlayer));
	scanf(" %c", &Position);
	AuxPos = OccupiedPos(Moves, Position);
	PutNumber(Board, AuxPos, Number);
	PrintBoard(Board);

	return AuxPos;
}

int CheckNumber(int PlayedNumbers[MAXBOARD*MAXBOARD], int Number){

	int Counter = 0;
  	char NewNumber = '0';
	int ConvNumber = 0;

	if((Number >= 0) && (Number < MAXBOARD*MAXBOARD)){
		while (Counter < (MAXBOARD*MAXBOARD)){
	      	if(PlayedNumbers[Counter] == Number){
	        	printf("This number has been played already; choose another one: ");
	        	scanf(" %c", &NewNumber);
				ConvNumber = DecConversion(NewNumber);
	        	ConvNumber = CheckNumber(PlayedNumbers, ConvNumber);
	        	return ConvNumber;
	      	}
	      	Counter++;
	  	}
	  	return Number;
	}
	while((Number < 0) || (Number >= MAXBOARD*MAXBOARD)){
	    printf("Invalid number; choose another one: ");
		scanf(" %c", &NewNumber);
		ConvNumber = DecConversion(NewNumber);
		ConvNumber = CheckNumber(PlayedNumbers, ConvNumber);
		return ConvNumber;
	}
	return Number;

}
