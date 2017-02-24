// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Worksheet_C.h"
#include "Worksheet_CGameMode.h"
#include "Worksheet_CHUD.h"
#include "Worksheet_CCharacter.h"

AWorksheet_CGameMode::AWorksheet_CGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AWorksheet_CHUD::StaticClass();
}
