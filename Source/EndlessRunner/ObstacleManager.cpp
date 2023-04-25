#include "ObstacleManager.h"
#include "ObstacleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/OnlineSession.h"

AObstacleManager::AObstacleManager()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	// noOfObstacles = 10;
	// for(int i=0; i<noOfObstacles; ++i)
	// {
	// 	ObstacleComponents.Add(CreateDefaultSubobject<UObstacleComponent>(*FString::Printf(TEXT("Obstacle Component %i"), i)));
	// 	// ObstacleComponents.Add(CreateDefaultSubobject<UStaticMeshComponent>(*FString::Printf(TEXT("ObstacleComponent %i"), i)));
	// 	ObstacleComponents[i]->SetupAttachment(RootComponent);
	// }
}

void AObstacleManager::BeginPlay()
{
	Super::BeginPlay();
	for(int i = 0; i < noOfObstacles; ++i)
	{
		UObstacleComponent* obstacle = NewObject<UObstacleComponent>(this, UObstacleComponent::StaticClass());
		obstacle->SetupAttachment(RootComponent);
		obstacle->RegisterComponent();
		// obstacle->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		ObstacleComponents.Add(obstacle);
	}
	SpawnObstacles();
}

void AObstacleManager::SpawnObstacles()
{
	int i = 0;
	for (UObstacleComponent* obstacle : ObstacleComponents)
	{
		int obstacleDataId = FMath::RandRange(0, ObstacleDatas.Num() - 1);
		obstacle->SetStaticMesh(ObstacleDatas[obstacleDataId]->ObstacleMesh);
		obstacle->SetWorldTransform(ObstacleDatas[obstacleDataId]->ObstacleTransform);
		obstacle->SetRelativeLocation(FVector(9500.f - i, FMath::RandRange(-1,1) * 300, 0.0f));
		i+=750;
	}
}

void AObstacleManager::RecycleObstacle(UObstacleComponent* obstacle)
{
	int obstacleDataId = FMath::RandRange(0, ObstacleDatas.Num() - 1);
	obstacle->SetStaticMesh(ObstacleDatas[obstacleDataId]->ObstacleMesh);
	obstacle->SetWorldTransform(ObstacleDatas[obstacleDataId]->ObstacleTransform);
	obstacle->SetRelativeLocation(FVector(9500.f, FMath::RandRange(-1,1) * 300, 0.0f));
}

