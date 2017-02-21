// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "ControllerAIEnemy.generated.h"

/**
 * 
 */
UCLASS()
class WORKSHEETC_API AControllerAIEnemy : public AAIController
{
	GENERATED_BODY()

public:
		AControllerAIEnemy();
	
		virtual void Possess(APawn* Pawn) override;

		void SetPlayerToFollow(APawn* Pawn);

protected:

	UBehaviorTreeComponent* BehaviorComp;
	UBlackboardComponent* BlackboardComp;
	
};
