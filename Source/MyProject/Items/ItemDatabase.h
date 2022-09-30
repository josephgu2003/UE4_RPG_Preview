// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Containers/Array.h"
#include "GameItem.h"
#include "ItemDatabase.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MYPROJECT_API UItemDatabase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Items")
	TArray<FGameItem> Items;
};
