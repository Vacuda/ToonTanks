// Copyright Vacuda 2020

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRate = 2.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRange = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turrets", meta = (AllowPrivateAccess = "true"))
	float PatrolSpeed = 1.f;

	FTimerHandle FireRateTimerHandle;
	APawnTank* PlayerPawn;

	void CheckFireCondition();
	float ReturnDistanceToPlayer();
	void PatrolBehavior();

public:

	APawnTurret();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	
	virtual void HandleDestruction() override;

};
