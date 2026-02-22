// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"
#include "NiagaraComponent.h"
#include "JumpyCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Fan.generated.h"

UCLASS()
class JUMPY_API AFan : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFan();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Frame;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Fan;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FanGrating;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* Box;

	UPROPERTY(VisibleAnywhere)
	UArrowComponent* ForceDirection;

	UPROPERTY(VisibleAnywhere)
	UNiagaraComponent* Wind;

	UFUNCTION()
	void OnPlayerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnPlayerExit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	FTimerHandle TimerHandle;

	void LaunchPlayer();

	AJumpyCharacter* Player;

	UPROPERTY(EditAnywhere)
	float FanPower = 100;
};
