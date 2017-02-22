// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "Comp130_WorksheetCHUD.generated.h"

UCLASS()
class AComp130_WorksheetCHUD : public AHUD
{
	GENERATED_BODY()

public:
	AComp130_WorksheetCHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

