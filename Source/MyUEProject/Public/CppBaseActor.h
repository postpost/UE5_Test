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
	void ShowInformation();

	//visible everywhere but cannot be changed
	UPROPERTY(VisibleAnyWhere)
	FString playerName = "Netology";

	//can be edited anywhere
	UPROPERTY(EditAnyWhere)
	int EnemyNum = 20;

	//can be edited in property window of the base classes = archetype only
	UPROPERTY(EditDefaultsOnly)
	float CurrentHealth = 57.54687;

	//can be edited in property window of the instanced objects only
	UPROPERTY(EditInstanceOnly)
	bool isAlive = true;

	UPROPERTY(VisibleDefaultsOnly)
	bool isVisible = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:


};
