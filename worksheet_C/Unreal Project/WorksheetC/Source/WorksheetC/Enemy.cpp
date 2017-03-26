// Fill out your copyright notice in the Description page of Project Settings.

#include "WorksheetC.h"
#include "Enemy.h"



// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	MaxWalkSpeed = MaxWalkSpeed;
	Health = EnemyMaxHealth;
	//Define spawner like blueprint
}

// Called every frame
void AEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	APawn* PlayerOne = GetWorld()->GetFirstPlayerController()->GetPawn();
	APawn* AlsoPlayerOne = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (Health <= 0.0f)
	{
		Death();
	}
	else if (GetDistanceTo(AlsoPlayerOne) < AttackDistance && CanAttack)
	{
		AttackPlayer();
	}
}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::AttackPlayer()
{
	// Attack player here
}

void AEnemy::Death()
{
	// Cast to spawner to respawn new Enemy
	Destroy();
}


