// Fill out your copyright notice in the Description page of Project Settings.

#include "WorksheetC.h"
#include "EnemySpawnerTriggerBox.h"
#include "EnemySpawnerActor.h"


// Sets default values
AEnemySpawnerActor::AEnemySpawnerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawnerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemySpawnerActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (TriggeredSpawnBox)
	{
		if (EnemySpawnTimer >= 100)
		{
			FActorSpawnParameters();
		}
		else
		{
			++EnemySpawnTimer;
		}
	}

}

void AEnemySpawnerActor::OnPlayerEnterSpawnTriggerBox(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepRes)
{
	TriggeredSpawnBox = true;
}

