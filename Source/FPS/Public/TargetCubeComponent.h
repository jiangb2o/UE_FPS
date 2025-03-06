// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TargetCubeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class FPS_API UTargetCubeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTargetCubeComponent();
	void TakeHit();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	uint8 bImportant:1;
	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.1", ClampMax = "1.0"))
	float HitScaleFactor;
	
};
