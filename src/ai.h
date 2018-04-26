#ifndef AI_H_
#define AI_H_

#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "game.h"
#include "board.h"

#define MAXBOARD 4
#define NOFPOS 4
#define AI -1

int NotPlayedNumber(int NumberArray[MAXBOARD*MAXBOARD], int PlayedNumbers[MAXBOARD*MAXBOARD]);
int MiniMax(int Board[MAXBOARD][MAXBOARD][NOFPOS], int NumberArray[MAXBOARD*MAXBOARD], int NofPlydNbrs, int PlayedNumbers[MAXBOARD*MAXBOARD], int CurrentPlayer);
void GetEmptyPosition(int Board[MAXBOARD][MAXBOARD][NOFPOS], int EmptyPosits[MAXBOARD*MAXBOARD]);
void NotPlayedArray(int NumberArray[MAXBOARD*MAXBOARD], int PlayedNumbers[MAXBOARD*MAXBOARD], int NotPlayed[MAXBOARD*MAXBOARD]);
void ConvertToArray(int NumberArray[NOFPOS], int Number);
int CheckMaxScore(int Board[MAXBOARD][MAXBOARD][NOFPOS], int Number);
int AIMove(int Board[MAXBOARD][MAXBOARD][NOFPOS], int Number, int NumberArray[MAXBOARD*MAXBOARD], int PlayedNumbers[MAXBOARD*MAXBOARD], int NofPlydNbrs);
int AIMovewMiniMax(int Board[MAXBOARD][MAXBOARD][NOFPOS], int Number, int NumberArray[MAXBOARD*MAXBOARD], int PlayedNumbers[MAXBOARD*MAXBOARD], int NofPlydNbrs);
int AIChooseNumber(int Board[MAXBOARD][MAXBOARD][NOFPOS], int NumberArray[MAXBOARD*MAXBOARD], int PlayedNumbers[MAXBOARD*MAXBOARD], int NumberofMoves);
void NArray(int Array[MAXBOARD*MAXBOARD]);

#endif
