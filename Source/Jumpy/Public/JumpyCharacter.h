// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
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

	UPROPERTY(EditAnywhere, Category = "mInput")
	UInputMappingContext* IMC_Jumpy;

	UPROPERTY(EditAnywhere, Category = "mInput")
	UInputAction* MoveAction;

	
	void Move(const FInputActionValue& Value);

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

};

// LOG EXAMPLES
	// UE_LOG(LogTemp, Warning, TEXT("The float value is: %f"), ExampleFloat);
	// UE_LOG(LogTemp, Warning, TEXT("The integer value is: %d"), ExampleInteger);
	// UE_LOG(LogTemp, Warning, TEXT("The vector value is: %s"), *ExampleVector.ToString());
