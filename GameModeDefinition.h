// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"

#include "GameModeDefinition.generated.h"

class UUserWidget;

UCLASS()
class LEMON_API UGameModeDefinition : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UUserWidget>> WidgetsToAdd;
};
