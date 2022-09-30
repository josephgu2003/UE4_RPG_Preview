#include "PlayerStat.h"

UPlayerStat::UPlayerStat()
{
    value = 0.0f;
}

void UPlayerStat::setValue(float newVal)
{
    value = newVal;

    if (newVal <= 0.0f) {
        zeroDelegate.Broadcast();
    }
}

float UPlayerStat::getValue() const
{
    return value;
}

void UPlayerStat::incrementValue(float inc)
{
    value += inc;
    if (value <= 0.0f) {
        zeroDelegate.Broadcast();
    }
}