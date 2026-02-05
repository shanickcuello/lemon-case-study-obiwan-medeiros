// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include "CatapultProjectile.generated.h"

UCLASS()
class LEMON_API ACatapultProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACatapultProjectile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LaunchProjectile(float Distance, float Height);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool IsLaunched = false;

	FVector Velocity = FVector(100.f, 0.f, 0.f);

	float Distance;

	float Height;

	void MoveProjectile(float DeltaTime);
};
