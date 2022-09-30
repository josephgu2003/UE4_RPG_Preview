// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerChoiceWidget.generated.h"

class UPlayerChoice;

/**
 *
 */
UCLASS()
class MYPROJECT_API UPlayerChoiceWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

public:

	UFUNCTION(BlueprintImplementableEvent)
		void init(UPARAM(ref) TArray<UPlayerChoice*>& choices);

	UFUNCTION(BlueprintImplementableEvent)
		void clearWidget();
};
