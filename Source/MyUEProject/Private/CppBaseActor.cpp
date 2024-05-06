// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
#include "Engine/Engine.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//StaticMeshComponent initialization
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	//ShowInformation();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppBaseActor::ShowInformation()
{
	UE_LOG(LogTemp, Display, TEXT("CppBase from here"));
	UE_LOG(LogTemp, Warning, TEXT("CppBase класс ошибка?"));
	UE_LOG(LogTemp, Error, TEXT("CppBase 異體字"));


	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("CurrentHealth: %f"), CurrentHealth);
	UE_LOG(LogTemp, Display, TEXT("isAlive: %i"), isAlive);

	UE_LOG(LogTemp, Display, TEXT("playerName: %s"), *playerName);

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Magenta, playerName, true, FVector2D(2.0f, 2.0f));
}

