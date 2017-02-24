// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "Worksheet_CHUD.generated.h"

UCLASS()
class AWorksheet_CHUD : public AHUD
{
	GENERATED_BODY()

public:
	AWorksheet_CHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

