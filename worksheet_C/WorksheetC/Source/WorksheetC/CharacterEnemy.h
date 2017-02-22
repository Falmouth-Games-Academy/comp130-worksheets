// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CharacterEnemy.generated.h"

UCLASS()
class WORKSHEETC_API ACharacterEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterEnemy();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category = "Behavior")
	class UBehaviorTree* BehaviorTree;

	// This is the static mesh for the component
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TargetMesh;

	// This is the fuction that is called when the targets health falls below 0
	void DestroyTarget();

	// This is a value from 0-100, and represents the health of the target
	float Health;

	/** This function takes a value and damages the target with that value
	* @param damage This is the amount to damage the target by
	*/
	void DamageTarget(float Damage);
	
	
};
