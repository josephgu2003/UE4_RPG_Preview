#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "MakeSpeechNode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFinishSpeechPin);

class AStoryScene;

UCLASS()
class MYPROJECT_API UMakeSpeechNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable)
		FFinishSpeechPin SpeechEnd;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "Scene")
		static UMakeSpeechNode* RunParsedSpeech(const FString& line, const FString& delimiter, bool cullEmpty, AStoryScene* scene_);

	FString speech;
	FString delimiter;
	bool cullEmpty;
	AStoryScene* scene;

	virtual void Activate() override;

	UFUNCTION()
	void OnSpeechEnd();
};

