// Fill out your copyright notice in the Description page of Project Settings.
// Based on tutorial at https://www.youtube.com/watch?v=fzgvXgHuxL4

#include "WorksheetC.h"
#include "ControllerAIEnemy.h"
#include "CharacterEnemy.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"

AControllerAIEnemy::AControllerAIEnemy()
{
		BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(FName("BehaviorComp"));
		BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(FName("BlackboardComp"));

}

void AControllerAIEnemy::Possess(APawn* Pawn)
{

	Super::Possess(Pawn);

	ACharacterEnemy* AICharacter = Cast<ACharacterEnemy>(Pawn);

	if (AICharacter)
	{
		if (AICharacter->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(AICharacter->BehaviorTree->BlackboardAsset));
			BehaviorComp->StartTree(*AICharacter->BehaviorTree);
		}
	}
}

void AControllerAIEnemy::SetPlayerToFollow(APawn * Pawn)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(FName("PlayerToFollow"), Pawn);
	}
}
