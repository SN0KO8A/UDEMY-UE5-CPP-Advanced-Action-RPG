// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorCharacterBase.h"
#include "WarriorCharacterHero.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UDA_InputConfig;
struct FInputActionValue;

UCLASS()
class ADVANCED_ACTION_RPG_API AWarriorCharacterHero : public AWarriorCharacterBase
{
	GENERATED_BODY()

public:
	AWarriorCharacterHero();

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;

	void InputMove(const FInputActionValue& InputActionValue);
	void InputLook(const FInputActionValue& InputActionValue);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	TObjectPtr<USpringArmComponent> SpringArmComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UCameraComponent> CameraComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Data")
	TObjectPtr<UDA_InputConfig> InputConfigDataAsset = nullptr;
};
