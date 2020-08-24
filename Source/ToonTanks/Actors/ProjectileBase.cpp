// Copyright Vacuda 2020

#include "ProjectileBase.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
	PrimaryActorTick.bCanEverTick = false;

	//set up ProjectileMesh
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	
	//Add event that will call OnHit
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);

	RootComponent = ProjectileMesh;

	//setup Projectile Movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->InitialSpeed = ProjectileSpeed;
	ProjectileMovement->MaxSpeed = ProjectileSpeed;

	//projectile's life span
	InitialLifeSpan = 3.f;
}

void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectileBase::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AActor* MyOwner = GetOwner();

	//safety check
	if(!MyOwner){
		return;
	}

	//OtherActor is the Target Hit
	//if OtherActor is valid, if OtherActor is not self, if OtherActor is not the Actor that spawned me, then apply damage
	if(OtherActor && OtherActor != this && OtherActor != MyOwner){
		UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwner->GetInstigatorController(), this, DamageType);
	}

	Destroy();
}


