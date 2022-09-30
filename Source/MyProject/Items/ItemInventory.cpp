// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemInventory.h"


bool UItemInventory::HasItemByID(FName ID) {
	for (FItemEntry& i : Items) {
		if (i.Item.ItemID == ID) {
			return true;
		}
	}
	return false;
}


int32 UItemInventory::GetItemCountByID(FName ID) {
	for (FItemEntry& i : Items) {
		if (i.Item.ItemID == ID) {
			return i.Count;
		}
	}
	return 0;
}


void UItemInventory::AddItem(FGameItem Item) {
	for (FItemEntry& i : Items) {
		if (i.Item.ItemID == Item.ItemID) {
			i.Count += 1;
			return;
		}
	}
	Items.Emplace(Item, 1);
}


void UItemInventory::RemoveItemByID(FName ID) {
	for (int i = 0; i < Items.Num(); i ++) {
		FItemEntry& itemEntry = Items[i];
		if (itemEntry.Item.ItemID == ID) {
			itemEntry.Count -= 1;
			if (itemEntry.Count == 0) {
				Items.RemoveAt(i);
			}
			return;
		}
	}
}

const TArray<FItemEntry>& UItemInventory::GetItems() {
	return Items;
}