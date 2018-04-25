#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdio.h>
#include <stdlib.h>
#include "ai.h"
#include "game.h"
#include "board.h"

#define MAXBOARD 4
#define NOFPOS 4
#define P1 1
#define P2 -1

int WhichPlayer(int Player);
int TypeNext(int CurrentPlayer, int NumberofMoves, int PlayedNumbers[MAXBOARD*MAXBOARD]);

#endif
