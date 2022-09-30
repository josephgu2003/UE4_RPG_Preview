#include "ChoiceExec3.h"
#include "StoryScene.h"

UChoiceExec3* UChoiceExec3::DecisionThree(FString choiceOne, FString choiceTwo, FString choiceThree, AStoryScene* scene_) {
	UChoiceExec3* BlueprintNode = NewObject<UChoiceExec3>();

	BlueprintNode->scene = scene_;

	BlueprintNode->AddChoice(BlueprintNode->PinOne, choiceOne, scene_);

	BlueprintNode->AddChoice(BlueprintNode->PinTwo, choiceTwo, scene_);

	BlueprintNode->AddChoice(BlueprintNode->PinThree, choiceThree, scene_);

	// should I add null checking?

	return BlueprintNode;
 }
