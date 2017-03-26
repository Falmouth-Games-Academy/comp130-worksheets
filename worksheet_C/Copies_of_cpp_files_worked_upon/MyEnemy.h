// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyEnemy.generated.h"

UCLASS()
class WORKSHEETC_API AMyEnemy : public ACharacter

	/*
	Enemy Blueprint derives from this class for Health float field
	*/

{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyEnemy();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	float Health;
};
