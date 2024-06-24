// Copyright Epic Games, Inc. All Rights Reserved.

#include "SeamlessTravelGameMode.h"
#include "SeamlessTravelCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASeamlessTravelGameMode::ASeamlessTravelGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}