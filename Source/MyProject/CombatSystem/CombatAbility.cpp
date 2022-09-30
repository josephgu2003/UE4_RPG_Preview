#include "CombatAbility.h"
#include "AbilityInteraction.h"
#include "AbilityComponent.h"

void UCombatAbility::TryActivate(UAbilityComponent* owner)
{
	if (CanActivate())
	{
		AbilityActivate(owner);
	}
}

void UCombatAbility::Dissipate() {
	endAbilityDelegate.Broadcast(this);
	OnDissipate();
}


void UCombatAbility::AbilityActivate(UAbilityComponent* owner) {
	ownerSystem = owner;
	abilityPower = InitAbilityPower();
	OnAbilityActivate();
}

AActor* UCombatAbility::SpawnActorDeferred
(
	UClass* Class,
	const FTransform& transform) {
	if (ownerSystem) {
		return ownerSystem->SpawnActorDeferred(Class, transform);
	}
	else {
		return nullptr;
	}
}

AActor* UCombatAbility::FinishSpawning(AActor* actor, const FTransform& spawnTransform) {
	if (ownerSystem) {
		return ownerSystem->FinishSpawning(actor, spawnTransform);
	}
	else {
		return nullptr;
	}
}

void UCombatAbility::BeginInteractionWith(UCombatAbility* other, UAbilityInteraction* interaction_) {
	// assumes one ability will begin the interaction first, the second call is nullified
	if (!interaction) {
		interaction = interaction_;
		other->interaction = interaction;
		interaction->abilityOne = this;
		interaction->abilityTwo = other;
		interaction->InitInteraction();
	}
}