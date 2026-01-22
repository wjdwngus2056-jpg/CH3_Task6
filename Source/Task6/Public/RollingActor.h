#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RollingActor.generated.h"

class UBoxComponent;

UCLASS()
class TASK6_API ARollingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARollingActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void RollActor(float DeltaTime);
	virtual void TurnActor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RollingActor|Components")
	TObjectPtr<USceneComponent> SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "RollingActor|Components")
    TObjectPtr<UStaticMeshComponent> StaticMeshComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "RollingActor||Components")
	TObjectPtr<UBoxComponent> BoxComp;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RollingActor|Properties")
	float ActorSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RollingActor|Properties")
	float RollingSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RollingActor|Properties")
	float TurnInterval;

	FTimerHandle TimerHandle;
	int32 TurnMode;
};
