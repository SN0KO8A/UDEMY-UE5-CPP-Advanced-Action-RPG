// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/WarriorCharacterBase.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/WarriorAttributeSet.h"
#include "DataAssets/StartUpData/DA_StartUpDataBase.h"

AWarriorCharacterBase::AWarriorCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	WarriorAbilitySystemComponent = CreateDefaultSubobject<UWarriorAbilitySystemComponent>(TEXT("WarriorAbilitySystemComponent"));
	WarriorAttributeSet = CreateDefaultSubobject<UWarriorAttributeSet>(TEXT("WarriorAttributeSet"));
}

UAbilitySystemComponent* AWarriorCharacterBase::GetAbilitySystemComponent() const
{
	return WarriorAbilitySystemComponent;
}

void AWarriorCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!IsValid(NewController) || !IsValid(WarriorAbilitySystemComponent))
	{
		ensureMsgf(false, TEXT("%s called with invalid NewController or WarriorAbilitySystemComponent"), ANSI_TO_TCHAR(__FUNCTION__));
		return;
	}

	WarriorAbilitySystemComponent->InitAbilityActorInfo(this, this);

	if (StartUpData.IsNull())
	{
		ensureMsgf(false, TEXT("%s called but StartUpData is not set. Please set it to a valid UDA_StartUpDataBase asset."), ANSI_TO_TCHAR(__FUNCTION__));
		return;
	}

	if (UDA_StartUpDataBase* StartUpDataAsset = StartUpData.LoadSynchronous())
	{
		StartUpDataAsset->GiveAbilityToComponent(WarriorAbilitySystemComponent);
	}
	else
	{
		ensureMsgf(false, TEXT("%s failed to load StartUpData asset. Please make sure the asset is valid and can be loaded."), ANSI_TO_TCHAR(__FUNCTION__));
	}
}
