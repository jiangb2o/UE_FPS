// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetCubeComponent.h"

// Sets default values for this component's properties
UTargetCubeComponent::UTargetCubeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bImportant = false;
}

void UTargetCubeComponent::TakeHit()
{
	if(AActor* Owner = GetOwner())
	{
		if(bHit == true)
		{
			Owner->Destroy();
			return;
		} 
		bHit = true;
		FVector CurrentScale = Owner->GetActorScale();
		CurrentScale *= HitScaleFactor;
		Owner->SetActorScale3D(CurrentScale);
	}
}

int32 UTargetCubeComponent::GetHitScore() const
{
	return bImportant ? HitScore * 2 : HitScore;
}

void UTargetCubeComponent::SetImportant()
{
	bImportant = true;
}


// Called when the game starts
void UTargetCubeComponent::BeginPlay()
{
	Super::BeginPlay();
}

