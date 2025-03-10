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
	AFPSGameStateBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float GameDuration;
	
	UFUNCTION(BlueprintCallable, Category = "GameState")
	int32 GetScore() const;
	UFUNCTION(BlueprintCallable, Category = "GameState")
	void SetScore(int32 Value);
	UFUNCTION(BlueprintCallable, Category = "GameState")
	float GetRemainingTime() const;
	UFUNCTION(BlueprintCallable, Category = "GameState")
	void SetRemainingTime(float Value);
	UFUNCTION(BlueprintCallable, Category = "GameState")
	void PrintScoreToScreen() const;

	/** Get Values Set in Blueprint, Call in BeginPlay */
	void InitValuesInBluePrint();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	int32 Score;			// Player Get Score
	UPROPERTY(VisibleAnywhere)
	float RemainingTime;	// Time Remaining
};
