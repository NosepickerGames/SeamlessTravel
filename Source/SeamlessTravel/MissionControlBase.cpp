// Fill out your copyright notice in the Description page of Project Settings.

#include "MissionControlBase.h"

// Sets default values
AMissionControlBase::AMissionControlBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Value = 42;
}

// Called when the game starts or when spawned
void AMissionControlBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMissionControlBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}