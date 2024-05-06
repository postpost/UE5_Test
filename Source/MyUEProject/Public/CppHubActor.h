// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppHubActor.generated.h"

class ACppBaseActor;

UCLASS()
class MYUEPROJECT_API ACppHubActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppHubActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere)
	float SpawnTimerRate = 2.0f; //������� ������������ �������

	UPROPERTY(EditAnywhere)
	float DestroyTimerRate = 1.0F; //������� ����������� �������

	FTimerHandle SpawnTimerHandle;
	FTimerHandle DestroyTimerHandle;

	void onTimeToSpawn();
	void onTimeToDestroy();

	const int32 TotalTimerCount = 10; //������������ ���������� ������������ �������
	int32 CurrentTimerCount = 0; //������� ���������� ������������ �������

	UPROPERTY()
	TArray<ACppBaseActor*> SpawnedObjects; //������ ������������ ��������

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACppBaseActor> CppClass; //��������� �� �����, ������� ����������� ��������. ��� ������ ������ ����� ����

};
