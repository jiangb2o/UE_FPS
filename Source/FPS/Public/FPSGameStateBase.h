// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FPSGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API AFPSGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "GameState")
	int32 GetScore() const;
	UFUNCTION(BlueprintCallable, Category = "GameState")
	void SetScore(int32 Value);
	UFUNCTION(BlueprintCallable, Category = "GameState")
	float GetTimePassed() const;
	UFUNCTION(BlueprintCallable, Category = "GameState")
	void SetTimePassed(float Value);

private:
	UPROPERTY(VisibleAnywhere)
	int32 Score;
	UPROPERTY(VisibleAnywhere)
	float TimePassed;
};
