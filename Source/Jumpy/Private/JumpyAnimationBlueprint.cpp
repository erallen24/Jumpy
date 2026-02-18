// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpyAnimationBlueprint.h"

void UJumpyAnimationBlueprint::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	//UE_LOG(LogTemp, Warning, TEXT("Native Initialize Animation is Playing"));

	JumpyCharacter = Cast<AJumpyCharacter>(TryGetPawnOwner());
	if (JumpyCharacter)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Jumpy Character Cast success"));
		JumpyCharacterMovement = JumpyCharacter->GetCharacterMovement();
	}
}

void UJumpyAnimationBlueprint::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	//UE_LOG(LogTemp, Warning, TEXT("Native Update Animation is Playing"));

	if (JumpyCharacterMovement)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Jumpy Character Movement set success"));
		FVector VelocityVector = JumpyCharacterMovement->Velocity;
		GroundSpeed = UKismetMathLibrary::VSizeXY(VelocityVector);

		// Calculate lean amount
		CurrentFrameRotation = JumpyCharacter->GetActorRotation();

		FRotator DeltaRotator = UKismetMathLibrary::NormalizedDeltaRotator(LastFrameRotation, CurrentFrameRotation);

		leanAmount = UKismetMathLibrary::FInterpTo(leanAmount, DeltaRotator.Yaw, DeltaSeconds, 2);

		LastFrameRotation = JumpyCharacter->GetActorRotation();

		// Calculate Jump
		isInAir = JumpyCharacterMovement->IsFalling();
		FVector MovementInputVector = JumpyCharacter->GetLastMovementInputVector();
		double MovementInputValue = UKismetMathLibrary::VSize(MovementInputVector);

		if (MovementInputValue > 0)
		{
			MovementInputBool = true;
		}
		else
		{
			MovementInputBool = false;
		}
	}
}


