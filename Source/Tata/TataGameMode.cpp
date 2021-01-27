// Copyright Epic Games, Inc. All Rights Reserved.

#include "TataGameMode.h"
#include "TataPawn.h"

ATataGameMode::ATataGameMode()
{
	// set default pawn class to our character class
	//DefaultPawnClass = ATataPawn::StaticClass();
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Player/BP_MyMyCharacter.BP_MyMyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;

	}
}

