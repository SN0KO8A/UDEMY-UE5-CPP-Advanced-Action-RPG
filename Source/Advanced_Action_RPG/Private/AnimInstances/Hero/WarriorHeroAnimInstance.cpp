// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/WarriorHeroAnimInstance.h"

#include "Characters/WarriorCharacterHero.h"

void UWarriorHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	WarriorCharacterHero = Cast<AWarriorCharacterHero>(TryGetPawnOwner());
}

void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		TimeElapsed = 0.f;
		bShouldEnterRelaxedState = false;
	}
	else
	{
		TimeElapsed += DeltaSeconds;
		bShouldEnterRelaxedState = TimeElapsed >= EnterRelaxedStateTimeTreshold;
	}
}
