// Fill out your copyright notice in the Description page of Project Settings.

#include "Portal.h"
#include "GameFramework/Character.h"
#include "Logging/StructuredLog.h"

// Sets default values
APortal::APortal()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cylinder(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

	Base = CreateDefaultSubobject<UStaticMeshComponent>("Base");
	Base->SetWorldScale3D(FVector(2.0, 2.0, 0.125));
	Base->SetStaticMesh(Cylinder.Object);
	Base->SetupAttachment(RootComponent);

	Collision = CreateDefaultSubobject<USphereComponent>("Collision");
	Collision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Collision->SetCollisionProfileName(FName("OverlapOnlyPawn"));
	Collision->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
	Collision->SetupAttachment(RootComponent);
	Collision->SetSphereRadius(64);

	TextRender = CreateDefaultSubobject<UTextRenderComponent>("TextRender");
	TextRender->SetRelativeLocation(FVector(0.0, 0.0, 100.0));
	TextRender->SetVerticalAlignment(EVRTA_TextCenter);
	TextRender->SetHorizontalAlignment(EHTA_Center);
	TextRender->SetupAttachment(RootComponent);

	Label = FText::FromString(TEXT("Portal"));
}

void APortal::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	TextRender->SetText(Label);
}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	Super::BeginPlay();
	
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndOverlap);
}

void APortal::OnBeginOverlap(UPrimitiveComponent* OverlapppedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APawn* Pawn = Cast<APawn>(OtherActor);
	if (Pawn)
	{
		OnEntered(Pawn);
	}
}

void APortal::OnEndOverlap(UPrimitiveComponent* OverlapppedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	APawn* Pawn = Cast<APawn>(OtherActor);
	if (Pawn)
	{
		OnLeft(Pawn);
	}
}

void APortal::OnEntered_Implementation(APawn* Pawn)
{
	if (Pawn->IsLocallyControlled())
	{
		FSoftObjectPath Path = TargetLevel.ToSoftObjectPath();

		const FWorldContext& Context = GEngine->GetWorldContextFromWorldChecked(GetWorld());
		FURL Target = Context.LastURL;

#if WITH_EDITOR
		Target.Map = UWorld::StripPIEPrefixFromPackageName(Path.GetLongPackageName(), GetWorld()->StreamingLevelsPrefix);
#else
		Target.Map = Path.GetLongPackageName();
#endif

		FString URL = Target.ToString();
		URL.RemoveFromStart(Target.GetHostPortString());

		UE_LOGFMT(LogTemp, Log, "traveling to {URL}", URL);
		GetWorld()->ServerTravel(URL);
	}
}

void APortal::OnLeft_Implementation(APawn* Pawn)
{
}