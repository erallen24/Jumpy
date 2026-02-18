// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "JumpyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "JumpyAnimationBlueprint.generated.h"

/**
 * 
 */
UCLASS()
class JUMPY_API UJumpyAnimationBlueprint : public UAnimInstance
{
	GENERATED_BODY()
	

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeInitializeAnimation() override;

	UPROPERTY(BlueprintReadOnly)
	AJumpyCharacter* JumpyCharacter;

	UPROPERTY(BlueprintReadOnly)
	UCharacterMovementComponent* JumpyCharacterMovement;

	UPROPERTY(BlueprintReadOnly)
	double GroundSpeed;

	// Lean Variables
	UPROPERTY(BlueprintReadOnly)
	double leanAmount;

	FRotator CurrentFrameRotation;
	FRotator LastFrameRotation;
};
