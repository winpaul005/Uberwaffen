// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "Controller/MyCharacter.h"
#include "Controller/MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
    PlayerControllerClass = AMyPlayerController::StaticClass();
    DefaultPawnClass = AMyCharacter::StaticClass();
}

