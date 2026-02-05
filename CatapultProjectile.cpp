// Fill out your copyright notice in the Description page of Project Settings.


#include "CatapultProjectile.h"

ACatapultProjectile::ACatapultProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ACatapultProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACatapultProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsLaunched)
	{
		MoveProjectile(DeltaTime);
	}

}

void ACatapultProjectile::LaunchProjectile(float InDistance, float InHeight)
{
	//x(t) = x₀ + v₀ₓ · t

	//y(t) = y₀ + v₀ᵧ · t

	//z(t) = z₀ + v₀𝓏 · t − ½ · g · t²

	Distance = InDistance;
	Height = InHeight;
	IsLaunched = true;
}

void ACatapultProjectile::MoveProjectile(float DeltaTime)
{
	float NewX = 0.f;
	float NewY = 0.f;
	float NewZ = 0.f;

	FVector CurrentVelocity = Velocity * FMath::Atan(Height / Distance);

	NewX = GetActorLocation().X + CurrentVelocity.X * DeltaTime;
	NewY = GetActorLocation().Y + CurrentVelocity.Y * DeltaTime;
	NewZ = GetActorLocation().Z + CurrentVelocity.Z * DeltaTime - 0.5f * 980.f * DeltaTime * DeltaTime;
}