#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RollingActor.generated.h"

UCLASS()
class TASK6_API ARollingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARollingActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
