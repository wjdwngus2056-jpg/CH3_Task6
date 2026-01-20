#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorForSpawner.generated.h"

UCLASS()
class TASK6_API AActorForSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	AActorForSpawner();

protected:
	virtual void BeginPlay() override;
	virtual void RandSpawnActors(int DistanceParam);
    virtual void RandomizeSpawnLocation(int DistanceParam);


protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorForSpawner|Properties")
    TArray<TSubclassOf<AActor>> SpawnableActors;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorForSpawner|Properties")
    int32 NumberOfActorsToSpawn;
	FVector SpawnLocation;
};
