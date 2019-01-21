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
	
	// doesnt make sense to aim at any tank if we aren't controlling one
	if (!GetControlledTank()) { return; }
	
	FVector HitLocation; // out parameter
	if (GetSightRayLocation(HitLocation)) // has 'side-effect'. is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		// TODO tell controlled tank to aim at this point
	}
}

// get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayLocation(FVector& OutLocation) const
{
	OutLocation = FVector(1.0);
	return true;
}
