// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProgressionFormula.h"
#include "PlayerStatsProgression.generated.h"

/**
 * A progression tracker for a single stat based on lvls and exp.
 */
UCLASS(BLueprintType)
class MYPROJECT_API UPlayerStatsProgression : public UObject
{
	GENERATED_BODY()
private:
	UPROPERTY()
	int32 exp;

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UProgressionFormula> expFormulaClass;

	UPROPERTY(BlueprintReadWrite)
	UObject* stats;
public:
	UPlayerStatsProgression();

	UFUNCTION(BlueprintCallable, Category = "Player Stats")
	void addExp(int32 xp);

	UFUNCTION(BlueprintCallable, Category = "Player Stats")
	void minusExp(int32 xp);
};
