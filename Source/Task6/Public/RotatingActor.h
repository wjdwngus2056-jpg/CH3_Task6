#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class TASK6_API ARotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void RotateActor(float DeltaTime);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingActor|Components")
	TObjectPtr<USceneComponent>	SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MovingActor|Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingActor|Properties")
	int32 RotationSpeed;

	int32 RotationMode;
};
