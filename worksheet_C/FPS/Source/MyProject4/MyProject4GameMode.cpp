// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "MyProject4.h"
#include "MyProject4GameMode.h"
#include "MyProject4HUD.h"
#include "MyProject4Character.h"

AMyProject4GameMode::AMyProject4GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMyProject4HUD::StaticClass();
}
