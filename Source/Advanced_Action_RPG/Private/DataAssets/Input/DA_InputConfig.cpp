// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/Input/DA_InputConfig.h"

UInputAction* UDA_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InInputTag) const
{
	for (const FInputActionConfig& CurrentInputAction : NativeInputActions)
	{
		if (CurrentInputAction.InputTag == InInputTag && CurrentInputAction.InputAction)
		{
			return CurrentInputAction.InputAction;
		}
	}

	return nullptr;
}
