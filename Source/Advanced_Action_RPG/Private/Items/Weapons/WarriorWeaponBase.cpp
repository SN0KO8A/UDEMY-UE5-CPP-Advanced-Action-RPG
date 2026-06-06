// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Weapons/WarriorWeaponBase.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

AWarriorWeaponBase::AWarriorWeaponBase()
{
 	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	WeaponCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionBox"));
	WeaponCollider->SetupAttachment(GetRootComponent());
	WeaponCollider->SetBoxExtent(FVector(20.0f));
	WeaponCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
