// Fill out your copyright notice in the Description page of Project Settings.


#include "Uberwaffen/Controller/MyPlayerController.h"
#include "Uberwaffen/Controller/MyCharacter.h"

AMyPlayerController::AMyPlayerController()
{
	bShowMouseCursor = false;

	// Настройки захвата мыши (чтобы она не вылетала за пределы окна)
	bEnableClickEvents = false;
	bEnableMouseOverEvents = false;
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent)
	{
		InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::MoveForward);
		InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::MoveRight);
		InputComponent->BindAxis("LookUp", this, &AMyPlayerController::LookUp);
		InputComponent->BindAxis("LookRight", this, &AMyPlayerController::LookRight);
	}
}

void AMyPlayerController::MoveForward(float Value)
{
	// �������� ���������, ������� ���������
	AMyCharacter* Char = Cast<AMyCharacter>(GetPawn());
	if (Char && Value != 0.0f)
	{
		// �������� ������� �������� � ���������
		Char->MoveForward(Value);
	}
}

void AMyPlayerController::MoveRight(float Value)
{
	AMyCharacter* Char = Cast<AMyCharacter>(GetPawn());
	if (Char && Value != 0.0f)
	{
		Char->MoveRight(Value);
	}
}

void AMyPlayerController::LookUp(float Value)
{
	AddPitchInput(Value);
}

void AMyPlayerController::LookRight(float Value)
{
	AddYawInput(Value);
}