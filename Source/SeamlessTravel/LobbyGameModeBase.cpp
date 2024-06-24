// Fill out your copyright notice in the Description page of Project Settings.

#include "LobbyGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Logging/StructuredLog.h"

ALobbyGameModeBase::ALobbyGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bUseSeamlessTravel = true;
}

void ALobbyGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	if (MissionControlType)
	{
		MissionControl = GetWorld()->SpawnActor<AMissionControlBase>(MissionControlType);
		if (MissionControl)
		{
			UE_LOGFMT(LogTemp, Log, "Mission Control created: {name} (value: {value})", MissionControl->GetName(), MissionControl->Value);
			MissionControl->Value = 23;
		}
		else
		{
			UE_LOGFMT(LogTemp, Error, "failed to create Mission Control");
		}
	}
}

void ALobbyGameModeBase::GetSeamlessTravelActorList(bool bToTransition, TArray<AActor*>& ActorList)
{
	Super::GetSeamlessTravelActorList(bToTransition, ActorList);

	if (MissionControl)
	{
		UE_LOGFMT(LogTemp, Log, "persisting mission control ({name}) across level transition", MissionControl->GetName());
		ActorList.Add(MissionControl);
	}
}