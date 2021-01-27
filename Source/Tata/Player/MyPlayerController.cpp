// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyCharacter.h"

void AMyPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	//InputComponent->BindAction("SetDestination", IE_Pressed, this, &AMyProjectPlayerController::OnSetDestinationPressed);
	//InputComponent->BindAction("SetDestination", IE_Released, this, &AMyProjectPlayerController::OnSetDestinationReleased);

	// support touch devices 
	//InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AMyProjectPlayerController::MoveToTouchLocation);
	//InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AMyProjectPlayerController::MoveToTouchLocation);

	InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::MoveRight);


	// InputComponent->BindAction("ResetVR", IE_Pressed, this, &AMyPlayerController:OnResetVR);
}

void AMyPlayerController::MoveForward(float x) {
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get forward vector
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	//UE_LOG(LogClass, Log, TEXT("mmtest 1")); 
	if (GetWorld() != nullptr)
	{ 
		//UE_LOG(LogClass, Log, TEXT("mmtest 2"));
		AMyCharacter* c = Cast<AMyCharacter>(GetPawn());
		if (c != nullptr) { 
			//UE_LOG(LogClass, Log, TEXT("mmtest 3"));
			c->AddMovementInput(Direction, x);
		}
	} 
}
void AMyPlayerController::MoveRight(float x) {

	// find out which way is right
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get right vector 
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	//UE_LOG(LogClass, Log, TEXT("mmtest 1")); 
	if (GetWorld() != nullptr)
	{
		//UE_LOG(LogClass, Log, TEXT("mmtest 2"));
		AMyCharacter* c = Cast<AMyCharacter>(GetPawn());
		if (c != nullptr) {
			//UE_LOG(LogClass, Log, TEXT("mmtest 3"));
			c->AddMovementInput(Direction, x);
		}
	}
}