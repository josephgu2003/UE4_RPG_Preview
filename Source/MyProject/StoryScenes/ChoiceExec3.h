#pragma once

#include "CoreMinimal.h"
#include "ChoiceExecBase.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ChoiceExec3.generated.h"

class UPlayerChoice;

/**
 *
 */
UCLASS()
class MYPROJECT_API UChoiceExec3 : public UChoiceExecBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
		FChoiceExecPin PinOne;
	UPROPERTY(BlueprintAssignable)
		FChoiceExecPin PinTwo;
	UPROPERTY(BlueprintAssignable)
		FChoiceExecPin PinThree;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "Scene")
		static UChoiceExec3* DecisionThree(FString choiceOne, FString choiceTwo, FString choiceThree, AStoryScene* scene_);

	virtual void RecieveFire(int i) override {
		if (i == 0) {
			PinOne.Broadcast();
		}
		if (i == 1) {
			PinTwo.Broadcast();
		}
		if (i == 2) {
			PinThree.Broadcast();
		}
	}
};