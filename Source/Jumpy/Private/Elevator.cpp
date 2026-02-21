// Fill out your copyright notice in the Description page of Project Settings.


#include "Elevator.h"

// Sets default values
AElevator::AElevator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ElevatorMesh"));
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	Root->SetupAttachment(GetRootComponent());
	Mesh->SetupAttachment(Root);
	Box->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void AElevator::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(InitalWaitTimer, this, &AElevator::SetGoToEndLocation, InitalWaitTime, false);

	Box->OnComponentBeginOverlap.AddDynamic(this, &AElevator::OnBeginElevatorOverlap);
	Box->OnComponentEndOverlap.AddDynamic(this, &AElevator::OnEndElevatorOverlap);
	
}

void AElevator::SetGoToEndLocation()
{
	GoToEndLocation = true;
	GoToStartLocation = false;
}

void AElevator::SetGoToStartLocation()
{
	GoToEndLocation = false;
	GoToStartLocation = true;
}

void AElevator::OnBeginElevatorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	isPlayerOut = false;
	GetWorldTimerManager().SetTimer(OverlapWaitTimer, this, &AElevator::SetGoToStartLocation, OverlapWaitTime, false);
}

void AElevator::OnEndElevatorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	isPlayerOut = true;
	GetWorldTimerManager().SetTimer(InitalWaitTimer, this, &AElevator::SetGoToEndLocation, InitalWaitTime, false);
}

// Called every frame
void AElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GoToEndLocation)
	{
		if (isPlayerOut)
		{
			FVector TempLocation = UKismetMathLibrary::VInterpTo(Mesh->GetRelativeLocation(), EndLocation, DeltaTime, 2);
			Mesh->SetRelativeLocation(TempLocation);

			double DistanceToEndLocation = UKismetMathLibrary::Vector_Distance(TempLocation, EndLocation);
			if (DistanceToEndLocation < 20)
			{
				GoToEndLocation = false;
			}
		}
	}

	if (GoToStartLocation)
	{
		FVector TempLocation = UKismetMathLibrary::VInterpTo(Mesh->GetRelativeLocation(), StartLocation, DeltaTime, 2);
		Mesh->SetRelativeLocation(TempLocation);

		double DistanceToStartLocation = UKismetMathLibrary::Vector_Distance(TempLocation, StartLocation);
		if (DistanceToStartLocation < 20)
		{
			GoToStartLocation = false;
		}
	}
}

