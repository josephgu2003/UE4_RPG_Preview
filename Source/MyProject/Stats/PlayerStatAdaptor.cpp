#include "PlayerStatAdaptor.h"

void UPlayerStatAdaptor::setProperty_Implementation(const FString &key, float value)
{
    UPlayerStat *stat = *statMap.Find(key);

    if (stat)
    {
        stat->setValue(value);
    }
}

void UPlayerStatAdaptor::incrementProperty_Implementation(const FString &key, float increment)
{
    UPlayerStat *stat = *statMap.Find(key);

    if (stat)
    {
        stat->incrementValue(increment);
    }
}

float UPlayerStatAdaptor::getProperty_Implementation(const FString &key) const
{
    UPlayerStat *stat = *statMap.Find(key);

    if (stat)
    {
        return stat->getValue();
    }
    else
    {
        return 0.0f;
    }
}

bool UPlayerStatAdaptor::hasProperty_Implementation(const FString &key) const
{
    return statMap.Contains(key);
}