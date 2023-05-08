#include "Runner.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ObstacleComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

ARunner::ARunner()
{
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	RootComponent = Root;
	GetCapsuleComponent()->SetupAttachment(Root);

	Capsule2 = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule2"));
	Capsule2->SetupAttachment(Root);
	Mesh2 = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh2"));
	Mesh2->SetupAttachment(Capsule2);
	Arrow2 = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow2"));
	Arrow2->SetupAttachment(Capsule2);
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	Camera->SetupAttachment(CameraBoom);
}

void ARunner::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* controller = Cast<APlayerController>(GetController());
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(controller->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MappingContext, 0);
	}

	DesiredPosition = GetCapsuleComponent()->GetRelativeLocation();
	DesiredPosition2 = Capsule2->GetRelativeLocation();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ARunner::OnOverlapBegin);
	Capsule2->OnComponentBeginOverlap.AddDynamic(this, &ARunner::OnOverlapBegin2);
}

void ARunner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetCapsuleComponent()->SetRelativeLocation(UKismetMathLibrary::VInterpTo_Constant(GetCapsuleComponent()->GetRelativeLocation(),DesiredPosition,DeltaTime,LerpStrength));
	Capsule2->SetRelativeLocation(UKismetMathLibrary::VInterpTo_Constant(Capsule2->GetRelativeLocation(),DesiredPosition2,DeltaTime,LerpStrength));
}

void ARunner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

void ARunner::SwipedLeft()
{
	if(Lane<0) return;
	Lane--;
	DesiredPosition -= FVector(0, SwipeOffset, 0);
}

void ARunner::SwipedRight()
{
	if(Lane>0) return;
	Lane++;
	DesiredPosition += FVector(0, SwipeOffset, 0);
}

void ARunner::SwipedLeft2()
{
	if(Lane2<0) return;
	Lane2--;
	DesiredPosition2 -= FVector(0, SwipeOffset, 0);
}

void ARunner::SwipedRight2()
{
	if(Lane2>0) return;
	Lane2++;
	DesiredPosition2 += FVector(0, SwipeOffset, 0);
}

void ARunner::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(!isVulnerable) return;
	isVulnerable = false;
	
	if(UObstacleComponent* obstacle = Cast<UObstacleComponent>(OtherComp)) {
		obstacle->CollideWithPlayer();
		Lives--;
		if(Lives<=0) {
			Cast<AEndlessRunnerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()))->GameOver();
			Die();
		}
		else {
			FTimerHandle TimerHandle;
			GetWorldTimerManager().SetTimer(TimerHandle,this, &ARunner::BecomeVulnerable, InvulnerabilityDuration, false);
			// GetWorldTimerManager().SetTimer(TimerHandle,this, [this](){this->isVulnerable = true;}, InvulnerabilityDuration, false);
		}
	}
}

void ARunner::OnOverlapBegin2(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(!isVulnerable2) return;
	isVulnerable2 = false;
	if(UObstacleComponent* obstacle = Cast<UObstacleComponent>(OtherComp)) {
		obstacle->CollideWithPlayer();
		Lives--;
		
		if(Lives<=0) {
			Cast<AEndlessRunnerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()))->GameOver();
			Die();
		}
		else {
			FTimerHandle TimerHandle;
			GetWorldTimerManager().SetTimer(TimerHandle,this, &ARunner::BecomeVulnerable2, InvulnerabilityDuration, false);
			// GetWorldTimerManager().SetTimer(TimerHandle,this, [this](){this->isVulnerable = true;}, InvulnerabilityDuration, false);
		}
	}
}

void ARunner::BecomeVulnerable()
{
	isVulnerable = true;
}

void ARunner::BecomeVulnerable2()
{
	isVulnerable2 = true;
}

