#pragma once

#include "CoreMinimal.h"
#include "ObstacleData.h"
#include "GameFramework/Actor.h"
#include "ObstacleManager.generated.h"

class UObstacleComponent;

UCLASS(Blueprintable,BlueprintType)
class ENDLESSRUNNER_API AObstacleManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AObstacleManager();

protected:
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
		int noOfObstacles;

	UPROPERTY()
	int NoofDisappearObstacles;

	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	float obstacleDisappearChances;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TArray<UObstacleData*> ObstacleDatas;

	UFUNCTION()
	void RecycleObstacle(UObstacleComponent* obstacle);
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TArray<UObstacleComponent*> ObstacleComponents;

	UFUNCTION()
	void SpawnObstacles();

};
