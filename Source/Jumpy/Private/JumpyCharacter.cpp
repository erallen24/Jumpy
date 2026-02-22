// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpyCharacter.h"


// Sets default values
AJumpyCharacter::AJumpyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MySpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("MyCamera"));
	Camera->AttachToComponent(SpringArm, FAttachmentTransformRules::KeepRelativeTransform);

	SpringArm->TargetArmLength = 500;
	SpringArm->SocketOffset = FVector(0, 0, 120);
	SpringArm->bUsePawnControlRotation = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->MaxWalkSpeed = 500;
	GetCharacterMovement()->bOrientRotationToMovement = true;

}

// Called when the game starts or when spawned
void AJumpyCharacter::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* JumpyController = Cast<APlayerController>(GetController());

	if (JumpyController)
	{

		PlayerHUD = CreateWidget<UJumpyUI>(JumpyController, widgetSubclass);
		PlayerHUD->AddToViewport();

		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(JumpyController->GetLocalPlayer());

		if (Subsystem)
		{
			Subsystem->ClearAllMappings();
			Subsystem->AddMappingContext(IMC_Jumpy, 0);
		}
	}
	
}

// Called every frame
void AJumpyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerHUD)
	{
		PlayerHUD->SetHeight(GetActorLocation().Z);
	}

}

// Called to bind functionality to input
void AJumpyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AJumpyCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AJumpyCharacter::Look);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AJumpyCharacter::JumpFunc);
	}
}

void AJumpyCharacter::Move(const FInputActionValue& Value)
{
	FVector2D ReceiveValue = Value.Get<FVector2D>();
	//UE_LOG(LogTemp, Warning, TEXT("The vector value is: %s"), *ReceiveValue.ToString());

	FRotator ControlRotation =  GetControlRotation();

	FVector ForwardVector = FRotationMatrix(FRotator(0, ControlRotation.Yaw, 0)).GetUnitAxis(EAxis::X);
	FVector RightVector = FRotationMatrix(FRotator(0, ControlRotation.Yaw, ControlRotation.Roll)).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardVector, ReceiveValue.Y);
	AddMovementInput(RightVector, ReceiveValue.X);
}

void AJumpyCharacter::Look(const FInputActionValue& Value)
{
	FVector2D ReceiveValue = Value.Get<FVector2D>();
	//UE_LOG(LogTemp, Warning, TEXT("The vector value is: %s"), *ReceiveValue.ToString());

	AddControllerPitchInput(ReceiveValue.Y);
	AddControllerYawInput(ReceiveValue.X);
}

void AJumpyCharacter::JumpFunc(const FInputActionValue& Value)
{
	Jump();
}

