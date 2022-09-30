// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ChoiceExecBase.h"
#include "ChoiceExec.generated.h"

class UPlayerChoice;

/**
 * 
 */
UCLASS()
class MYPROJECT_API UChoiceExec : public UChoiceExecBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
		FChoiceExecPin PinOne;
	UPROPERTY(BlueprintAssignable)
		FChoiceExecPin PinTwo;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "Scene")
		static UChoiceExec* DecisionTwo(FString choiceOne, FString choiceTwo, AStoryScene* scene_);

	virtual void RecieveFire(int i) override {
		if (i == 0) {
			PinOne.Broadcast();
		}
		if (i == 1) {
			PinTwo.Broadcast();
		}
	}
};

// Can try extending this and see what happens, or give all of them a common base with some common logic
// these nodes should work for compile time known decisions, if want to add dynamic options, use array method instead
// its difficult to make dynamic options work in graphical mode