// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/TextRenderComponent.h"
#include "Portal.generated.h"

UCLASS()
class SEAMLESSTRAVEL_API APortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortal();

	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Base;

	UPROPERTY(EditAnywhere)
	USphereComponent* Collision;

	UPROPERTY(EditAnywhere)
	UTextRenderComponent* TextRender;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> TargetLevel;

	UPROPERTY(EditAnywhere)
	FText Label;

	UFUNCTION()
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlapppedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);

	UFUNCTION(BlueprintNativeEvent)
	void OnEntered(APawn* Pawn);

	UFUNCTION(BlueprintNativeEvent)
	void OnLeft(APawn* Pawn);
};