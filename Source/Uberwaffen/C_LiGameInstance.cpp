// Fill out your copyright notice in the Description page of Project Settings.


#include "C_LiGameInstance.h"
#include "MoviePlayer.h"
#include "Slate.h"
#include "Runtime/UMG/Public/UMG.h" 

void UC_LiGameInstance::Init()
{
    Super::Init();

    FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UC_LiGameInstance::BeginLoadingScreen);
    FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UC_LiGameInstance::EndLoadingScreen);
}

void UC_LiGameInstance::BeginLoadingScreen(const FString& InMapName)
{
    if (!IsRunningDedicatedServer())
    {
        FLoadingScreenAttributes LoadingScreen;
        LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
        UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenWidget);
        LoadingScreen.WidgetLoadingScreen = Widget->TakeWidget();

        GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
    }
}

void UC_LiGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{

}
