// Copyright Epic Games, Inc. All Rights Reserved.


#include "EndlessRunnerGameModeBase.h"

AEndlessRunnerGameModeBase::AEndlessRunnerGameModeBase()
{
}

void AEndlessRunnerGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void AEndlessRunnerGameModeBase::AddScore(int value)
{
	Score+= value;
}
