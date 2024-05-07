// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FTransformStruct
{
	//макрос дл€ корректной обработки сгенерированного кода анализатором IntelliSense (синтаксический анализ объ€вленной структуры)
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);

};

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};


UCLASS()
class MYUEPROJECT_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();
	//Create mesh component
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ShowActorInformation();

	UFUNCTION(BlueprintCallable)
	void SinMovement();

	// Amplitude, Frequency, InitialLocation
	UPROPERTY(EditInstanceOnly)
	float Amplitude = 20;

	UPROPERTY(EditInstanceOnly)
	float Frequency = 5;

	FVector InitialLocation;

	UPROPERTY(VisibleDefaultsOnly)
	FString InstanceName = GetName();

	UPROPERTY(EditInstanceOnly)
	int EnemyCount = 30;

	UPROPERTY(EditInstanceOnly)
	bool isAlive = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
