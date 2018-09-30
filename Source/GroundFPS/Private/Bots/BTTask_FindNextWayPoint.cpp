// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FindNextWayPoint.h"
#include "PatrolRoute.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UBTTask_FindNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	UE_LOG(LogTemp, Warning, TEXT("This is UBTTask_FindNextWayPoint running."));

	// Get the index of current way point.
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	// Set next way point and update index with one plus.
	AAIController* AC = OwnerComp.GetAIOwner();
	APawn* Pawn = AC->GetPawn();

	if (Pawn)
	{
		UPatrolRoute* PatrolRouteComp = Pawn->FindComponentByClass<UPatrolRoute>();
		if (!ensure(PatrolRouteComp))
		{
			return EBTNodeResult::Failed;
		}

		auto PatrolPoints = PatrolRouteComp->GetPatrolPoints();

		BlackboardComp->SetValueAsObject(WayPointKey.SelectedKeyName, PatrolPoints[Index]);

		Index++;
		int NewIndex = Index % PatrolPoints.Num(); // Cycle index
		BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NewIndex);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
