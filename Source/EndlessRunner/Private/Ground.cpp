#include "Ground.h"
#include "EndlessRunnerGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void AGround::BeginPlay()
{
	Super::BeginPlay();
	Cast<AEndlessRunnerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()))->GroundObjects.Add(this);
}

void AGround::SetSpeed(float Speed)
{
	GetStaticMeshComponent()->SetScalarParameterValueOnMaterials("Speed", Speed);
}
