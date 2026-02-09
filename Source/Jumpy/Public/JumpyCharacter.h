// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "JumpyCharacter.generated.h"

UCLASS()
class JUMPY_API AJumpyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AJumpyCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;
	

};
