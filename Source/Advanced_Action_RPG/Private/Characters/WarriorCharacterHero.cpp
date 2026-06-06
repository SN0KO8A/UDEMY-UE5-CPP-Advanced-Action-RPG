// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/WarriorCharacterHero.h"

#include "Camera/CameraComponent.h"
#include "DataAssets/Input/DA_InputConfig.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/Input/WarriorInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "WarriorGameplayTags.h"
#include "WarriorDebugHelper.h"

AWarriorCharacterHero::AWarriorCharacterHero()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	USceneComponent* CurrentRootComponent = GetRootComponent();

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(CurrentRootComponent);
	SpringArmComponent->TargetArmLength = 200.f;
	SpringArmComponent->SocketOffset = FVector(0.f, 55.f, 65.f);
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;

	UCharacterMovementComponent* CharacterMovementComponent = GetCharacterMovement();
	CharacterMovementComponent->bOrientRotationToMovement = true;
	CharacterMovementComponent->RotationRate = FRotator(0.f, 500.f, 0.f);
	CharacterMovementComponent->MaxWalkSpeed = 400.0f;
	CharacterMovementComponent->BrakingDecelerationWalking = 2000.f;
}

void AWarriorCharacterHero::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void AWarriorCharacterHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (!ensureMsgf(InputConfigDataAsset, TEXT("InputConfigDataAsset is not set on %s. Please set it to a valid UDA_InputConfig asset."), *GetName()))
	{
		return;
	}

	APlayerController* PlayerController = GetController<APlayerController>();
	ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

	if (!ensureMsgf(InputSubsystem, TEXT("InputSubsystem is null on %s. Make sure the controller's local player is valid and has an Enhanced Input Local Player Subsystem."), *GetName()))
	{
		return;
	}

	InputSubsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);
	
	if (UWarriorInputComponent* WarriorInputComponent = Cast<UWarriorInputComponent>(PlayerInputComponent))
	{
		WarriorInputComponent->BindNativeAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &AWarriorCharacterHero::InputMove);
		WarriorInputComponent->BindNativeAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &AWarriorCharacterHero::InputLook);
	}
}

void AWarriorCharacterHero::BeginPlay()
{
	Super::BeginPlay();
	DEBUG_PRINT(TEXT("Hero Begin Play"));
}

void AWarriorCharacterHero::InputMove(const FInputActionValue& InputActionValue)
{
	DEBUG_PRINT_FULL(FString::Printf(TEXT("Move input: %s"), *InputActionValue.Get<FVector2D>().ToString()), FColor::Green, 5.f, 1);

	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotation = FRotator(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if (!FMath::IsNearlyZero(MovementVector.Y))
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (!FMath::IsNearlyZero(MovementVector.X))
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AWarriorCharacterHero::InputLook(const FInputActionValue& InputActionValue)
{
	DEBUG_PRINT_FULL(FString::Printf(TEXT("Look input: %s"), *InputActionValue.Get<FVector2D>().ToString()), FColor::Blue, 5.f, 2);

	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (!FMath::IsNearlyZero(LookAxisVector.X))
	{
		AddControllerYawInput(LookAxisVector.X);
	}

	if (!FMath::IsNearlyZero(LookAxisVector.Y))
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}
