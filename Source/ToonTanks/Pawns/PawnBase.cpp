// Copyright Vacuda 2020


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APawnBase::APawnBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = Capsule;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

}


void APawnBase::RotateTurret(FVector Target)
{


	//get StartLocation of Turret Component
	FVector StartLocation = TurretMesh->GetComponentLocation();

	//set to X and Y of Target.  Keep Z of Turret
	FVector TargetLocation = FVector(Target.X, Target.Y, StartLocation.Z);

	//get new rotation, target - start
	FRotator TurretRotation = FVector(TargetLocation - StartLocation).Rotation();

	TurretMesh->SetWorldRotation(TurretRotation);




}

void APawnBase::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Fire Fire"));
}

void APawnBase::HandleDestruction()
{

}

