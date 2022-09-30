#include "MakeSpeechNode.h"
#include "StoryScene.h"

UMakeSpeechNode* UMakeSpeechNode::RunParsedSpeech(const FString& line, const FString& delimiter, bool cullEmpty, AStoryScene* scene_) {
	UMakeSpeechNode* BlueprintNode = NewObject<UMakeSpeechNode>();

	BlueprintNode->scene = scene_;	
	BlueprintNode->speech = line;
	BlueprintNode->delimiter = delimiter;
	BlueprintNode->cullEmpty = cullEmpty;

	return BlueprintNode;
 }


 void UMakeSpeechNode::Activate() {
	 FAsyncDoneDelegate delegate;
	 delegate.BindDynamic(this, &UMakeSpeechNode::OnSpeechEnd);
	 scene->newParsedSpeech(speech, delimiter, cullEmpty, delegate);
 }

 void UMakeSpeechNode::OnSpeechEnd() {
	 SpeechEnd.Broadcast();
 }