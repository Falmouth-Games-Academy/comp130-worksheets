// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "cfps.h"
#include "cfpsGameMode.h"
#include "cfpsHUD.h"
#include "cfpsCharacter.h"

AcfpsGameMode::AcfpsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AcfpsHUD::StaticClass();
}
