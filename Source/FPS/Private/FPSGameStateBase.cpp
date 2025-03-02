// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameStateBase.h"

int32 AFPSGameStateBase::GetScore() const
{
	return Score;
}

void AFPSGameStateBase::SetScore(int32 Value)
{
	this->Score = Value;
}

float AFPSGameStateBase::GetTimePassed() const
{
	return TimePassed;
}

void AFPSGameStateBase::SetTimePassed(float Value)
{
	this->TimePassed = Value;
}
