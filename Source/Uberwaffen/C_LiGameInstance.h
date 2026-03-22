// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "C_LiGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UBERWAFFEN_API UC_LiGameInstance : public UGameInstance
{
	GENERATED_BODY()
    public:
        virtual void Init() override;
    
        UFUNCTION()
        virtual void BeginLoadingScreen(const FString& MapName);
        UFUNCTION()
        virtual void EndLoadingScreen(UWorld* InLoadedWorld);
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Loading Screen")
        TSubclassOf<class UUserWidget> LoadingScreenWidget;
};
