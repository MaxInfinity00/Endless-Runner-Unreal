#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ScoreBoard.generated.h"

UCLASS(Blueprintable,BlueprintType)
class ENDLESSRUNNER_API UScoreBoard : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int HighScore;
	
};
