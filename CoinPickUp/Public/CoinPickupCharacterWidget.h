// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "CoinPickupCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class COINPICKUP_API UCoinPickupCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	// [Score] is text block on interface
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Score;
	
};
