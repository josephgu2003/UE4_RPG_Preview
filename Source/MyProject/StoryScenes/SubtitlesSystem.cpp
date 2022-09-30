// Fill out your copyright notice in the Description page of Project Settings.

#include "SubtitlesSystem.h"


void USubtitlesSystem::displaySubtitle(const FString &line, float duration)
{
    ISubtitleUI::Execute_displaySubtitle(this->subTitleUI.GetObject(), 
    line, duration);
}