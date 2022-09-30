// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleLvlFormula.h"
	#include "GenericPlatform/GenericPlatformMath.h"

int32 USimpleLvlFormula::calculateNewLevel_Implementation(int32 currentLvl,
 int32 expAtCurrentLvl) const {
     int nextLvl = currentLvl;
     int nextThreshold = pow(nextLvl * 6, 3.0);
     while (expAtCurrentLvl >= nextThreshold) {
        nextLvl++;
        expAtCurrentLvl -= nextThreshold;
        nextThreshold = pow(nextLvl * 6, 3.0);
     }
     return nextLvl;
 }