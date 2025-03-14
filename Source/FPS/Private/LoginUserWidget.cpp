// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginUserWidget.h"

#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void ULoginUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if(LoginButton)
	{
		LoginButton->OnClicked.AddDynamic(this, &ULoginUserWidget::OnLoginButtonClick);
	}
}

void ULoginUserWidget::OnLoginButtonClick()
{
	FString StatusString;
	FSlateColor StatusTextColor;
	if(Validate())
	{
		StatusString = TEXT("Login Successfully!");
		StatusTextColor = FColor::Green;
		UGameplayStatics::OpenLevel(GetWorld(), TEXT("FirstPersonalMap"));
	}
	else
	{
		StatusString = TEXT("UserName or Password Error!");
		StatusTextColor = FColor::Red;
		// clean text box
		PasswordTextBox->SetText(FText::FromString(""));
	}
	StatusText->SetVisibility(ESlateVisibility::Visible);
	StatusText->SetText(FText::FromString(StatusString));
	StatusText->SetColorAndOpacity(StatusTextColor);
	
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	// has timer, then clean
	if(TimerManager.IsTimerActive(StatusTextCleanTimerHandle))
	{
		TimerManager.ClearTimer(StatusTextCleanTimerHandle);
	}
	// set new timer to clean status text
	TimerManager.SetTimer(StatusTextCleanTimerHandle, this, &ULoginUserWidget::CleanStatusText, 3,
	                                       false);
}

bool ULoginUserWidget::Validate() const
{
	if(!UserNameTextBox || !PasswordTextBox)
	{
		return false;
	}
	
	FString UserName = UserNameTextBox->GetText().ToString();
	FString Password = PasswordTextBox->GetText().ToString();
	if(UserName == this->DefaultUserName && Password == this->DefaultPassword)
	{
		return true;
	}
	return false;
}

void ULoginUserWidget::CleanStatusText()
{
	if(StatusText)
	{
		StatusText->SetText(FText::FromString(""));
	}
}
