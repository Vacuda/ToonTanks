// Copyright Vacuda 2020


#include "PawnTurret.h"
#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"  //Get Pawn and maybe fvector

APawnTurret::APawnTurret()
{


}


void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	
    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition,  FireRate, true);

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    // safety check
    if(!PlayerPawn || !TurretMesh){
        return;
    }

    if(ReturnDistanceToPlayer() <= FireRange){
        Super::RotateTurret(PlayerPawn->GetActorLocation());
    }
    else{
        PatrolBehavior();
    }


}

void APawnTurret::CheckFireCondition()
{

    // safety check
    if(!PlayerPawn){
        return;
    }

    if(ReturnDistanceToPlayer() <= FireRange){
        Fire();
    }
}

float APawnTurret::ReturnDistanceToPlayer()
{
    // safety check
    if(!PlayerPawn){
        return 0.f;
    }

    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());

}

void APawnTurret::PatrolBehavior()
{
    // safety check
    if(!TurretMesh){
        return;
    }

    //starting rotation
    FRotator RotationChange = TurretMesh->GetComponentRotation();

    //change rotation
    RotationChange.Yaw+=PatrolSpeed;

    //set turret rotation
    TurretMesh->SetWorldRotation(RotationChange);
}

void APawnTurret::HandleDestruction()
{
    Super::HandleDestruction();

    Destroy();
}