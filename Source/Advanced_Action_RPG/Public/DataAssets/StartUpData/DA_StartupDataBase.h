// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_StartUpDataBase.generated.h"

class UWarriorGameplayAbility;
class UWarriorAbilitySystemComponent;

UCLASS()
class ADVANCED_ACTION_RPG_API UDA_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	virtual void GiveAbilityToComponent(UWarriorAbilitySystemComponent* AbilitySystemComponent, int32 AbilityLevel = 1);

protected:
	void GiveAbilityToComponent_Internal(const TArray<TSubclassOf<UWarriorGameplayAbility>>& Abilities, UWarriorAbilitySystemComponent* AbilitySystemComponent, int32 AbilityLevel = 1);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Startup Data Base")
	TArray<TSubclassOf<UWarriorGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Startup Data Base")
	TArray<TSubclassOf<UWarriorGameplayAbility>> ReactiveAbilities;
};
