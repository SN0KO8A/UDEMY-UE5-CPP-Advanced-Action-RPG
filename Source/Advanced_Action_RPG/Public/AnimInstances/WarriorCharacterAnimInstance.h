// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorBaseAnimInstance.h"
#include "WarriorCharacterAnimInstance.generated.h"

class AWarriorCharacterBase;
class UCharacterMovementComponent;

UCLASS()
class ADVANCED_ACTION_RPG_API UWarriorCharacterAnimInstance : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(Transient)
	TObjectPtr<AWarriorCharacterBase> WarriorCharacterBase = nullptr;

	UPROPERTY(Transient)
	TObjectPtr<UCharacterMovementComponent> CharacterMovementComponent = nullptr;

	UPROPERTY(Transient, VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed = 0.f;

	UPROPERTY(Transient, VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration = false;
};
