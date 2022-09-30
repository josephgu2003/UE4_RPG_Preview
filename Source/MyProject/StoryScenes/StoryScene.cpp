// Fill out your copyright notice in the Description page of Project Settings.

#include "StoryScene.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AStoryScene::AStoryScene()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	secPerChar = 0.1f;
	subtitlesSystem = nullptr; 
}

void AStoryScene::newSpeech(const TArray<FString>& lines, const FAsyncDoneDelegate& func)
{
	for (FString line : lines)
	{
		this->queuedLines.Enqueue(QueuedLine(line,
			line.Len() * secPerChar));
	}

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AStoryScene::sayLine, 1.0f, false, 0.0f);

	delegate = func;
}

void AStoryScene::newParsedSpeech(const FString& line, const FString& delimiter, bool cullEmpty, const FAsyncDoneDelegate& func) {
	TArray<FString> lines;
	line.ParseIntoArray(lines, *delimiter, cullEmpty);
	newSpeech(lines, func);
}

void AStoryScene::sayLine()
{
	if (!queuedLines.IsEmpty()) {
		QueuedLine line;
		queuedLines.Dequeue(line);

		if (subtitlesSystem && GetWorld()) {
			subtitlesSystem->displaySubtitle(line.line, line.duration);
			GetWorldTimerManager().
				SetTimer(MemberTimerHandle, this, &AStoryScene::sayLine, 1.0f, false, line.duration); // bug when world is switched, getworld returns null, in that case
				// do nothing and let the lines run out
		}
	}
	else {
		delegate.ExecuteIfBound();
	}
}
void AStoryScene::newChoice(TArray<UPlayerChoice*>& choices) {
	newChoices(choices);
}

void AStoryScene::newChoices(TArray<UPlayerChoice*>& choices) {
	if (playerChoice) {
		playerChoice->init(choices);
	}
}

void AStoryScene::cancelScene() {
	queuedLines.Empty();
	delegate.Unbind();

	if (playerChoice)
	playerChoice->clearWidget();
}


void AStoryScene::endScene() {
	TSubclassOf<AStoryScene> completedClass(GetClass());
	endSceneDelegate.Broadcast(completedClass);
	TArray<AActor*> allScenes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStoryScene::StaticClass(), allScenes);

	for (auto& scene : allScenes) {
		Cast<AStoryScene>(scene)->OnStorylineUpdated();
	}
	Destroy();
}


void AStoryScene::BeginPlay() {
	Super::BeginPlay();
	if (hasBeenCompleted()) {
		Destroy();
	}
}

bool AStoryScene::PrereqsMetAndNotCompleted() {
	return prereqsMet() && !hasBeenCompleted();
}