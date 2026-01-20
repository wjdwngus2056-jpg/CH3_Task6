#include "RollingActor.h"

ARollingActor::ARollingActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ARollingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARollingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

