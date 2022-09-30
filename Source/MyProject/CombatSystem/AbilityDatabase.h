#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Containers/Array.h"
#include "AbilityEntry.h"
#include "AbilityDatabase.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class MYPROJECT_API UAbilityDatabase : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
		TArray<FAbilityEntry> Items;
};
