// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/Input/DA_InputConfig.h"
#include "EnhancedInputComponent.h"

#include "WarriorInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCED_ACTION_RPG_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	template<class UserObject, typename CallbackFunction>
	void BindNativeAction(const class UDA_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunction Func);
};

template<class UserObject, typename CallbackFunction>
inline void UWarriorInputComponent::BindNativeAction(const class UDA_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunction Func)
{
	ensureMsgf(InInputConfig, TEXT("Input config data asset is null, can not proceed with binding"));

	if (UInputAction* InputAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(InputAction, TriggerEvent, ContextObject, Func);
	}

}
