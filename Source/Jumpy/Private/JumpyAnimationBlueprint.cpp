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
		//UE_LOG(LogTemp, Warning, TEXT("The velocity vector value is: %s"), *VelocityVector.ToString());
		GroundSpeed = UKismetMathLibrary::VSizeXY(VelocityVector);
	}
}


