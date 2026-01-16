#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class TASK6_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
public:
	AMovingActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingActor|Components")
	TObjectPtr<USceneComponent> SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MovingActor|Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComp;

	int32 MovementSpeed;
	int32 MovementDistance;
};
