// Fill out your copyright notice in the Description page of Project Settings.


#include "Uberwaffen/Controller/MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// 1. Настройка коллизии (размеры капсулы по умолчанию обычно подходят)
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	// 2. НАСТРОЙКА ВРАЩЕНИЯ ДЛЯ FIRST PERSON
	// Мы хотим, чтобы персонаж поворачивался всем телом (Yaw) вслед за мышкой.
	bUseControllerRotationPitch = false; // Камера наклоняется, тело - нет
	bUseControllerRotationYaw = true;   // ТЕЛО ПОВОРАЧИВАЕТСЯ ВЛЕВО/ВПРАВО
	bUseControllerRotationRoll = false;

	// 3. Создание и настройка камеры
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	// Привязываем камеру к капсуле
	PlayerCamera->SetupAttachment(GetCapsuleComponent());
	// Позиционируем камеру на уровне глаз (примерно)
	PlayerCamera->SetRelativeLocation(FVector(0.f, 0.f, 64.f));

	// ВАЖНО: Камера должна использовать вращение контроллера для осмотра
	PlayerCamera->bUsePawnControlRotation = true;

	// 4. Настройка передвижения (базовая)
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Для FPS нам НЕ нужно ориентировать вращение на движение
	GetCharacterMovement()->bOrientRotationToMovement = false;

}

void AMyCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AMyCharacter::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

