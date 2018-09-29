// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FindNextWayPoint.h"




EBTNodeResult::Type UBTTask_FindNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	UE_LOG(LogTemp, Warning, TEXT("This is UBTTask_FindNextWayPoint running."));

	return EBTNodeResult::Succeeded;
}
