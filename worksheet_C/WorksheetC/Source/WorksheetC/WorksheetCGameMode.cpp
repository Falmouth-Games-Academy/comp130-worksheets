// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "WorksheetC.h"
#include "WorksheetCGameMode.h"
#include "WorksheetCHUD.h"
#include "WorksheetCCharacter.h"

AWorksheetCGameMode::AWorksheetCGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AWorksheetCHUD::StaticClass();
}
