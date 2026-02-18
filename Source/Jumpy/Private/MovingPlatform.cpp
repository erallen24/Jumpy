// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MovingPlatformMesh"));
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Path"));
	Interp = CreateDefaultSubobject< UInterpToMovementComponent>(TEXT("Movement"));


	Root->SetupAttachment(GetRootComponent());
	Mesh->SetupAttachment(Root);
	Spline->SetupAttachment(Root);
	
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	int32 NumSplinePoints = Spline->GetNumberOfSplinePoints();
	for (size_t i = 0; i < NumSplinePoints; i++)
	{
		FVector splinePointLocation = Spline->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::Local);

		Interp->AddControlPointPosition(splinePointLocation);
	}

	Interp->SetComponentTickEnabled(true);
	Interp->Duration = Duration;
	Interp->BehaviourType = EInterpToBehaviourType::PingPong;
	Interp->FinaliseControlPoints();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

