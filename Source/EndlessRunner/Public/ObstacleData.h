// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ObstacleData.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API UObstacleData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstacle Data")
		UStaticMesh* ObstacleMesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		FTransform ObstacleTransform;
	
};
