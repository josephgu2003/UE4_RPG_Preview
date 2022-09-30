// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProgressionFormula.h"
#include "SimpleLvlFormula.generated.h"

/**
 * For the main Level stat.
 */
UCLASS()
class MYPROJECT_API USimpleLvlFormula : public UProgressionFormula
{
	GENERATED_BODY()
	public:
		// where exp at current lvl means that at initial entering of lvl, exp = 0
	int32 calculateNewLevel_Implementation(int32 currentLvl, int32 expAtCurrentLvl) const;
};
