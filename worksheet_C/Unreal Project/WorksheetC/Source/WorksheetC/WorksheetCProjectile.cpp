// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "WorksheetC.h"
#include "WorksheetCProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PhysicsEngine/DestructibleActor.h"
#include "MyEnemy.h"

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
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		//OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
		OnDetonate();
	}
}

void AWorksheetCProjectile::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, this, &AWorksheetCProjectile::OnDetonate, 5.0f, false);
}

void AWorksheetCProjectile::OnDetonate()
{
	UParticleSystemComponent* Explosion = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticles, GetActorTransform());
	Explosion->SetRelativeScale3D(FVector(4.0f));

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, GetActorLocation());

	// All actors caught in explosion radius
	TArray<FHitResult> HitActors;

	// Setting up explosion capture area
	FVector StartTrace = GetActorLocation();
	FVector EndTrace = StartTrace;
	EndTrace.Z += 300.0f;
	FCollisionShape CollisionShape;
	CollisionShape.ShapeType = ECollisionShape::Sphere;
	CollisionShape.SetSphere(radius);

	if (GetWorld()->SweepMultiByChannel(HitActors, StartTrace, EndTrace, FQuat::FQuat(), ECC_WorldStatic, CollisionShape))
	{
		// Cycles through all actors in collision sphere
		for (auto Actors = HitActors.CreateIterator(); Actors; Actors++)
		{
			// Pointer declaration. the Cast acts as an 'if' statement as if no such component exists then the cast fails and the following if statement is false.
			// Also has the benefit of inherently allowing access to applicable functions. ie static mesh->add impulse. This is awesome.
			UStaticMeshComponent* TempStaticMesh = Cast<UStaticMeshComponent>((*Actors).Actor->GetRootComponent());
			ADestructibleActor* TempDestructableActor = Cast<ADestructibleActor>((*Actors).GetActor());
			AMyEnemy* TempMyEnemy = Cast<AMyEnemy>((*Actors).GetActor());

			// For static mesh objects in scene
			if (TempStaticMesh)
			{
				TempStaticMesh->AddRadialImpulse(GetActorLocation(), 1000.0f, 5000.0f, ERadialImpulseFalloff::RIF_Linear, true);
			}
				
			// For Enemy actors
			else if (TempMyEnemy)
			{
				TempMyEnemy->Health -= ExplosionDamage;
			}
				
			// For destructible objects in scene
			else if (TempDestructableActor)
			{
				TempDestructableActor->GetDestructibleComponent()->ApplyRadiusDamage(10.0f, Actors->ImpactPoint, 500.0f, 3000.0f, false);
			}
		}
	}

	Destroy();

}

