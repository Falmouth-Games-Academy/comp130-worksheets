// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Enemy.h"
#include "Engine/TriggerBox.h"
#include "EnemySpawnerTriggerBox.generated.h"


/**
 * 
 */
UCLASS()
class WORKSHEETC_API AEnemySpawnerTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	bool UnleashGeology = false;

	UPROPERTY(EditAnywhere)
	TArray<AEnemy*>Enemies;

	UPROPERTY(EditAnywhere)
	AEnemy* EnemyToRemoveFromList;

	UPROPERTY(EditAnywhere)
	uint32 MaxEnemiesInScreen = 6;

	UPROPERTY(EditDefaultsOnly, Category = Enemy)
	TSubclassOf<class AEnemy> EnemyClass;

protected:

	void SpawnSingleEnemy();
	void RemoveEnemyFromList();
		
	
};

