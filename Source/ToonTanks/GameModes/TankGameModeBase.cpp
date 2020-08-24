// Copyright Vacuda 2020


#include "TankGameModeBase.h"




void ATankGameModeBase::BeginPlay()
{
    //get references and game win/lose conditions

    //call Handlegamestart() to initialize the start countdown, turret activation, and pawn check etc.
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
    //check what type of actor died.  if turret, tally.  if player, go to lose.
    UE_LOG(LogTemp, Warning, TEXT("A Pawn Died!!!!"));
}

void ATankGameModeBase::HandleGameStart()
{
    //initialize the start countdown, turret activation, and pawn check etc.
    //call bp version gamestart
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
    //if all turrets destroyed, show win result
    //else if turret destroyed player, show lose result
    //call bp version gameover(bool)
}


