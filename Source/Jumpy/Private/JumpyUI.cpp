// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpyUI.h"

#define LOCTEXT_NAMESPACE "MyNamespace"

void UJumpyUI::SetHeight(int32 Height)
{
	FText HeightFText = FText::Format(LOCTEXT("ShowHeight", "{0}"), Height/100);
	HeightText->SetText(HeightFText);

	MaxHeightProgressBar->SetPercent(static_cast<float>(Height) / MaxHeight);

	if (Height > (MaxHeight + 50))
	{
		IncreaseCoin((Height - MaxHeight) / 10);

		MaxHeight = Height;
		FText MaxHeightFText = FText::Format(LOCTEXT("ShowMaxHeight", "{0}"), Height / 100);
		MaxHeightText->SetText(MaxHeightFText);
	}
}

void UJumpyUI::SetCoin(int32 Amount)
{
	FText coinAmountFText = FText::AsCurrency(Amount, "$");
	CoinText->SetText(coinAmountFText);
}

void UJumpyUI::IncreaseCoin(int32 Amount)
{
	CoinAmount += Amount;
	SetCoin(CoinAmount);
}
