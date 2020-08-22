// Copyright Vacuda 2020


#include "ProjectileBase.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	RootComponent = ProjectileMesh;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));

	ProjectileMovement->InitialSpeed = ProjectileSpeed;
	ProjectileMovement->MaxSpeed = ProjectileSpeed;

	//whole class
	InitialLifeSpan = 3.f;


	// ProjectileMovement->Damage = ProjectileDamage;
}

void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}


