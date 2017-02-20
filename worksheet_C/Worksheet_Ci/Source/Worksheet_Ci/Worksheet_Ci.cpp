// Fill out your copyright notice in the Description page of Project Settings.

#include "Worksheet_Ci.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, Worksheet_Ci, "Worksheet_Ci" );

void ALauncherProjectile::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle, this, &ALauncherProjectile::Ondetonate, 5.f, false)
}

void ALAuncherProjectile::OnDetonate()
{

}