// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "FPSCharacter.h"
#include "TargetCubeComponent.h"
#include "Runtime/Core/Tests/Containers/TestUtils.h"
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
	SetImportantCubeTarget();
}

void AFPSGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(float RemainingTime = GameState->GetRemainingTime(); RemainingTime > 0.0f)
	{
		RemainingTime -= DeltaTime;
		GameState->SetRemainingTime(RemainingTime);
		FString RemainingTimeMessage = FString::Printf(TEXT("Remaining Time: %.2f"), GameState->GetRemainingTime());
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Blue, RemainingTimeMessage);
		if(RemainingTime < 0)
		{
			GameOver();	
		}
	}
}

void AFPSGameMode::SetImportantCubeTarget()
{
	UWorld* World = GetWorld();
	if(!World) return;
	
	TArray<UTargetCubeComponent*> TargetCubeComponents;
	for(TObjectIterator<UTargetCubeComponent> It; It; ++It)
	{
		if(It->GetWorld() == World)
		{
			TargetCubeComponents.Add(*It);
		}
	}
	
	if(TargetCubeComponents.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Get 0 TargetCubeComponent!"));
		return;
	}
	Test::Shuffle(TargetCubeComponents);
	for(int32 i = 0; i < ImportantCubeCount; i++)
	{
		TargetCubeComponents[i]->SetImportant();
		// Set Important Cube Red Color to Recognize
		UStaticMeshComponent* StaticMeshComponent = TargetCubeComponents[i]->GetOwner()->GetComponentByClass<UStaticMeshComponent>();
		if(!StaticMeshComponent || !StaticMeshComponent->GetMaterial(0))
		{
			return;
		}
		UMaterialInstanceDynamic* DynamicMaterial = StaticMeshComponent->CreateAndSetMaterialInstanceDynamic(0);
		if(DynamicMaterial)
		{
			DynamicMaterial->SetVectorParameterValue(TEXT("BaseColor"), FLinearColor::Red);
		}
	}
}

void AFPSGameMode::GameOver()
{
	UE_LOG(LogTemp, Warning, TEXT("Game Over"));
	// Pause Game
	if(APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		SetPause(PlayerController);
	}
	// Show Game Over Score
	FString ScoreMessage = FString::Printf(TEXT("Your Score: %d"), GameState->GetScore());
	GEngine->AddOnScreenDebugMessage(-1, INFINITY, FColor::Red, ScoreMessage);
}

