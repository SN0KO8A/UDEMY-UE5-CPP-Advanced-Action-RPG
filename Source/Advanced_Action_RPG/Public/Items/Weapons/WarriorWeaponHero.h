// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items/Weapons/WarriorWeaponBase.h"

#include "WarriorWeaponHero.generated.h"

UCLASS()
class ADVANCED_ACTION_RPG_API AWarriorWeaponHero : public AWarriorWeaponBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWarriorWeaponHero();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
