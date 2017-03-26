// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Comp130_WorksheetC.h"
#include "Comp130_WorksheetCGameMode.h"
#include "Comp130_WorksheetCHUD.h"
#include "Comp130_WorksheetCCharacter.h"

AComp130_WorksheetCGameMode::AComp130_WorksheetCGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AComp130_WorksheetCHUD::StaticClass();
}
