// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GroundFPSGameMode.h"
#include "GroundFPSHUD.h"
#include "GroundFPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGroundFPSGameMode::AGroundFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGroundFPSHUD::StaticClass();
}
