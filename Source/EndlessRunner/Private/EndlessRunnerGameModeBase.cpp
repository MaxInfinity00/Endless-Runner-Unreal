#include "EndlessRunnerGameModeBase.h"
#include "Ground.h"
#include "ScoreBoard.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

AEndlessRunnerGameModeBase::AEndlessRunnerGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEndlessRunnerGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetPlayerController(GetWorld(),0)->bShowMouseCursor = false;
	
	GetWorldTimerManager().SetTimer(DifficultyIncreaseTimerHandle,this, &AEndlessRunnerGameModeBase::IncreaseSpeed, DifficultyIncreaseTimer, true);

	if(ScoreBoardSave = Cast<UScoreBoard>(UGameplayStatics::LoadGameFromSlot("HighScore", 0)))
	{
		HighScore = ScoreBoardSave->HighScore;
	}
	else
	{
		ScoreBoardSave = Cast<UScoreBoard>(UGameplayStatics::CreateSaveGameObject(UScoreBoard::StaticClass()));
		ScoreBoardSave->HighScore = 0;
		HighScore = 0;
		UGameplayStatics::SaveGameToSlot(ScoreBoardSave, "HighScore", 0);
	}
	
	HUDWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass,TEXT("HUD"));
	HUDWidget->AddToViewport();
}

void AEndlessRunnerGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Score += DeltaTime * Speed;
}

void AEndlessRunnerGameModeBase::SetSpeed(float SpeedValue)
{
	Speed = SpeedValue;
	for(AGround* Ground : GroundObjects)
	{
		Ground->SetSpeed(SpeedValue/1000.f);
	}
}

void AEndlessRunnerGameModeBase::IncreaseSpeed()
{
	SetSpeed(Speed + DifficultyIncreaseRate);
}

void AEndlessRunnerGameModeBase::GameOver_Implementation()
{
	GetWorldTimerManager().ClearTimer(DifficultyIncreaseTimerHandle);
	SetSpeed(0);
	UGameplayStatics::GetPlayerController(GetWorld(),0)->bShowMouseCursor = true;
	if(Score > HighScore)
	{
		ScoreBoardSave->HighScore = FMath::FloorToInt(Score);
		UGameplayStatics::SaveGameToSlot(ScoreBoardSave, "HighScore", 0);
	}
}

