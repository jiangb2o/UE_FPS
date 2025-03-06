// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPSGameMode::AFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.01f;
}

void AFPSGameMode::BeginPlay()
{
	Super::BeginPlay();
	GameState = GetWorld()->GetGameState<AFPSGameStateBase>();
}

void AFPSGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float RemainingTime = GameState->GetRemainingTime();
	GameState->SetRemainingTime(RemainingTime - DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Remaining Time: %.2f"), GameState->GetRemainingTime());
}

