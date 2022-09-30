
#pragma once

#include "CoreMinimal.h"
#include "PlayerStatInterface.generated.h"

UCLASS(BlueprintType)
class MYPROJECT_API UPlayerStatInterface : public UObject
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Player Stats")
	void setProperty(const FString &key, float value);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Player Stats")
	void incrementProperty(const FString &key, float increment);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure, Category = "Player Stats")
	float getProperty(const FString &key) const;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure, Category = "Player Stats")
	bool hasProperty(const FString &key) const;
};
