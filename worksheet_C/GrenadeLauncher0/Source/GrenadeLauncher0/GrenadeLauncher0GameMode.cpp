// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "GrenadeLauncher0.h"
#include "GrenadeLauncher0GameMode.h"
#include "GrenadeLauncher0HUD.h"
#include "GrenadeLauncher0Character.h"

AGrenadeLauncher0GameMode::AGrenadeLauncher0GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGrenadeLauncher0HUD::StaticClass();
}
