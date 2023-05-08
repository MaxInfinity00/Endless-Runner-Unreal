#include "ObstacleDisappear.h"
#include "Components/ShapeComponent.h"
#include "ObstacleComponent.h"
#include "ObstacleManager.h"

void AObstacleDisappear::BeginPlay()
{
	Super::BeginPlay();
	this->GetCollisionComponent()->OnComponentBeginOverlap.AddDynamic(this, &AObstacleDisappear::OnComponentBeginOverlap);
}

void AObstacleDisappear::OnComponentBeginOverlap(UPrimitiveComponent* a, AActor* b, UPrimitiveComponent* OtherComp, int c, bool d, const FHitResult& e)
{
	if(OtherComp->IsA<UObstacleComponent>())
	{
		AObstacleManager* ManagerObj = Cast<AObstacleManager>(OtherComp->GetOwner());
		if(ManagerObj->NoofDisappearObstacles)
		{
			ManagerObj->NoofDisappearObstacles--;
			Cast<UObstacleComponent>(OtherComp)->Disappear();
		}
	}
}