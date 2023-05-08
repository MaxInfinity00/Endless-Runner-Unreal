#include "ObstacleComponent.h"
#include "ObstacleManager.h"
#include "Kismet/GameplayStatics.h"

UObstacleComponent::UObstacleComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UObstacleComponent::BeginPlay()
{
	Super::BeginPlay();
	GameMode = Cast<AEndlessRunnerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
}

void UObstacleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector Pos = this->GetRelativeLocation();
	Pos.X -= GameMode->Speed * DeltaTime;
	this->SetRelativeLocation(Pos, true);
}

void UObstacleComponent::Recycle()
{
	Cast<AObstacleManager>(GetOwner())->RecycleObstacle(this);
}

void UObstacleComponent::CollideWithPlayer()
{
	bIsCollided = true;
}

void UObstacleComponent::Disappear()
{
	SetCollisionProfileName("NoCollision");
	SetVisibility(false);
	IsDisappeared = true;
}



