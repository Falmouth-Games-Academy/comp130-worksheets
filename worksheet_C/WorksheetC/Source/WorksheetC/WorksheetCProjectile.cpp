// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "WorksheetC.h"
#include "WorksheetCProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "CharacterEnemy.h"

AWorksheetCProjectile::AWorksheetCProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AWorksheetCProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AWorksheetCProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Will detonate when projectile hits something
	if ((OtherActor != NULL) && (OtherActor != this))
	{
		OnDetonate();
	}
}


void AWorksheetCProjectile::OnDetonate()
{
	// Spawns a particle system at explosion location
	UParticleSystemComponent* Explosion = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticles, GetActorTransform());
	// Scales up the explosion
	Explosion->SetRelativeScale3D(FVector(4.f));

	// Plays the sound at explosion location
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, GetActorLocation());

	// Makes an array to store hit actors
	TArray<FHitResult> HitActors;

	FVector StartTrace = GetActorLocation();
	FVector EndTrace = StartTrace;
	EndTrace.Z += 300.f;

	// Sets CollisionShape to a sphere
	FCollisionShape CollisionShape;
	CollisionShape.ShapeType = ECollisionShape::Sphere;
	CollisionShape.SetSphere(Radius);

	// look this up FQuat
	if (GetWorld()->SweepMultiByChannel(HitActors, StartTrace, EndTrace, FQuat::FQuat(), ECC_WorldStatic, CollisionShape))
	{
		// loops through hit actors
		for (auto Actors = HitActors.CreateIterator(); Actors; Actors++)
		{
			// casts whatever was hit into a static mesh
			UStaticMeshComponent* SM = Cast<UStaticMeshComponent>((*Actors).Actor->GetRootComponent());
			ACharacterEnemy* CE = Cast<ACharacterEnemy>((*Actors).GetActor());
			if (CE)
			{
				// Enemy hit takes damage
				CE->DamageTarget(1.f);
			
			}
			else if (SM)
			{
				// Applies force to static mesh
				SM->AddRadialImpulse(GetActorLocation(), 1000.f, 5000.f, ERadialImpulseFalloff::RIF_Linear, true);
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("You hit: %s"), *Actors->Actor->GetName()));
			}

		}
	}
	Destroy();

}