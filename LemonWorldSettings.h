// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/WorldSettings.h"

#include "LemonWorldSettings.generated.h"

class UGameModeDefinition;

/**
 * 
 */
UCLASS()
class LEMON_API ALemonWorldSettings : public AWorldSettings
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UGameModeDefinition> GameDefinition;
};
