// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/WarriorCharacterAnimInstance.h"

#include "Characters/WarriorCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

void UWarriorCharacterAnimInstance::NativeInitializeAnimation()
{
	WarriorCharacterBase = Cast<AWarriorCharacterBase>(TryGetPawnOwner());

	if (WarriorCharacterBase)
	{
		CharacterMovementComponent = WarriorCharacterBase->GetCharacterMovement();
	}
}

void UWarriorCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!WarriorCharacterBase || !CharacterMovementComponent)
	{
		return;
	}

	GroundSpeed = WarriorCharacterBase->GetVelocity().Size2D();
	bHasAcceleration = CharacterMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}