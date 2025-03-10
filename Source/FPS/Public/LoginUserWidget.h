// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginUserWidget.generated.h"

class UTextBlock;
class UEditableTextBox;
class UButton;
/**
 * 
 */
UCLASS()
class FPS_API ULoginUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnLoginButtonClick();

	/** Validate UserName and Password with default */
	UFUNCTION()
	bool Validate() const;

	FString DefaultUserName = "bo";
	FString DefaultPassword = "123";

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* LoginButton;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UEditableTextBox* UserNameTextBox;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UEditableTextBox* PasswordTextBox;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* StatusText;				/* 登录状态消息 */
	
};
