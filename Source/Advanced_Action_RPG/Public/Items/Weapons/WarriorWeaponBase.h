// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WarriorWeaponBase.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class ADVANCED_ACTION_RPG_API AWarriorWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	AWarriorWeaponBase();

	FORCEINLINE UBoxComponent* GetBoxComponent() const { return WeaponCollider; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon Base")
	TObjectPtr<UStaticMeshComponent> WeaponMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon Base")
	TObjectPtr<UBoxComponent> WeaponCollider = nullptr;
};
