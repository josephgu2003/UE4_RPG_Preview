#pragma once

#include "CoreMinimal.h"
#include "AbilityEntry.generated.h"

class UTexture2D;
class UCombatAbility;

/**
 * A game item as in the inventory.
 */
USTRUCT(BlueprintType)
struct FAbilityEntry
{
	GENERATED_BODY()

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
		TSubclassOf<UCombatAbility> AbiltiyClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
		FText Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
		FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
		UTexture2D* AbilityIcon;
};
