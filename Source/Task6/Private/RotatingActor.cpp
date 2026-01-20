#include "RotatingActor.h"

ARotatingActor::ARotatingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotationMode = FMath::RandRange(1, 3);
	RotationSpeed = 50;
}

void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
}

void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateActor(DeltaTime);
}

void ARotatingActor::RotateActor(float DeltaTime)
{
	switch (RotationMode)
	{
	case 1:
		AddActorLocalRotation(FRotator(RotationSpeed * DeltaTime, 0.f, 0.f));
		break;
	case 2:
		AddActorLocalRotation(FRotator(0.f, RotationSpeed * DeltaTime, 0.f));
		break;
	case 3:
		AddActorLocalRotation(FRotator(0.f, 0.f, RotationSpeed * DeltaTime));
		break;
	}
}

