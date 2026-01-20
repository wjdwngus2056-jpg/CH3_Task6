#include "RollingActor.h"

ARollingActor::ARollingActor()
{
	PrimaryActorTick.bCanEverTick = true;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    RootComponent = SceneRoot;
    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    ActorSpeed = 100.f;
    RollingSpeed = 90.f;
    TurnInterval = 2.0f;
    TurnMode = 1;
}

void ARollingActor::BeginPlay()
{
	Super::BeginPlay();
	
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ARollingActor::TurnActor, TurnInterval, true);
}

void ARollingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    RollActor(DeltaTime);
}

void ARollingActor::RollActor(float DeltaTime)
{
    switch(TurnMode)
    {
    case 1:
        AddActorWorldOffset(FVector(ActorSpeed * DeltaTime, 0.f, 0.f));
        AddActorWorldRotation(FRotator(-RollingSpeed * DeltaTime, 0.f, 0.f));
        break;
    case 2:
        AddActorWorldOffset(FVector(0.f, 0.f, ActorSpeed * DeltaTime));
        AddActorWorldRotation(FRotator(0.f, 0.f, -RollingSpeed * DeltaTime));
        break;
    case 3:
        AddActorWorldOffset(FVector(-ActorSpeed * DeltaTime, 0.f, 0.f));
        AddActorWorldRotation(FRotator(RollingSpeed * DeltaTime, 0.f, 0.f));
        break;
    case 4:
        AddActorWorldOffset(FVector(0.f, 0.f, -ActorSpeed * DeltaTime));
        AddActorWorldRotation(FRotator(0.f, 0.f, RollingSpeed * DeltaTime));
        break;
    }
}

void ARollingActor::TurnActor()
{
    if (TurnMode == 4)
    {
        TurnMode = 1;
    }
    else
    {
        TurnMode++;
    }
}
