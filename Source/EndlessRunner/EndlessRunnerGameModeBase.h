// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessRunnerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API AEndlessRunnerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AEndlessRunnerGameModeBase();
	
protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadWrite)
	float Speed;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	int Score;

	UFUNCTION(BlueprintCallable)
		void AddScore(int value);
};
