// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinPickupGameState.h"
//#include "Net/UnrealNetwork.h"
#include "CoinPickupCharacterController.h"
#include "Engine/GameEngine.h"

void ACoinPickupGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// TODO: What is DOREPLIFETIME?
	//DOREPLIFETIME(ACoinPickupGameState, Score);
}

void ACoinPickupGameState::CoinPickedUp()
{
	// coin was picked up increment score
	Score++;

	if (GEngine){
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("CoinPickedUp()"));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("World delta for current frame equals %d"), Score));
	}
}

void ACoinPickupGameState::OnCoinPickedUp()
{
	// Get player controller and update HUD to new score
	ACoinPickupCharacterController* CoinPickupController = Cast<ACoinPickupCharacterController>(GetWorld()->GetFirstPlayerController());
	if (CoinPickupController) {
		CoinPickupController->SetHUDScore(Score);
	}
}
