// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Array.h"
#include "GameItem.h"
#include "ItemInventory.generated.h"

struct ItemEntry {
	FGameItem item;
	int32 count;

	ItemEntry(const FGameItem& item_, int32 count_) {
		item = item_;
		count = count_;
	}
};

/**
 * Container for items.
 */
UCLASS(BlueprintType)
class MYPROJECT_API UItemInventory : public UObject
{
	GENERATED_BODY()
private:
	UPROPERTY()
	TArray<FItemEntry> Items; // Invariant : each item entry must have >= 1 count, no duplicate entries

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Items")
		bool HasItemByID(FName ID);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Items")
		int32 GetItemCountByID(FName ID);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Items")
		const TArray<FItemEntry>& GetItems();

	UFUNCTION(BlueprintCallable, Category = "Items")
		void AddItem(FGameItem Item);

	UFUNCTION(BlueprintCallable, Category = "Items")
		void RemoveItemByID(FName ID);
};
