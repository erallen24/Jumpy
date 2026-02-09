// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpyCharacter.h"

// Sets default values
AJumpyCharacter::AJumpyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJumpyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJumpyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AJumpyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

