#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TaskCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
struct FInputActionValue;

UCLASS()
class TASK6_API ATaskCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATaskCharacter();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UCameraComponent> CameraComp;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void Move(const FInputActionValue& value);
	UFUNCTION()
	void StartJump(const FInputActionValue& value);
	UFUNCTION()
    void StopJump(const FInputActionValue& value);
	UFUNCTION()
    void Look(const FInputActionValue& value);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float CharacterSpeed;
};
