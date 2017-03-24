// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "cfpsHUD.generated.h"

UCLASS()
class AcfpsHUD : public AHUD
{
	GENERATED_BODY()

public:
	AcfpsHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

