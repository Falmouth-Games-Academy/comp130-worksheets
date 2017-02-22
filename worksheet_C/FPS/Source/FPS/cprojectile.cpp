// Fill out your copyright notice in the Description page of Project Settings.

#include "FPS.h"
#include "cprojectile.h"


// Sets default values
Acprojectile::Acprojectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Acprojectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Acprojectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

