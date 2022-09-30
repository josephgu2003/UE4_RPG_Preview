// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilityComponent.h"
#include "CombatAbility.h"
#include "AbilityEffect.h"
#include "AbilityIntentListener.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UAbilityComponent::UAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

// Called when the game starts
void UAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

void UAbilityComponent::GiveAbility(TSubclassOf<UCombatAbility> ability)
{
	for (auto& available : availableAbilities)
	{
		if (available.Get() == ability.Get())
		{
			return; // does this work?
		}
	}
	availableAbilities.Add(ability);
}


bool UAbilityComponent::TakeAbilityAndCall(UCombatAbility* ability) {
	for (auto& available : availableAbilities)
	{
		if (available.Get() == ability->GetClass())
		{
			return processAbility(ability);
		}
	}
	return false;
}


bool UAbilityComponent::processAbility(UCombatAbility* ability) {
	ability->ownerSystem = this;

	// broadcast intent to use ability
	for (auto listener : abilityIntentListeners) {
		if (!IAbilityIntentListener::Execute_ProcessAbilityIntent(listener.GetObject(), ability)) {
			return false;
		}
	}

	if (ability && ability->CanActivate())
	{
		ability->endAbilityDelegate.AddUObject(this, &UAbilityComponent::OnAbilityEnd);
		ability->TryActivate(this);
		activeAbilities.Add(ability);
		// broadcast ability was activated
		abilityActivatedDelegate.Broadcast(ability);
		return true;
	}
	else {
		return false;
	}
}

void UAbilityComponent::CallAbility(TSubclassOf<UCombatAbility> ability)
{
	for (auto &available : availableAbilities)
	{
		if (available.Get() == ability.Get())
		{
			UCombatAbility *newAbility =
				NewObject<UCombatAbility>(this, available);
			processAbility(newAbility);
			return;
		}
	}
}

void UAbilityComponent::OnAbilityEnd(UCombatAbility* ability) {
	activeAbilities.Remove(ability);
	abilityDissipatedDelegate.Broadcast(ability);
}

AActor* UAbilityComponent::SpawnActorDeferred
(
	UClass* Class,
	const FTransform& transform) {
	return GetWorld()->SpawnActorDeferred<AActor>(Class, transform);
}

void UAbilityComponent::ApplyAbilityEffect(UCombatAbility* ability, UAbilityEffect* effect) {
	effect->ApplyEffect(this, stats);
}

AActor* UAbilityComponent::FinishSpawning(AActor* actor, const FTransform& transform) {
	return UGameplayStatics::FinishSpawningActor(actor, transform);
}

bool UAbilityComponent::AbilityIsActive(TSubclassOf<UCombatAbility> ability_) {
	for (auto& ability : activeAbilities) {
		if (ability->GetClass() == ability_.Get()) {
			return true;
		}
	}
	return false;
}

bool UAbilityComponent::AbilityWithTagIsActive(FGameplayTag tag, bool exactMatch) {
	for (auto& ability : activeAbilities) {
		FGameplayTagContainer tags;
		ability->GetOwnedGameplayTags(tags);
		if (exactMatch && tags.HasTagExact(tag)) {
			return true;
		}
		else if (!exactMatch && tags.HasTag(tag)) {
			return true;
		}
	}
	return false;
}


void UAbilityComponent::AddAbilityIntentListener(TScriptInterface<IAbilityIntentListener>& listener) {
	abilityIntentListeners.Add(listener);
}

void UAbilityComponent::RemoveAbilityIntentListener(TScriptInterface<IAbilityIntentListener>& listener) {
	abilityIntentListeners.Remove(listener);
}

void UAbilityComponent::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);

	for (auto& ability : activeAbilities) {
		ability->Dissipate();
	}
}

/**
void UAbilityComponent::BlockAbilitiesWithTag(FGameplayTag& tag) {
	blockedAbilityTags.AddTag(tag);
}

void UAbilityComponent::UnBlockAbilitiesWithTag(FGameplayTag& tag) {
	blockedAbilityTags.RemoveTag(tag);
}

void UAbilityComponent::UnBlockAllAbilities() {
	blockedAbilityTags.Reset();
}**/