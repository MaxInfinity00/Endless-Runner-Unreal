#pragma once

#include "CoreMinimal.h"
#include "EndlessRunnerGameModeBase.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/TriggerVolume.h"
#include "ObstacleComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType )
class ENDLESSRUNNER_API UObstacleComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:	
	UObstacleComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	void Recycle();

	UPROPERTY()
	AEndlessRunnerGameModeBase* GameMode;

	UFUNCTION(BlueprintCallable)
	void CollideWithPlayer();

	UFUNCTION(BlueprintCallable)
		void Disappear();

	UPROPERTY(BlueprintReadWrite)
	bool bIsCollided = false;

	UPROPERTY(BlueprintReadWrite)
	bool IsDisappeared = false;
};
