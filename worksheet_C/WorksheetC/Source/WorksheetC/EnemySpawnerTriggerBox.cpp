// Fill out your copyright notice in the Description page of Project Settings.

#include "WorksheetC.h"
#include "EnemySpawnerTriggerBox.h"
#include "Enemy.h"


void AEnemySpawnerTriggerBox::SpawnSingleEnemy()
{
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	//UGameplayStatics::BeginSpawningActorFromClass()
	AEnemy * NewEnemy = GetWorld()->SpawnActor<AEnemy>(EnemyClass, ActorSpawnParams);  // Not need Transform? Compiles without...
	
	Enemies.Add(NewEnemy);
}

void AEnemySpawnerTriggerBox::RemoveEnemyFromList()
{
	Enemies.Remove(EnemyToRemoveFromList);
}
