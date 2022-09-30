// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Containers/Array.h"
#include "PlayerStatInterface.h"
#include "GameplayTagContainer.h"
#include "AbilityComponent.generated.h"

class UCombatAbility;
class UAbilityEffect;
class IAbilityIntentListener;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAbilityActivatedDelegate, UCombatAbility*, Ability);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYPROJECT_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	UPROPERTY()
		TArray<TSubclassOf<UCombatAbility>> availableAbilities;

	UPROPERTY()
		TArray<UCombatAbility*> activeAbilities;

	UPROPERTY()
		TArray<TScriptInterface<IAbilityIntentListener>> abilityIntentListeners;

	UPROPERTY()
		FGameplayTagContainer blockedAbilityTags;

	void OnAbilityEnd(UCombatAbility* ability);

	bool processAbility(UCombatAbility* ability);

public:
	// Sets default values for this component's properties
	UAbilityComponent();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPlayerStatInterface* stats;
protected:

public:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(BlueprintReadWrite)
		bool BlockAllAbilities;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Combat")
		FAbilityActivatedDelegate abilityActivatedDelegate;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Combat")
		FAbilityActivatedDelegate abilityDissipatedDelegate;

	UFUNCTION(BlueprintCallable, Category = "Combat")
		void GiveAbility(TSubclassOf<UCombatAbility> ability);

	UFUNCTION(BlueprintCallable, Category = "Combat")
		void CallAbility(TSubclassOf<UCombatAbility> ability);

	UFUNCTION(BlueprintCallable, Category = "Combat")
		bool TakeAbilityAndCall(UCombatAbility* ability);

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void ApplyAbilityEffect(UCombatAbility* ability, UAbilityEffect* effect);

	AActor* SpawnActorDeferred(UClass* Class, const FTransform& transform);

	AActor* FinishSpawning(AActor* actor, const FTransform& spawnTransform);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Combat")
		bool AbilityIsActive(TSubclassOf<UCombatAbility> ability);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Combat")
		bool AbilityWithTagIsActive(FGameplayTag tag, bool exactMatch);

	UFUNCTION(BlueprintCallable, Category = "Combat")
		void AddAbilityIntentListener(UPARAM(ref) TScriptInterface<IAbilityIntentListener>& listener);

	UFUNCTION(BlueprintCallable, Category = "Combat")
		void RemoveAbilityIntentListener(UPARAM(ref) TScriptInterface<IAbilityIntentListener>& listener);

	/**
	UFUNCTION(BlueprintCallable, Category = "Combat")
		void BlockAbilitiesWithTag(FGameplayTag& tag);
	UFUNCTION(BlueprintCallable, Category = "Combat")
		void UnBlockAbilitiesWithTag(FGameplayTag& tag);
	UFUNCTION(BlueprintCallable, Category = "Combat")
		void UnBlockAllAbilities();**/
};
