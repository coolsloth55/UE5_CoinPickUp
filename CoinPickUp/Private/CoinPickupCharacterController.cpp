// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinPickupCharacterController.h"
#include "CoinPickupCharacterHUD.h"
#include "CoinPickupCharacterWidget.h"

void ACoinPickupCharacterController::SetHUDScore(int32 Score)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("SetHUDScore()"));
	}
		

	// check if CoinPickupCharcterHUD is null if so cast HUD to CoinPickupCharcterHUD
	// if not null return CoinPickupCharcterHUD
	CoinPickupCharcterHUD = CoinPickupCharcterHUD == nullptr ? Cast<ACoinPickupCharcterHUD>(GetHUD()) : CoinPickupCharcterHUD;
	if (CoinPickupCharcterHUD && CoinPickupCharcterHUD->CPCharacterWidget && CoinPickupCharcterHUD->CPCharacterWidget->Score) {
		FString ScoreText = FString::Printf(TEXT("%d"), Score);
		CoinPickupCharcterHUD->CPCharacterWidget->Score->SetText(FText::FromString(ScoreText));
	}

	if(CoinPickupCharcterHUD) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("CPCharacterWidget is avail"));
		}
	}
}

void ACoinPickupCharacterController::BeginPlay()
{
	Super::BeginPlay();

	CoinPickupCharcterHUD = Cast<ACoinPickupCharcterHUD>(GetHUD());

	if (CoinPickupCharcterHUD) {
		if (CoinPickupCharcterHUD->CPCharacterWidget == nullptr) {
			CoinPickupCharcterHUD->AddCharacterOverlay();
		}
	}

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("ACoinPickupCharacterController::BeginPlay()"));
	}

}

void ACoinPickupCharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PollInit();
}

void ACoinPickupCharacterController::PollInit()
{
	// TODO: Maybe init score text here
}
