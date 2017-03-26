// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSWorksheet.h"
#include "FPSAIController.h"
#include "FPSAI.h"
#include "FPSAITargetPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"

AFPSAIController::AFPSAIController()
{
	/* Set up Blackboard and Behaviour Tree*/

	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	/* Set up keys in Blackboard */

	PlayerKey = "Target";
	LocationToGoKey = "LocationToGo";

	CurrentPatrolPoint = 0;

}


void AFPSAIController::Possess(APawn * Pawn)
{
	Super::Possess(Pawn);

	/* Reference to Character */

	AFPSAI* AICharacter = Cast<AFPSAI>(Pawn);

	if (AICharacter)
	{
		if (AICharacter->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(AICharacter->BehaviorTree->BlackboardAsset));
		}
	}

	/* Add to Patrol Point Array */

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFPSAI::StaticClass(), PatrolPoints);
	BehaviorComp->StartTree(*AICharacter->BehaviorTree);

}

void AFPSAIController::SetPlayerCaught(APawn * Pawn)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(PlayerKey, Pawn);
	}

}
