// Fill out your copyright notice in the Description page of Project Settings.
// Based on tutorial at https://www.youtube.com/watch?v=fzgvXgHuxL4

#include "WorksheetC.h"
#include "CharacterEnemy.h"
#include "ControllerAIEnemy.h"
#include "WorksheetCCharacter.h"

// Sets default values
ACharacterEnemy::ACharacterEnemy()
{
	Health = 100.f;

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup Mesh"));

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterEnemy::BeginPlay()
{
	Super::BeginPlay();

	// Getting the controller
	AControllerAIEnemy* AIController = Cast<AControllerAIEnemy>(GetController());

	// Getting the player
	AWorksheetCCharacter* Character = Cast<AWorksheetCCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (AIController)
	{
		AIController->SetPlayerToFollow(Character);
	}
}

void ACharacterEnemy::DamageTarget(float Damage)
{
	Health -= Damage;

	if (Health <= 0.f)
	{
		DestroyTarget();
	}
}

void ACharacterEnemy::DestroyTarget()
{
	Destroy();
}
