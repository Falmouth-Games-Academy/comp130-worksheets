// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "cprojectile.generated.h"

UCLASS()
class FPS_API Acprojectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Acprojectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
