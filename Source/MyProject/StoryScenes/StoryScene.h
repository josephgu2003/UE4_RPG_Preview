// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/Queue.h"
#include "PlayerChoiceWidget.h"
#include "SubtitlesSystem.h"
#include "StoryScene.generated.h"

DECLARE_DYNAMIC_DELEGATE(FAsyncDoneDelegate);

class AStoryScene;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEndSceneDelegate, TSubclassOf<AStoryScene>, Scene);

UCLASS()
class MYPROJECT_API AStoryScene : public AActor
{
	GENERATED_BODY()


private:
	struct QueuedLine
	{
		FString line;
		float duration;

		QueuedLine()
		{
			line = "";
			duration = 0.0f;
		}
		QueuedLine(const FString &line_, float duration_)
		{
			line = line_;
			duration = duration_;
		}
	};

	TQueue<QueuedLine, EQueueMode::Spsc> queuedLines;

	UPROPERTY()
	FTimerHandle MemberTimerHandle;

	UPROPERTY()
	FAsyncDoneDelegate delegate;

	void sayLine();

public:
	// Sets default values for this actor's properties
	AStoryScene();

protected:

	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "func"), Category = "Scene")
	void newSpeech(const TArray<FString> &lines, const FAsyncDoneDelegate& func);

	UFUNCTION(BlueprintCallable, Category = "Scene")
	void newChoice(UPARAM(ref) 
	TArray<UPlayerChoice*>& choices);

	// cancels the scene if player leaves
	UFUNCTION(BlueprintCallable, Category = "Scene")
		void cancelScene();

	UFUNCTION(BlueprintCallable, Category = "Scene")
		void endScene();

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category = "Scene")
		bool hasBeenCompleted();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, BlueprintPure, Category = "Scene")
		bool prereqsMet();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scene")
		bool PrereqsMetAndNotCompleted();

	UFUNCTION(BlueprintImplementableEvent, Category = "Scene")
		void OnStorylineUpdated();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float secPerChar;
public:
	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "func"), Category = "Scene")
		void newParsedSpeech(const FString& line, const FString& delimiter, bool cullEmpty, const FAsyncDoneDelegate& func);

	void newChoices(TArray<UPlayerChoice*>& choices);

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USubtitlesSystem *subtitlesSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPlayerChoiceWidget* playerChoice;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Scene")
		FEndSceneDelegate endSceneDelegate;
};
