#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "ObstacleRecycler.generated.h"


UCLASS()
class ENDLESSRUNNER_API AObstacleRecycler : public ATriggerBox
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* a, AActor* b, UPrimitiveComponent* OtherComp, int32 c, bool d, const FHitResult& e);
};
