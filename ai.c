#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ai.h"
#include "game.h"
#include "board.h"
#include "player.h"

int NotPlayedNumber(int NumberArray[MAXBOARD*MAXBOARD], int PlayedNumbers[MAXBOARD*MAXBOARD]){

	int Counter0 = 0;
	int Counter1 = 0;
	int NotPlayed = 0;

	while(Counter0 < MAXBOARD*MAXBOARD){
		Counter1 = 0;
		NotPlayed = 0;
		while((PlayedNumbers[Counter1] != EMPTY) && (Counter1 < MAXBOARD*MAXBOARD)){
			if((PlayedNumbers[Counter1] != NumberArray[Counter0]) && (NotPlayed != -1)){
				NotPlayed = NumberArray[Counter0];
			}else{
				NotPlayed = -1;
			}
			++Counter1;
		}
		if(NotPlayed != -1){
			return NotPlayed;
		}
		++Counter0;
	}
	return NotPlayed;
}

int BestMove(int Board[MAXBOARD][MAXBOARD][NOFPOS], int NumberArray[MAXBOARD*MAXBOARD], int NofPlydNbrs, int PlayedNumbers[MAXBOARD*MAXBOARD], int CurrentPlayer){

    int Winner = AnyWinner(Board, (-1)*CurrentPlayer);
    int Counter0 = 0;
    int Counter1 = 0;
	int NPlayed = NotPlayedNumber(NumberArray, PlayedNumbers);
    int i = -1;
    int j = -1;
    int Score = -2;

    if(Winner != 0){
        return Winner*CurrentPlayer;
    }

    while(Counter0 < MAXBOARD){
		Counter1 = 0;
        while(Counter1 < MAXBOARD){
	        if(Board[Counter0][Counter1][0] == EMPTY){
				Convert2BinAndPut(Board, Counter0, Counter1, NPlayed);
				PlayedNumbers[NofPlydNbrs] = NPlayed;
				++NofPlydNbrs;
	            int TempScore = (-1)*BestMove(Board, NumberArray, NofPlydNbrs, PlayedNumbers, (-1)*CurrentPlayer);
				--NofPlydNbrs;
				PlayedNumbers[NofPlydNbrs] = EMPTY;
	        	Convert2BinAndPut(Board, Counter0, Counter1, EMPTY);
	            if(TempScore > Score){
	                Score = TempScore;
	                i = Counter0;
	                j = Counter1;
	            }
			}
            Counter1++;
        }
        Counter0++;
    }
    if((i == -1) && (j == -1)){
        return 0;
    }
    return Score;
}

void GetEmptyPosition(int Board[MAXBOARD][MAXBOARD][NOFPOS], int EmptyPosits[MAXBOARD*MAXBOARD]){

	int Counter0 = 0;
	int Counter1 = 0;
	int Counter2 = 0;
	int TempPos = -1;
	InitArray(EmptyPosits);

	while(Counter0 < MAXBOARD){
		Counter1 = 0;
		while(Counter1 < MAXBOARD){
			if(Board[Counter0][Counter1][0] == -1){
				TempPos = Counter1 + MAXBOARD*Counter0 + 1;
				EmptyPosits[Counter2] = TempPos;
				++Counter2;
			}
			++Counter1;
		}
		++Counter0;
	}
}

void NotPlayedArray(int NumberArray[MAXBOARD*MAXBOARD], int PlayedNumbers[MAXBOARD*MAXBOARD], int NotPlayed[MAXBOARD*MAXBOARD]){

	int Counter0 = 0;
	int Counter1 = 0;
	int Counter2 = 0;
	int NPlayed = -1;
	InitArray(NotPlayed);

	while(Counter0 < MAXBOARD*MAXBOARD){
		Counter1 = 0;
		NPlayed = -1;
		while((PlayedNumbers[Counter1] != NumberArray[Counter0]) && (Counter1 < MAXBOARD*MAXBOARD)){
			NPlayed = NumberArray[Counter0];
			++Counter1;
		}
		if((PlayedNumbers[Counter1] == -1) || (Counter1 == MAXBOARD*MAXBOARD)){
			NotPlayed[Counter2] = NPlayed;
			printf("nplayed %d\n", NPlayed);
			++Counter2;
		}
		++Counter0;
	}
}

void ConvertToArray(int NumberArray[NOFPOS], int Number){

	int Counter = 0;
	int AuxNumber = Number;

	while(Counter < NOFPOS){
		NumberArray[Counter] = AuxNumber % 2;
		AuxNumber = AuxNumber / 2;
		++Counter;
	}
}

int CheckMaxScore(int Board[MAXBOARD][MAXBOARD][NOFPOS], int Number){

	int EmptyPos[MAXBOARD*MAXBOARD];
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int m = 0;
	int x = -1;
	int y = -1;
	int Counter0 = 0;
	int TempScore = 0;
	int Score = -1;
	GetEmptyPosition(Board, EmptyPos);

	while(EmptyPos[Counter0] != EMPTY && Counter0 < MAXBOARD*MAXBOARD){
		x = ((EmptyPos[Counter0]) - 1)/MAXBOARD;
		y = (EmptyPos[Counter0]) - MAXBOARD*x - 1;
		Convert2BinAndPut(Board, x, y, Number);

		//Horizontal win
		k = 0;
		while (k < NOFPOS){
			j = 0;
			TempScore = 0;
			while(j < MAXBOARD - 1){
				l = j;
				m = l;
				if(TempScore == 0){
					while(m < MAXBOARD - 1){
						if((Board[x][l][k] == Board[x][m + 1][k]) && (Board[x][l][k] != EMPTY) && (Board[x][m + 1][k] != EMPTY)){
							++TempScore;
						}
						++m;
					}
				}
				++j;
			}
			if(TempScore == MAXBOARD - 1){
				Convert2BinAndPut(Board, x, y, EMPTY);
				return TempScore;
			}
			if((Score == -1) || ((TempScore > Score))){
				Score = TempScore;
			}
			++k;
		}

		//Vertical win
		k = 0;
		while (k < NOFPOS){
		   	i = 0;
			TempScore = 0;
			while(i < MAXBOARD - 1){
				l = i;
				m = l;
				if(TempScore == 0){
					while(m < MAXBOARD - 1){
						if((Board[l][y][k] == Board[m + 1][y][k]) && (Board[l][y][k] != EMPTY) && (Board[m + 1][y][k] != EMPTY)){
							++TempScore;
						}
						++m;
					}
				}
				++i;
			}
			if(TempScore == MAXBOARD - 1){
				Convert2BinAndPut(Board, x, y, EMPTY);
				return TempScore;
			}
			if((Score == -1) || ((TempScore > Score))){
				Score = TempScore;
			}
		    ++k;
		}

		//Main diagonal win
		if(x == y){
			k = 0;
			while(k < NOFPOS){
				i = 0;
				TempScore = 0;
			   	while(i < MAXBOARD - 1){
					l = i;
					m = l;
					if(TempScore == 0){
						while(m < MAXBOARD - 1){
							if((Board[l][l][k] == Board[m + 1][m + 1][k]) && (Board[l][l][k] != EMPTY) && (Board[m + 1][m + 1][k] != EMPTY)){
								++TempScore;
							}
							++m;
						}
					}
				   	++i;
				}
				if(TempScore == MAXBOARD - 1){
					Convert2BinAndPut(Board, x, y, EMPTY);
					return TempScore;
				}
				if((Score == -1) || ((TempScore > Score))){
					Score = TempScore;
				}
				++k;
			}
		}

	   	//Antidiagonal diagonal win
		if(x + y == MAXBOARD - 1){
			k = 0;
			while(k < NOFPOS){
				i = 0;
				j = MAXBOARD - 1;
				TempScore = 0;
				while (j > 0){
					l = i;
					m = j;
					int n = i;
					int o = j;
					if(TempScore == 0){
						while(m > 0){
							if((Board[n][o][k] == Board[l + 1][m - 1][k]) && (Board[n][o][k] != EMPTY) && (Board[l + 1][m - 1][k] != EMPTY)){
								++TempScore;
							}
							++l;
							--m;
						}
					}
				    i++;
				    j--;
				}
				if(TempScore == MAXBOARD - 1){
					Convert2BinAndPut(Board, x, y, EMPTY);
					return TempScore;
				}
				if((Score == -1) || ((TempScore > Score))){
					Score = TempScore;
				}
				++k;
			}
		}
		++Counter0;
		Convert2BinAndPut(Board, x, y, EMPTY);
	}
	return Score;
}

int AIMove(int Board[MAXBOARD][MAXBOARD][NOFPOS], int Number, int NumberArray[MAXBOARD*MAXBOARD], int PlayedNumbers[MAXBOARD*MAXBOARD], int NofPlydNbrs){

	int EmptyPos[MAXBOARD*MAXBOARD];
	int Counter0 = 0;
	int TempScore = -1;
	int Score = -1;
	int i = -1;
	int j = -1;
	int x = -1;
	int y = -1;
	GetEmptyPosition(Board, EmptyPos);

	while(EmptyPos[Counter0] != EMPTY && Counter0 < MAXBOARD*MAXBOARD){
		x = ((EmptyPos[Counter0]) - 1)/MAXBOARD;
		y = (EmptyPos[Counter0]) - MAXBOARD*x - 1;
		TempScore = CheckMaxScore(Board, Number);
		if(TempScore > Score){
			Score = TempScore;
			i = x;
			j = y;
		}
		++Counter0;
	}
	Convert2BinAndPut(Board, i, j, Number);
	return (j + MAXBOARD*i + 1);
}

int AIMovewMiniMax(int Board[MAXBOARD][MAXBOARD][NOFPOS], int Number, int NumberArray[MAXBOARD*MAXBOARD], int PlayedNumbers[MAXBOARD*MAXBOARD], int NofPlydNbrs){

	int Counter0 = 0;
	int Counter1 = 0;
	int TempScore = -1;
	int Score = -2;
	int i = -1;
	int j = -1;

	int Counter = 0;
	while(Counter < MAXBOARD*MAXBOARD){
		++Counter;
	}

	while(Counter0 < MAXBOARD){
		Counter1 = 0;
        while(Counter1 < MAXBOARD){
	        if(Board[Counter0][Counter1][0] == EMPTY){
				Convert2BinAndPut(Board, Counter0, Counter1, Number);
				PlayedNumbers[NofPlydNbrs] = Number;
				++NofPlydNbrs;
	            TempScore = (-1)*BestMove(Board, NumberArray, NofPlydNbrs, PlayedNumbers, (-1)*AI);
				--NofPlydNbrs;
				PlayedNumbers[NofPlydNbrs] = EMPTY;
	        	Convert2BinAndPut(Board, Counter0, Counter1, EMPTY);
	            if(TempScore > Score){
	                Score = TempScore;
	                i = Counter0;
	                j = Counter1;
	            }
			}
            Counter1++;
        }
        Counter0++;
    }
	Convert2BinAndPut(Board, i, j, Number);
	return (j + MAXBOARD*i + 1);
}

int AIChooseNumber(int Board[MAXBOARD][MAXBOARD][NOFPOS], int NumberArray[MAXBOARD*MAXBOARD], int PlayedNumbers[MAXBOARD*MAXBOARD], int NumberofMoves){

	int NotPlayed[MAXBOARD*MAXBOARD];
	int Counter0 = 0;
	int TempScore = -1;
	int AuxNumber = -1;
	int TempNumber = -1;
	char HexNumber = '0';
	int Score = 4;
	NotPlayedArray(NumberArray, PlayedNumbers, NotPlayed);

	if(NumberofMoves == 0){
		srand((unsigned) time(NULL));
		AuxNumber = rand() % MAXBOARD*MAXBOARD;
		HexNumber = HexConversion(AuxNumber);
		printf("(AI) The first number is: %c\n", HexNumber);
	}else{
		while(Counter0 < MAXBOARD*MAXBOARD && NotPlayed[Counter0] != EMPTY){
			TempNumber = NotPlayed[Counter0];
			TempScore = CheckMaxScore(Board, TempNumber);
			if(TempScore < Score){
				Score = TempScore;
				AuxNumber = TempNumber;
			}
			++Counter0;
		}
		HexNumber = HexConversion(AuxNumber);
		printf("(AI) The next number is: %c\n", HexNumber);
	}
	return AuxNumber;
}

void NArray(int Array[MAXBOARD*MAXBOARD]){

	int *PArray = &Array[0];
	int Counter0 = 0;

	while(Counter0 < MAXBOARD*MAXBOARD){
		*PArray = Counter0;
		++PArray;
		++Counter0;
	}
}
