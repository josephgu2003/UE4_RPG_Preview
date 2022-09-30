#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "PlayerChoice.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ChoiceExecBase.generated.h"

class AStoryScene;
class UPlayerChoice;
class UObject;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FChoiceExecPin);

USTRUCT() struct FUseless {GENERATED_BODY()};

UCLASS()
class MYPROJECT_API UChoiceExecBase : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
protected:
	UPROPERTY()
	TArray<UPlayerChoice*> choices;

	AStoryScene* scene;

	virtual void RecieveFire(int i) {}

protected:
	UFUNCTION()
	void HandleChoices(UPlayerChoice* choice);


	void AddChoice(FChoiceExecPin pin, FString choiceName, UObject* parent) {
		UPlayerChoice* choice = NewObject<UPlayerChoice>(parent);
		choice->choiceName = choiceName;
		choice->result.BindDynamic(this, &UChoiceExecBase::HandleChoices);

		if (choice) {
			choices.Add(choice);
		}
	}
public:
	virtual void Activate() override;
};

