// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "FPSAIController.generated.h"

/**
 * 
 */
UCLASS()
class FPSWORKSHEET_API AFPSAIController : public AAIController
{
	GENERATED_BODY()

		/* Set Behavior Tree Component */
		UBehaviorTreeComponent* BehaviorComp;

		/* Set Blackboard Component*/

		UBlackboardComponent* BlackboardComp;

		/* Keys in Blackboard */

		UPROPERTY(EditDefaultsOnly, Category = AI)
			FName LocationToGoKey;

		UPROPERTY(EditDefaultsOnly, Category = AI)
			FName PlayerKey;

		TArray<AActor*> PatrolPoints;
		
		virtual void Possess(APawn* Pawn) override;

public: 

	AFPSAIController();

	void SetPlayerCaught(APawn* Pawn);

	int32 CurrentPatrolPoint = 0;

	/* Get inline functions */
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }
	FORCEINLINE TArray<AActor*> GetPatrolPoints() const { return PatrolPoints; }
	
	
	
};
