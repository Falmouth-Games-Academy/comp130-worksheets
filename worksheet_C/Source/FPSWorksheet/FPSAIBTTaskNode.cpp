// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSWorksheet.h"
#include "FPSAIBTTaskNode.h"
#include "FPSAITargetPoint.h"
#include "FPSAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UFPSAIBTTaskNode::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AFPSAIController* AICon = Cast<AFPSAIController>(OwnerComp.GetAIOwner());

	if (AICon)
	{
		// Get Blackboard Component
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComp();

		AFPSAITargetPoint* CurrentPoint = Cast<AFPSAITargetPoint>(BlackboardComp->GetValueAsObject("LocationToGo"));

		TArray<AActor*> AvailablePatrolPoints = AICon->GetPatrolPoints();

		AFPSAITargetPoint* NextPatrolPoint = nullptr;

		if (AICon->CurrentPatrolPoint != AvailablePatrolPoints.Num() - 1)
		{
			NextPatrolPoint = Cast<AFPSAITargetPoint>(AvailablePatrolPoints[++AICon->CurrentPatrolPoint]);
		}

		else // No patrol points left to go to
		{
			NextPatrolPoint = Cast<AFPSAITargetPoint>(AvailablePatrolPoints[0]);
			AICon->CurrentPatrolPoint = 0;
		}

		BlackboardComp->SetValueAsObject("LocationToGo", NextPatrolPoint);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
