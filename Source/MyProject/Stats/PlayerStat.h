// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerStat.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStatHitZeroDelegate);

UCLASS(BlueprintType)
class MYPROJECT_API UPlayerStat : public UObject
{
    GENERATED_BODY()
private:
    float value;

public:
    UPlayerStat();

    UFUNCTION(BlueprintCallable, Category = "Player Stats")
    void setValue(float newVal);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Player Stats")
    float getValue() const;

    UFUNCTION(BlueprintCallable, Category = "Player Stats")
    void incrementValue(float inc);

    UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Player Stats")
        FStatHitZeroDelegate zeroDelegate;
};