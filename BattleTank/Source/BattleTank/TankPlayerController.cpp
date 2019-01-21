// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// intercepting BeginPlay from parents
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Being Play"));

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)	{ UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank.")); }
	else	{ UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName())); } 
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() 
{
	if (!GetControlledTank()) { return; }
	//UE_LOG(LogTemp, Warning, TEXT("Aiming towards Crosshair"));

	// get world location if linetrace through crosshair
	// if hits the landscape
		// tell controlled tank to aim at this point
}