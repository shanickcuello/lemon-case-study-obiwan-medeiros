// Fill out your copyright notice in the Description page of Project Settings.


#include "LemonGameModeBase.h"
#include "LemonWorldSettings.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include "Blueprint/UserWidget.h"
#include "GameModeDefinition.h"

void ALemonGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	UAssetManager* Manager = &UAssetManager::Get();
	ALemonWorldSettings* WorldSettings = Cast<ALemonWorldSettings>(GetWorldSettings());

	if (WorldSettings)
	{
		Manager->GetStreamableManager().RequestAsyncLoad(WorldSettings->GameDefinition.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &ALemonGameModeBase::FinishedLoading));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("WorldSettings is not ALemonWorldSettings"));
	}
}

void ALemonGameModeBase::FinishedLoading()
{
	ALemonWorldSettings* WorldSettings = Cast<ALemonWorldSettings>(GetWorldSettings());
	
	UGameModeDefinition* Definition = WorldSettings->GameDefinition.Get();

	if (Definition->WidgetsToAdd.Num() > 0)
	{
		AddWidgetsFromDefinition(Definition);
	}
}

void ALemonGameModeBase::AddWidgetsFromDefinition(UGameModeDefinition* Definition)
{
	for (TSubclassOf<UUserWidget> Widget : Definition->WidgetsToAdd)
	{
		if (Widget.Get()->IsValidLowLevelFast())
		{
			CreateWidget<UUserWidget>(GetWorld(), Widget)->AddToViewport();
		}
	}
}
