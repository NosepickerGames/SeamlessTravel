// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SeamlessTravelGameMode.generated.h"

UCLASS(minimalapi)
class ASeamlessTravelGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASeamlessTravelGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};