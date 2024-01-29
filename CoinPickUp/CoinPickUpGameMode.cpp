// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoinPickUpGameMode.h"
#include "CoinPickUpCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "CoinPickupGameState.h"
#include "CoinPickupCharacterHUD.h"
#include "CoinPickupCharacterController.h"

ACoinPickUpGameMode::ACoinPickUpGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	/*
	*	The following is way to set gamemode member classes. What was difficult was trying to have a hud and user widget to display overlay without having to 
	*   draw everything within class and not use blue prints.
	*/

	// set GameStateClass to custom game state
	// UI is greyed out since c++
	//GameStateClass = ACoinPickupGameState::StaticClass();

	// set HUDClass to custom character hud
	//HUDClass = ACoinPickupCharcterHUD::StaticClass();

	// set PlayerControllerClass to player controller class
	//PlayerControllerClass = ACoinPickupCharacterController::StaticClass();
}
