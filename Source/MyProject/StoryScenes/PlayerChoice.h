#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerChoice.generated.h"

class UPlayerChoice;
class USceneAffinity;

DECLARE_DYNAMIC_DELEGATE_OneParam(FPlayerChoiceResult, UPlayerChoice*, choice);


UCLASS(Blueprintable) 
class UPlayerChoice : public UObject {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
		FString choiceName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
		USceneAffinity* sceneAffinity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPlayerChoiceResult result; // either the result of choosing this choice or an intermediate action that fires one of the exec pins in a ChoiceExec
};