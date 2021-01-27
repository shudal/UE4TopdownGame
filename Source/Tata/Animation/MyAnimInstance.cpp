// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "../Player/MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	AMyCharacter* Pawn = Cast<AMyCharacter>(TryGetPawnOwner());
	if (Pawn && Pawn->IsValidLowLevel())
	{ 
		Speed = Pawn->GetCharacterMovement()->Velocity.Size(); 
	}
}

float UMyAnimInstance::GetSpeed()
{
	return Speed;
}