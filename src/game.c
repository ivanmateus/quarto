#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "board.h"
#include "player.h"
#include "ai.h"

int Game(int Board[MAXBOARD][MAXBOARD][NOFPOS]){

	int MatchResult = 0;
	int NumberofMoves = 0;
	int NofPlydNbrs = 0;
	int Moves[MAXBOARD*MAXBOARD];
	int PlayedNumbers[MAXBOARD*MAXBOARD];
	int ConvertedNumber = 0;
	int CurrentPlayer = P1;

	InitArray(Moves);
	InitArray(PlayedNumbers);


	printf("START!\n");
	ConvertedNumber = TypeNext(CurrentPlayer, NumberofMoves, PlayedNumbers);

	while(NumberofMoves < (MAXBOARD*MAXBOARD)){
		CurrentPlayer = CurrentPlayer*(-1);
		Moves[NumberofMoves] = CheckAndPut(Board, PlayedNumbers, Moves, CurrentPlayer, ConvertedNumber);
		PlayedNumbers[NofPlydNbrs] = ConvertedNumber;
		++NofPlydNbrs;
		++NumberofMoves;
		MatchResult = AnyWinner(Board, CurrentPlayer);
		if(MatchResult != FALSE){
			return MatchResult;
		}
		ConvertedNumber = TypeNext(CurrentPlayer, NumberofMoves, PlayedNumbers);

	    if(NumberofMoves != MAXBOARD*MAXBOARD){
			CurrentPlayer = CurrentPlayer*(-1);
			Moves[NumberofMoves] = CheckAndPut(Board, PlayedNumbers, Moves, CurrentPlayer, ConvertedNumber);
			PlayedNumbers[NofPlydNbrs] = ConvertedNumber;
			++NofPlydNbrs;
			++NumberofMoves;
			MatchResult = AnyWinner(Board, CurrentPlayer);
			if(MatchResult != FALSE){
				return MatchResult;
			}
			ConvertedNumber = TypeNext(CurrentPlayer, NumberofMoves, PlayedNumbers);
		}
	}
	return MatchResult;
}

void GameResult(int MatchResult){

	if(MatchResult == P1){
		printf("The winner is Player 1!\n");
	}else{
		printf("The winner is Player 2!\n");
	}
}

void MultiPlayerGame(int Board[MAXBOARD][MAXBOARD][NOFPOS]){

	int Result = Game(Board);
	GameResult(Result);
}

int AIGame_AIFirst(int Board[MAXBOARD][MAXBOARD][NOFPOS]){

	int MatchResult = 0;
	int NumberofMoves = 0;
	int NofPlydNbrs = 0;
	int Moves[MAXBOARD*MAXBOARD];
	int NumberArray[MAXBOARD*MAXBOARD];
	int PlayedNumbers[MAXBOARD*MAXBOARD];
	int PlayerNumber = 0;
	int AINumber = 0;
	int CurrentPlayer = AI;

	InitArray(Moves);
	InitArray(PlayedNumbers);
	NArray(NumberArray);

	printf("START!\n");
	AINumber = AIChooseNumber(Board, NumberArray, PlayedNumbers, NumberofMoves);

	while(NumberofMoves < (MAXBOARD*MAXBOARD)){
		CurrentPlayer = CurrentPlayer*(-1);
		Moves[NumberofMoves] = CheckAndPut(Board, PlayedNumbers, Moves, CurrentPlayer, AINumber);
		PlayedNumbers[NofPlydNbrs] = AINumber;
		++NofPlydNbrs;
		++NumberofMoves;
		MatchResult = AnyWinner(Board, CurrentPlayer);
		if(MatchResult != FALSE){
			return MatchResult;
		}
		PlayerNumber = TypeNext(CurrentPlayer, NumberofMoves, PlayedNumbers);

	    if(NumberofMoves != MAXBOARD*MAXBOARD){
			CurrentPlayer = CurrentPlayer*(-1);
			if(NumberofMoves < 6){
				Moves[NumberofMoves] = AIMove(Board, PlayerNumber, NumberArray, PlayedNumbers, NofPlydNbrs);
			}else{
				Moves[NumberofMoves] = AIMovewMiniMax(Board, PlayerNumber, NumberArray, PlayedNumbers, NofPlydNbrs);
			}
			PlayedNumbers[NofPlydNbrs] = PlayerNumber;
			++NumberofMoves;
			++NofPlydNbrs;
			PrintBoard(Board);
			MatchResult = AnyWinner(Board, CurrentPlayer);
			if(MatchResult != FALSE){
		      	return MatchResult;
		    }

			AINumber = AIChooseNumber(Board, NumberArray, PlayedNumbers, NumberofMoves);
		}
	}
	return MatchResult;
}

int AIGame_PlayerFirst(int Board[MAXBOARD][MAXBOARD][NOFPOS]){

	int MatchResult = 0;
	int NumberofMoves = 0;
	int NofPlydNbrs = 0;
	int Moves[MAXBOARD*MAXBOARD];
	int NumberArray[MAXBOARD*MAXBOARD];
	int PlayedNumbers[MAXBOARD*MAXBOARD];
	int PlayerNumber = 0;
	int AINumber = 0;
	int CurrentPlayer = P1;

	InitArray(Moves);
	InitArray(PlayedNumbers);
	NArray(NumberArray);

	printf("START!\n");
	PlayerNumber = TypeNext(CurrentPlayer, NumberofMoves, PlayedNumbers);

	while(NumberofMoves < (MAXBOARD*MAXBOARD)){
		CurrentPlayer = CurrentPlayer*(-1);
		if(NumberofMoves < 6){
			Moves[NumberofMoves] = AIMove(Board, PlayerNumber, NumberArray, PlayedNumbers, NofPlydNbrs);
		}else{
			Moves[NumberofMoves] = AIMovewMiniMax(Board, PlayerNumber, NumberArray, PlayedNumbers, NofPlydNbrs);
		}
		PlayedNumbers[NofPlydNbrs] = PlayerNumber;
		++NumberofMoves;
		++NofPlydNbrs;
		AINumber = AIChooseNumber(Board, NumberArray, PlayedNumbers, NumberofMoves);
		PrintBoard(Board);
		MatchResult = AnyWinner(Board, CurrentPlayer);
		if(MatchResult != FALSE){
	      	return MatchResult;
	    }

	    if(NumberofMoves != MAXBOARD*MAXBOARD){
			CurrentPlayer = CurrentPlayer*(-1);
			Moves[NumberofMoves] = CheckAndPut(Board, PlayedNumbers, Moves, CurrentPlayer, AINumber);
			PlayedNumbers[NofPlydNbrs] = AINumber;
			++NumberofMoves;
			++NofPlydNbrs;
			MatchResult = AnyWinner(Board, CurrentPlayer);
		    if(MatchResult != FALSE){
		        return MatchResult;
		    }

			PlayerNumber = TypeNext(CurrentPlayer, NumberofMoves, PlayedNumbers);
		}
	}
	return MatchResult;
}

void AIGameResult(int MatchResult){

	if(MatchResult == P1){
		printf("The winner is Player!\n");
	}else{
		printf("The winner is AI!\n");
	}
}

void FullAIGame(int Board[MAXBOARD][MAXBOARD][NOFPOS]){

	int Result = 0;
	int Option = -1;

	printf("Choose a game option: \n");
	printf("1. Player first\n");
	printf("2. AI first\n");
	printf("Type in the option: ");
	scanf("%d", &Option);
	printf("\n");

	while((Option != 1) && (Option != 2)){
		printf("Type in the option: ");
		scanf("%d", &Option);
		printf("\n");
	}
	switch (Option){
		case 1:
			Result = AIGame_PlayerFirst(Board);
			AIGameResult(Result);
			break;
		case 2:
			Result = AIGame_AIFirst(Board);
			AIGameResult(Result);
			break;
	}
}

void FullMultiGame(int Board[MAXBOARD][MAXBOARD][NOFPOS]){

	int MatchResult = Game(Board);
	GameResult(MatchResult);
}

void Quarto(int Board[MAXBOARD][MAXBOARD][NOFPOS]){

    int Option = -1;
    int PlayAgain = 1;
    int AuxAgain = -1;

    printf("Quarto\n\n");

    while(PlayAgain == 1){

        printf("Choose a game option: \n");
        printf("1. Player vs Computer\n");
        printf("2. Player vs Player\n");
        printf("Type in the option: ");
		scanf("%d", &Option);
		printf("\n");

        while((Option != 1) && (Option != 2)){
			printf("Invalid option. Type in again: ");
			scanf("%d", &Option);
	        printf("\n");
      	}

		switch(Option){
			case 1:
				FullAIGame(Board);
				break;
			case 2:
				FullMultiGame(Board);
				break;
		}

      	Option = -1;
      	InitBoard(Board);
      	printf("Would you like to play again? If so, press 1; else, 0: ");
	  	while((AuxAgain != 1) && (AuxAgain != 0)){
      		scanf("%d", &AuxAgain);
	  	}
      	PlayAgain = AuxAgain;
		AuxAgain = -1;
      	printf("\n\n");
    }
}
