// Copyright Vacuda 2020


#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


///////SETUP///////
    APawnTank::APawnTank()
    {
        SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
        SpringArm->SetupAttachment(RootComponent);

        Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
        Camera->SetupAttachment(SpringArm);
    }

    void APawnTank::BeginPlay()
    {
        Super::BeginPlay();
        PlayerControllerRef = Cast<APlayerController>(GetController());

    }

    void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
    {
        Super::SetupPlayerInputComponent(PlayerInputComponent);

        PlayerInputComponent->BindAxis("MoveForward", this, &APawnTank::CalculateMoveInput);
        PlayerInputComponent->BindAxis("Turn", this, &APawnTank::CalculateTurnInput);
        PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APawnTank::Fire);
    }



///////MOVEMENT///////
    //calculate
    void APawnTank::CalculateMoveInput(float Value)
    {
        MoveDirection = FVector(Value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0, 0);
    }

    //calculate
    void APawnTank::CalculateTurnInput(float Value)
    {
        float TurnAmount = Value * TurnSpeed * GetWorld()->DeltaTimeSeconds;
        FRotator Turn = FRotator(0, TurnAmount, 0);
        TurnDirection = FQuat(Turn);
    }

    //apply
    void APawnTank::Move()
    {
        AddActorLocalOffset(MoveDirection, true);
    }

    //apply
    void APawnTank::Turn()
    {
        AddActorLocalRotation(TurnDirection, true);
    }


///////OTHER///////

void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    Turn();
    Move();

    if(PlayerControllerRef){

        //get mouse movement
        FHitResult TraceHitResult;
        PlayerControllerRef->GetHitResultUnderCursor(ECC_Visibility, false, TraceHitResult);

        //set turret rotate to mouse position
        RotateTurret(TraceHitResult.ImpactPoint);
    }

}


void APawnTank::HandleDestruction()
{
    Super::HandleDestruction();

    //Hide player
}