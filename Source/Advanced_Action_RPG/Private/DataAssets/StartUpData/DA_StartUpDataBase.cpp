// Fill out your copyright notice in the Description page of Project Settings.

#include "DataAssets/StartUpData/DA_StartUpDataBase.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "GameplayAbilitySpec.h"

void UDA_StartUpDataBase::GiveAbilityToComponent(UWarriorAbilitySystemComponent* AbilitySystemComponent, int32 AbilityLevel)
{
	GiveAbilityToComponent_Internal(ActivateOnGivenAbilities, AbilitySystemComponent, AbilityLevel);
	GiveAbilityToComponent_Internal(ReactiveAbilities, AbilitySystemComponent, AbilityLevel);
}

void UDA_StartUpDataBase::GiveAbilityToComponent_Internal(const TArray<TSubclassOf<UWarriorGameplayAbility>>& Abilities, UWarriorAbilitySystemComponent* AbilitySystemComponent, int32 AbilityLevel)
{
	if (!IsValid(AbilitySystemComponent))
	{
		ensureAlwaysMsgf(false, TEXT("UDA_StartUpDataBase::GiveAbilityToComponent_Internal called with invalid AbilitySystemComponent"));
		return;
	}

	for (const TSubclassOf<UWarriorGameplayAbility>& Ability : Abilities)
	{
		if (!IsValid(Ability))
		{
			ensureAlwaysMsgf(false, TEXT("UDA_StartUpDataBase::GiveAbilityToComponent_Internal called with invalid Ability in Abilities array"));
			continue;
		}

		FGameplayAbilitySpec CurrentAbilitySpec(Ability);
		CurrentAbilitySpec.SourceObject = AbilitySystemComponent->GetAvatarActor();
		CurrentAbilitySpec.Level = AbilityLevel;

		AbilitySystemComponent->GiveAbility(CurrentAbilitySpec);
	}
}
