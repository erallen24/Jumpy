// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "JumpyUI.generated.h"

/**
 * 
 */
UCLASS()
class JUMPY_API UJumpyUI : public UUserWidget
{
	GENERATED_BODY()

public:

	void SetHeight(int32 Height);
	void SetCoin(int32 Amount);
	void IncreaseCoin(int32 Amount);

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* HeightText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* MaxHeightText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UProgressBar* MaxHeightProgressBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* CoinText;

	int32 MaxHeight;

	int32 CoinAmount;

};
