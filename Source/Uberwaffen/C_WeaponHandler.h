// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "C_WeaponHandler.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Melee,
	Ranged,
	Disposable
};
UENUM(BlueprintType)
enum class EDamagePatterm : uint8
{
	Single,
	FullAuto
};
USTRUCT(BlueprintType)
struct FWeaponItem: public FTableRowBase
{
	GENERATED_USTRUCT_BODY();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString ItemName;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString ItemDescription;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* ItemImage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USkeletalMesh* ViewportMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EDamagePatterm DamagePattern;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EWeaponType WeaponType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MaxAmmo;
	UPROPERTY(BlueprintReadWrite, AdvancedDisplay)
	int currentAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USoundBase* PewSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float shootCooldown;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float shootWarmup;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UBERWAFFEN_API UC_WeaponHandler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UC_WeaponHandler();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
