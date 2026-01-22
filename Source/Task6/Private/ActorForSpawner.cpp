#include "ActorForSpawner.h"
#include "RotatingActor.h"
#include "MovingActor.h"

AActorForSpawner::AActorForSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
    SpawnLocation = FVector::ZeroVector;
	NumberOfActorsToSpawn = 5;
}

void AActorForSpawner::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < NumberOfActorsToSpawn; i++)
	{
		RandSpawnActors(i);
	}

}

void AActorForSpawner::RandSpawnActors(int DistanceParam)
{
	RandomizeSpawnLocation(DistanceParam);
	int32 RandomIndex = FMath::RandRange(0, SpawnableActors.Num() - 1);
	if (SpawnableActors.IsValidIndex(RandomIndex) && SpawnableActors[RandomIndex])
	{
		GetWorld()->SpawnActor<AActor>(
			SpawnableActors[RandomIndex],
			SpawnLocation,
			FRotator::ZeroRotator
		);
	}
}

void AActorForSpawner::RandomizeSpawnLocation(int DistanceParam)
{
    int32 LocationZ = FMath::RandRange(100.f, 300.f);

    SpawnLocation = FVector(0.f, DistanceParam * 200.f, LocationZ);
}
