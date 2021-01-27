// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TATA_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Speed;
public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override; 


	UFUNCTION(BlueprintCallable)
	float GetSpeed();
};
