#include "MovingActor.h"


AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	MovementSpeed = FMath::RandRange(70.f, 210.f);
	MovementDistance = FMath::RandRange(300.f, 500.f);
	StartLocation = FVector::ZeroVector;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveActor(DeltaTime);
}

void AMovingActor::MoveActor(float DeltaTime)
{
	if (FVector::Dist(GetActorLocation(), StartLocation) >= MovementDistance)
	{
		MovementSpeed = -MovementSpeed;
	}
	AddActorLocalOffset(FVector(MovementSpeed * DeltaTime, 0.f, 0.f));
}

