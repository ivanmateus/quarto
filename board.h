#ifndef BOARD_H_
#define BOARD_H_

#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "ai.h"
#include "game.h"

#define MAXBOARD 4
#define NOFPOS 4
#define EMPTY -1
#define TRUE 1
#define FALSE 0

void InitBoard(int Board[MAXBOARD][MAXBOARD][NOFPOS]);
void PrintBoard(int Board[MAXBOARD][MAXBOARD][NOFPOS]);
int AnyWinner(int Board[MAXBOARD][MAXBOARD][NOFPOS], int CurrentPlayer);
void InitArray(int Array[MAXBOARD*MAXBOARD]);
int OccupiedPos(int Moves[MAXBOARD*MAXBOARD], char Position);
int DecConversion(char HexNumber);
char HexConversion(int ConvNumber);
void Convert2BinAndPut(int Board[MAXBOARD][MAXBOARD][NOFPOS], int i, int j, int Number);
void PutNumber(int Board[MAXBOARD][MAXBOARD][NOFPOS], int Position, int Number);
int CheckAndPut(int Board[MAXBOARD][MAXBOARD][NOFPOS], int PlayedNumbers[MAXBOARD*MAXBOARD], int Moves[MAXBOARD*MAXBOARD], int CurrentPlayer, int Number);
int CheckNumber(int PlayedNumbers[MAXBOARD*MAXBOARD], int Number);

#endif
