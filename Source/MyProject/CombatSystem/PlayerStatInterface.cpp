#include "PlayerStatInterface.h"


	void UPlayerStatInterface::setProperty_Implementation(const FString &key, float value)
	{
	}
	void UPlayerStatInterface::incrementProperty_Implementation(const FString &key, float increment)
	{
	}
	float UPlayerStatInterface::getProperty_Implementation(const FString &key) const
	{
		return 0.0f;
	}
	bool UPlayerStatInterface::hasProperty_Implementation(const FString &key) const
	{
		return false;
	}