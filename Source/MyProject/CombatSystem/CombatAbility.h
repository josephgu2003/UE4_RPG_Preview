#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "CombatAbility.generated.h"

class UCombatAbility;
class AActor;

DECLARE_MULTICAST_DELEGATE_OneParam(FEndAbilityDelegate, UCombatAbility*);

class UAbilityComponent;
class UAbilityInteraction;

UCLASS(Blueprintable)
class MYPROJECT_API UCombatAbility : public UObject, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

private:
	UPROPERTY()
		UAbilityInteraction* interaction; // invariant : assume this is always in sync with the another ability's interaction field
		// current limitations: only one interaction, who dafuq owns it for GC collection 

protected:
	UPROPERTY(BlueprintReadOnly)
		int32 abilityPower;

	UFUNCTION(BlueprintCallable, Category = "Combat")
		void BeginInteractionWith(UCombatAbility* other, UAbilityInteraction* interaction_);

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat")
	int32 InitAbilityPower();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Combat")
		void Pierce(UCombatAbility* ability);

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat")
		void OnDissipate();

	// code on activation
	UFUNCTION(BlueprintImplementableEvent, Category = "Combat")
		void OnAbilityActivate();

	UFUNCTION(BlueprintCallable, Category = "Combat")
		AActor* SpawnActorDeferred
		(
			UClass* Class,
			const FTransform& transform);

	UFUNCTION(BlueprintCallable, Category = "Combat")
	AActor* FinishSpawning(AActor* actor, const FTransform& spawnTransform);


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTagContainer abilityTags;
public:
	UPROPERTY(BlueprintReadOnly)
		UAbilityComponent* ownerSystem;

	UFUNCTION(BlueprintCallable, Category = "Combat")
		void Dissipate();

	// can we activate?
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category = "Combat")
		bool CanActivate() const;

	// tries to activate the ability
	void TryActivate(UAbilityComponent* owner);

	void AbilityActivate(UAbilityComponent* owner);

	FEndAbilityDelegate endAbilityDelegate;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override 
	{ TagContainer = abilityTags; return; }

};


// on collision
// directly decrease LP