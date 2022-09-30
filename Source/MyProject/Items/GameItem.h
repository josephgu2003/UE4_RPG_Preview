// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemAction.h"
#include "GameItem.generated.h"

class UTexture2D;
/**
 * A game item as in the inventory.
 */
USTRUCT(BlueprintType)
struct FGameItem
{
	GENERATED_BODY()

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Items")
		FName ItemID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Items")
		FText Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Items")
		FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Items")
		TSubclassOf<UItemAction> Action;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Items")
		UTexture2D* ItemIcon;
};

USTRUCT(BlueprintType)
struct FItemEntry
{
	GENERATED_BODY()

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Items")
		FGameItem Item;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Items")
		int32 Count;

	FItemEntry() {
		Count = 0;
	}

	FItemEntry(const FGameItem& Item_, int32 Count_) {
		Item = Item_;
		Count = Count_;
	}
};