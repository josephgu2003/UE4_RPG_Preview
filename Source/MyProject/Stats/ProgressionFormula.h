// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProgressionFormula.generated.h"

/**
 * Strategy pattern haha.
 */
UCLASS()
class MYPROJECT_API UProgressionFormula : public UObject
{
	GENERATED_BODY()
	public:
	// where exp at current lvl means that at initial entering of lvl, exp = 0
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category = "Player Stats")
	int32 calculateNewLevel(int32 currentLvl, int32 expAtCurrentLvl) const;

	virtual int32 calculateNewLevel_Implementation(int32 currentLvl, int32 expAtCurrentLvl) const {
		return 0;
	}
};
