#pragma once

#include "CoreMinimal.h"
#include "AbilityIntentListener.generated.h"

class UCombatAbility;

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UAbilityIntentListener : public UInterface
{
	GENERATED_BODY()

};

class MYPROJECT_API IAbilityIntentListener
{
	GENERATED_BODY()

public:
	/*
	* Process the ability intent, return true if the ability should be allowed to cast.
	*/
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Combat")
		bool ProcessAbilityIntent(UCombatAbility* ability);
};

// right now anyone can make an intent listener and add it, doesn't need to be a buff...
// which is okay
// if want to restrict, pass the buff container to the ability/buff wanting to register