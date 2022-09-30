// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AbilityInteraction.generated.h"

class UCombatAbility;

/**
 * An interaction between two abilities.
 */
UCLASS(Blueprintable)
class MYPROJECT_API UAbilityInteraction : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Combat")
		void InitInteraction();

	UPROPERTY(BlueprintReadOnly)
		UCombatAbility* abilityOne;

	UPROPERTY(BlueprintReadOnly)
		UCombatAbility* abilityTwo;
	
};
