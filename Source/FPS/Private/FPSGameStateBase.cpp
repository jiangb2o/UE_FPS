// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameStateBase.h"

AFPSGameStateBase::AFPSGameStateBase()
	: Super()
{
	Score = 0;
	GameDuration = 0;
	RemainingTime = 0;
}

int32 AFPSGameStateBase::GetScore() const
{
	return Score;
}

void AFPSGameStateBase::SetScore(int32 Value)
{
	this->Score = Value;
	PrintScoreToScreen();
}

float AFPSGameStateBase::GetRemainingTime() const
{
	return RemainingTime;
}

void AFPSGameStateBase::SetRemainingTime(float Value)
{
	this->RemainingTime = Value;
}

void AFPSGameStateBase::PrintScoreToScreen() const
{
	FString ScoreString = FString::Printf(TEXT("Score: %d"), GetScore());
	GEngine->AddOnScreenDebugMessage(2, 5.0f, FColor::Red, ScoreString);
}

void AFPSGameStateBase::InitValuesInBluePrint()
{
	RemainingTime = GameDuration;
}

void AFPSGameStateBase::BeginPlay()
{
	Super::BeginPlay();
	InitValuesInBluePrint();
	SetScore(0);
}
