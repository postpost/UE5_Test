// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

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
	ShowActorInformation();
	InitialLocation = this->GetActorLocation();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppBaseActor::ShowActorInformation()
{
	UE_LOG(LogTemp, Display, TEXT("InstanceName: %s"), *InstanceName);
	UE_LOG(LogTemp, Display, TEXT("EnemyCount: %d"), EnemyCount);
	UE_LOG(LogTemp, Display, TEXT("isAlive: %i"), isAlive);
}

void ACppBaseActor::SinMovement() 
{

	float ZVector = InitialLocation.Z;
	double TimeSecs = GetWorld()->GetTimeSeconds();
	ZVector = ZVector + Amplitude * FMath::Sin(TimeSecs * Frequency);
	FVector newLocation{InitialLocation.X,InitialLocation.Y, ZVector};
	SetActorLocation(newLocation);
}
