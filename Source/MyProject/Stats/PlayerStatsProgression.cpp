// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatsProgression.h"

	UPlayerStatsProgression::UPlayerStatsProgression() {
        exp = 0;
    }

	void UPlayerStatsProgression::addExp(int32 xp) {
        UProgressionFormula *formula =
				NewObject<UProgressionFormula>(this, expFormulaClass);

                if (formula) {
                    int newLvl = formula->calculateNewLevel(0, xp + 0);
                }
    }

	void UPlayerStatsProgression::minusExp(int32 xp) {

    }