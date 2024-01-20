// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoinPickUpGameMode.h"
#include "CoinPickUpCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACoinPickUpGameMode::ACoinPickUpGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
