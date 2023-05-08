#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "Runner.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;

UCLASS()
class ENDLESSRUNNER_API ARunner : public ACharacter
{
	GENERATED_BODY()

public:

	//Components
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* MappingContext;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UCapsuleComponent* Capsule2;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	USkeletalMeshComponent* Mesh2;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UArrowComponent* Arrow2;

	//Common Variables

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float SwipeOffset;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float LerpStrength;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	int Lives;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float InvulnerabilityDuration;

	//Player1 Vars

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category="Player1")
	int Lane;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category="Player1")
	FVector DesiredPosition;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category="Player1")
	bool isVulnerable;

	//Player2 Vars

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category="Player2")
	int Lane2;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category="Player2")
	FVector DesiredPosition2;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category="Player2")
	bool isVulnerable2;


	
	
public:
	ARunner();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SwipedLeft();
	
	UFUNCTION(BlueprintCallable)
	void SwipedRight();
	
	UFUNCTION(BlueprintCallable)
	void SwipedLeft2();
	
	UFUNCTION(BlueprintCallable)
	void SwipedRight2();

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
						class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
						bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapBegin2(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
						class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
						bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void BecomeVulnerable();
	
	UFUNCTION()
	void BecomeVulnerable2();
	
	UFUNCTION(BlueprintImplementableEvent)
	void Die();
};
