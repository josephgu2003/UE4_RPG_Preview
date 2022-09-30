// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "PlayerStat.h"
#include "../CombatSystem/PlayerStatInterface.h"
#include "UObject/NoExportTypes.h"
#include "PlayerStatAdaptor.generated.h"

/**
 * Strategy pattern haha.
 */
UCLASS(Blueprintable)
class MYPROJECT_API UPlayerStatAdaptor : public UPlayerStatInterface
{
    GENERATED_BODY()
protected:
    UPROPERTY(BlueprintReadWrite)
    TMap<FString, UPlayerStat *> statMap;

public:
    void setProperty_Implementation(const FString &key, float value) override;

    void incrementProperty_Implementation(const FString &key, float increment) override;

    float getProperty_Implementation(const FString &key) const override;

    bool hasProperty_Implementation(const FString &key) const override;
};
