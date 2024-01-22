// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoinPickUpGameMode.h"
#include "CoinPickUpCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "CoinPickupGameState.h"

ACoinPickUpGameMode::ACoinPickUpGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set GameStateClass to custom game state
	// UI is greyed out since c++
	GameStateClass = ACoinPickupGameState::StaticClass();
}
