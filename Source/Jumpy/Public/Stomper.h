// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "JumpyCharacter.h"
#include "Stomper.generated.h"

UCLASS()
class JUMPY_API AStomper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStomper();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void MoveStomper(FVector Position);
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	
	

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Frame;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Stomper;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* Box;

	UFUNCTION()
	void OnPlayerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnPlayerExit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
