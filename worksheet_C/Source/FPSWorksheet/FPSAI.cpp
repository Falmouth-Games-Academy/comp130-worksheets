// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSWorksheet.h"
#include "FPSAI.h"
#include "FPSAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"

// Sets default values
AFPSAI::AFPSAI()
{
	// Set up AI sensors for Pawns
	PawnSensingComp = CreateAbstractDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(90.0f);

}

// Called when the game starts or when spawned
void AFPSAI::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AFPSAI::OnPlayerCaught);
	}

}
// Called to bind functionality to input
void AFPSAI::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AFPSAI::OnPlayerCaught(APawn * Pawn)
{
	// Reference to player controller
	AFPSAIController* AIController = Cast<AFPSAIController>(GetController());

	if (AIController)
	{
		// If in Sight of AI - Player loses health
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Health -1"));
		
		AIController->SetPlayerCaught(Pawn);
	}
}