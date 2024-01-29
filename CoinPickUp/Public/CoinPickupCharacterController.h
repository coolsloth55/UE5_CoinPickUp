// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
//#include "CoinPickupCharacterHUD.h"
#include "CoinPickupCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class COINPICKUP_API ACoinPickupCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	// update score on HUD for player
	void SetHUDScore(int32 Score);
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void PollInit();

private:

	UPROPERTY()
	class ACoinPickupCharcterHUD* CoinPickupCharcterHUD;
};
