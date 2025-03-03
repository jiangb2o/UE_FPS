// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameStateBase.h"

AFPSGameStateBase::AFPSGameStateBase()
	: Super()
{
	Score = 0;
}

int32 AFPSGameStateBase::GetScore() const
{
	return Score;
}

void AFPSGameStateBase::SetScore(int32 Value)
{
	this->Score = Value;
}

float AFPSGameStateBase::GetRemainingTime() const
{
	return RemainingTime;
}

void AFPSGameStateBase::SetRemainingTime(float Value)
{
	this->RemainingTime = Value;
}

void AFPSGameStateBase::InitValuesInBluePrint()
{
	RemainingTime = GameDuration;
}
