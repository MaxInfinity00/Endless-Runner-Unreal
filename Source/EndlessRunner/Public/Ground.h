#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Ground.generated.h"

UCLASS()
class ENDLESSRUNNER_API AGround : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UFUNCTION()
	void SetSpeed(float Speed);
	
};
