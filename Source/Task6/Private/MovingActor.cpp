#include "MovingActor.h"


AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

