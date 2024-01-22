// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Engine/GameEngine.h"
#include "CoinPickupGameState.generated.h"

/**
 * 
 */
UCLASS()
class COINPICKUP_API ACoinPickupGameState : public AGameState
{
	GENERATED_BODY()

public:
	// TODO: What is GetLifetimeReplicatedProps?
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// CoinPickedUp represents coin picked up and increment score
	void CoinPickedUp();

	// TODO: Not sure what this is?
	UPROPERTY(Replicated=OnCoinPickedUp)
	int Score = 0;

	// TODO: Why UFUNCTION?
	UFUNCTION()
	void OnCoinPickedUp();
	
};
