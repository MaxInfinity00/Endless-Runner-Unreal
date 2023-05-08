#include "ObstacleRecycler.h"
#include "Components/ShapeComponent.h"
#include "ObstacleComponent.h"

void AObstacleRecycler::BeginPlay()
{
	Super::BeginPlay();
	UShapeComponent* x = this->GetCollisionComponent();
	x->OnComponentBeginOverlap.AddDynamic(this, &AObstacleRecycler::OnComponentBeginOverlap);
}

void AObstacleRecycler::OnComponentBeginOverlap(UPrimitiveComponent* a, AActor* b, UPrimitiveComponent* OtherComp, int c, bool d, const FHitResult& e)
{
	if(OtherComp->IsA<UObstacleComponent>())
	{
		Cast<UObstacleComponent>(OtherComp)->Recycle();
	}
}
