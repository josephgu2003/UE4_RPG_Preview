#pragma once

#include "CoreMinimal.h"
#include "PlayerStatInterface.h"
#include "AbilityEffect.generated.h"

class UPlayerStats;
class UAbilityComponent;

UCLASS(Blueprintable)
class MYPROJECT_API UAbilityEffect : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category = "Combat", Meta = (ExposeOnSpawn = "true"))
		int32 effectPower = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Combat", Meta = (ExposeOnSpawn = "true"))
		float duration = 0.0f;
public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Combat")
		void ApplyEffect(UAbilityComponent* target, UPlayerStatInterface* playerStatInterface);
};
