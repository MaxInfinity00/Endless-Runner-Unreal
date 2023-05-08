#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessRunnerGameModeBase.generated.h"

class AGround;
class UScoreBoard;

UCLASS()
class ENDLESSRUNNER_API AEndlessRunnerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere)
	TArray<AGround*> GroundObjects;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(BlueprintReadWrite)
	UUserWidget* HUDWidget;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float Speed;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float Score;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float DifficultyIncreaseRate;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float DifficultyIncreaseTimer;

	UPROPERTY()
	FTimerHandle DifficultyIncreaseTimerHandle;

	UPROPERTY()
	UScoreBoard* ScoreBoardSave;

	UPROPERTY(BlueprintReadWrite)
	int HighScore;

public:
	AEndlessRunnerGameModeBase();
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void SetSpeed(float SpeedValue);

	UFUNCTION()
		void IncreaseSpeed();

	UFUNCTION(BlueprintNativeEvent)
		void GameOver();
	
};
