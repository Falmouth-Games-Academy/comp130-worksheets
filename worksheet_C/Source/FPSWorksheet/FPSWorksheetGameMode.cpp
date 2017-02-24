// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "FPSWorksheet.h"
#include "FPSWorksheetGameMode.h"
#include "FPSWorksheetHUD.h"
#include "FPSWorksheetCharacter.h"

AFPSWorksheetGameMode::AFPSWorksheetGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSWorksheetHUD::StaticClass();
}
