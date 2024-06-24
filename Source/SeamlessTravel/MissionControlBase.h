// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "MissionControlBase.generated.h"

UCLASS(Blueprintable)
class SEAMLESSTRAVEL_API AMissionControlBase : public AInfo
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMissionControlBase();

	UPROPERTY(BlueprintReadOnly)
	int32 Value;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};