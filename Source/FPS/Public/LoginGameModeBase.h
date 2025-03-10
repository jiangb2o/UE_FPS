// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LoginGameModeBase.generated.h"

class ULoginUserWidget;
/**
 * 
 */
UCLASS()
class FPS_API ALoginGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ALoginGameModeBase();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	ULoginUserWidget* LoginUserWidget;

	TSubclassOf<ULoginUserWidget> LoginUserWidgetClass;
};
