// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();
	if (!AIControlledTank) { UE_LOG(LogTemp, Warning, TEXT("AIControlled tank not found.")); }
	else { UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(AIControlledTank->GetName())); }

	auto PlayerControlledTank = GetPlayerTank();
	if (!PlayerControlledTank) { UE_LOG(LogTemp, Warning, TEXT("PlayerControlled tank not found.")); }
	else { UE_LOG(LogTemp, Warning, TEXT("PlayerControlled tank found: %s"), *(PlayerControlledTank->GetName())); }
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	//auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	//if (!PlayerPawn) { return nullptr; }
	
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}