#include "ChoiceExecBase.h"
#include "StoryScene.h"

void UChoiceExecBase::HandleChoices(UPlayerChoice* choice) {
	for (int i = 0; i < choices.Num(); i++) {
		if (choices[i] == choice) {
			RecieveFire(i);
			return;
		}
	}
}

void UChoiceExecBase::Activate() {
	scene->newChoices(choices);
}
