// Fill out your copyright notice in the Description page of Project Settings.


#include "ChoiceExec.h"
#include "StoryScene.h"

UChoiceExec* UChoiceExec::DecisionTwo(FString choiceOne, FString choiceTwo, AStoryScene* scene_) {
	UChoiceExec* BlueprintNode = NewObject<UChoiceExec>();

	BlueprintNode->scene = scene_;

	BlueprintNode->AddChoice(BlueprintNode->PinOne, choiceOne, scene_);

	BlueprintNode->AddChoice(BlueprintNode->PinTwo, choiceTwo, scene_);

	// should I add null checking?

	return BlueprintNode;
}
