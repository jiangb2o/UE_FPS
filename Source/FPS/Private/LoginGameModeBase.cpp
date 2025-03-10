// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginGameModeBase.h"

#include "LoginUserWidget.h"
#include "Blueprint/UserWidget.h"

ALoginGameModeBase::ALoginGameModeBase()
	: Super()
{
	static ConstructorHelpers::FClassFinder<ULoginUserWidget> LoginUserWidgetClassFinder(TEXT("/Game/FirstPerson/Blueprints/UMG/WBP_Login"));
	if(LoginUserWidgetClassFinder.Succeeded())
	{
		LoginUserWidgetClass = LoginUserWidgetClassFinder.Class;
	}
}

void ALoginGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	if(LoginUserWidgetClass)
	{
		LoginUserWidget = CreateWidget<ULoginUserWidget>(GetWorld(), LoginUserWidgetClass);
		if(LoginUserWidget)
		{
			LoginUserWidget->AddToViewport();
		}
	}
	
}
