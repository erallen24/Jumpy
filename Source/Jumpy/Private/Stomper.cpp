// Fill out your copyright notice in the Description page of Project Settings.


#include "Stomper.h"

// Sets default values
AStomper::AStomper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Frame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StomperFrame"));
	Stomper = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StomperBody"));
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	Frame->SetupAttachment(GetRootComponent());
	Stomper->SetupAttachment(Frame);
	Box->SetupAttachment(Stomper);

}

// Called when the game starts or when spawned
void AStomper::BeginPlay()
{
	Super::BeginPlay();

	Box->OnComponentBeginOverlap.AddDynamic(this, &AStomper::OnPlayerEnter);
	Box->OnComponentEndOverlap.AddDynamic(this, &AStomper::OnPlayerExit);
	
}

void AStomper::OnPlayerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AJumpyCharacter* Player = Cast<AJumpyCharacter>(OtherActor);
	if (Player)
	{
		//UE_LOG(LogTemp, Warning, TEXT("OnPlayerEnter"));
		Player->GetCharacterMovement()->MovementMode = MOVE_Flying;
		Player->GetCharacterMovement()->Velocity = Frame->GetForwardVector();
	}
}

void AStomper::OnPlayerExit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AJumpyCharacter* Player = Cast<AJumpyCharacter>(OtherActor);
	if (Player)
	{
		Player->GetCharacterMovement()->MovementMode = MOVE_Walking;
	}
}

// Called every frame
void AStomper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStomper::MoveStomper(FVector Position)
{
	Stomper->SetRelativeLocation(Position);
}

