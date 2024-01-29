// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CoinPickupCharacterHUD.generated.h"

/**
 * 
 */
UCLASS()
class COINPICKUP_API ACoinPickupCharcterHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:

	virtual void DrawHUD() override;

	UPROPERTY(EditAnywhere, Category = "Score")
	TSubclassOf<class UUserWidget> CPCharacterWidgetClass;

	UPROPERTY()
	class UCoinPickupCharacterWidget* CPCharacterWidget;
	
	void AddCharacterOverlay();
};
