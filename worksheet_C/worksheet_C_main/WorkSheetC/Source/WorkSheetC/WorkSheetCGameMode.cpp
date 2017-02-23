// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "WorkSheetC.h"
#include "WorkSheetCGameMode.h"
#include "WorkSheetCHUD.h"
#include "WorkSheetCCharacter.h"

AWorkSheetCGameMode::AWorkSheetCGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AWorkSheetCHUD::StaticClass();
}
