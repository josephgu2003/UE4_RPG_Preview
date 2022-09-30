// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SubtitleUI.h"
#include "SubtitlesSystem.generated.h"
/**
 *
 */

UCLASS(BlueprintType)
class MYPROJECT_API USubtitlesSystem : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TScriptInterface<ISubtitleUI> subTitleUI;

	UFUNCTION(BlueprintCallable)
	void displaySubtitle(const FString &line, float duration);
};
