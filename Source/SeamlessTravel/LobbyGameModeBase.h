// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SeamlessTravelGameMode.h"
#include "MissionControlBase.h"
#include "LobbyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SEAMLESSTRAVEL_API ALobbyGameModeBase : public ASeamlessTravelGameMode
{
	GENERATED_BODY()
	
public:
	ALobbyGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void BeginPlay() override;

	virtual void GetSeamlessTravelActorList(bool bToTransition, TArray<AActor*>& ActorList) override;

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AMissionControlBase> MissionControlType;

	AMissionControlBase* MissionControl;
};