// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinPickupCharacterHUD.h"
#include "Subsystems/PanelExtensionSubsystem.h"
#include "CoinPickupCharacterWidget.h"


void ACoinPickupCharcterHUD::BeginPlay()
{
	Super::BeginPlay();
}

void ACoinPickupCharcterHUD::DrawHUD()
{
	Super::DrawHUD();
}

void ACoinPickupCharcterHUD::AddCharacterOverlay()
{
	APlayerController* PlayerController = GetOwningPlayerController();
	if (PlayerController && CPCharacterWidgetClass)
	{
		CPCharacterWidget = CreateWidget<UCoinPickupCharacterWidget>(PlayerController, CPCharacterWidgetClass);
		CPCharacterWidget->AddToViewport();

		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("ACoinPickupCharcterHUD::AddCharacterOverlay()"));
		}
	}
	else {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("ACoinPickupCharcterHUD::AddCharacterOverlay()"));
		}
	}
}
