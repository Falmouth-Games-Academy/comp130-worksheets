// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "EnemySpawnerActor.generated.h"

UCLASS()
class WORKSHEETC_API AEnemySpawnerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawnerActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

/*
	UProperty(EditAnywhere)
	int32* MaxNumberOfEnemies;
*/	

	UPROPERTY(EditAnywhere)
	UShapeComponent* SpawnTriggerBox;

	UFUNCTION()
	void OnPlayerEnterSpawnTriggerBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepRes);
	
protected:
	bool TriggeredSpawnBox;
	float EnemySpawnTimer;
	int32 CurrentNumberOfEnemies;
	
	
	
};
