#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "ObstacleDisappear.generated.h"

UCLASS()
class ENDLESSRUNNER_API AObstacleDisappear : public ATriggerBox
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* a, AActor* b, UPrimitiveComponent* OtherComp, int c, bool d, const FHitResult& e);
};
