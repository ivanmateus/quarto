#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "ai.h"
#include "board.h"

#define MAXBOARD 4
#define NOFPOS 4

int Game(int Board[MAXBOARD][MAXBOARD][NOFPOS]);
void GameResult(int MatchResult);
void MultiPlayerGame(int Board[MAXBOARD][MAXBOARD][NOFPOS]);
int AIShowNext(int Board[MAXBOARD][MAXBOARD][NOFPOS], int NumberArray[MAXBOARD*MAXBOARD], int PlayedNumbers[MAXBOARD*MAXBOARD], int NumberofMoves);
int AIGame_AIFirst(int Board[MAXBOARD][MAXBOARD][NOFPOS]);
int AIGame_PlayerFirst(int Board[MAXBOARD][MAXBOARD][NOFPOS]);
void AIGameResult(int MatchResult);
void FullAIGame(int Board[MAXBOARD][MAXBOARD][NOFPOS]);
void FullMultiGame(int Board[MAXBOARD][MAXBOARD][NOFPOS]);
void Quarto(int Board[MAXBOARD][MAXBOARD][NOFPOS]);

#endif
