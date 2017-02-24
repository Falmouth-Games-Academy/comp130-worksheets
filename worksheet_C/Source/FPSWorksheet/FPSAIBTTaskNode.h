// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "FPSAIBTTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class FPSWORKSHEET_API UFPSAIBTTaskNode : public UBTTaskNode
{
	GENERATED_BODY()

		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
