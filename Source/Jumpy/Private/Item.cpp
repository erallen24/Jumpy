// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Orb = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Orb"));
	Ring = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ring"));
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	Box->SetupAttachment(GetRootComponent());
	Orb->SetupAttachment(Box);
	Ring->SetupAttachment(Orb);

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	Orb->SetWorldRotation(FRotator(0, UKismetMathLibrary::RandomIntegerInRange(0, 15) * 22, 0));

	Box->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnPlayerEnter);

	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Orb->AddLocalRotation(FRotator(0, DeltaTime * 100, 0));

}

void AItem::OnPlayerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AJumpyCharacter* Player = Cast<AJumpyCharacter>(OtherActor);
	if (Player)
	{
		//UE_LOG(LogTemp, Warning, TEXT("OnPlayerEnter"));
		Player->PlayerHUD->IncreaseCoin(100);
		UGameplayStatics::PlaySoundAtLocation(this, CoinCollectedSound, GetActorLocation());
		Destroy();
	}
}



