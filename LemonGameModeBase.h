// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <GameFramework/GameModeBase.h>

#include "LemonGameModeBase.generated.h"

class UGameModeDefinition;

UCLASS()
class LEMON_API ALemonGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned.
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	UFUNCTION()
	void FinishedLoading();

	void AddWidgetsFromDefinition(UGameModeDefinition* Definition);
};
