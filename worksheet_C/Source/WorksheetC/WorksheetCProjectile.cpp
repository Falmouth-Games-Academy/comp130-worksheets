// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "WorksheetC.h"
#include "WorksheetCProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "EnemyClass.h"

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
void AWorksheetCProjectile::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, this, &AWorksheetCProjectile::Explode, 6.f, false);

}
void AWorksheetCProjectile::Explode()
{
	//Creates an array of actors that have been hit by the explosion
	TArray<FHitResult> ExplodedActors;
	FVector StartTrace = GetActorLocation();
	FVector EndTrace = StartTrace;
	EndTrace.Z += 350.f;

	//Creates our collisionSphere to act as the explosion
	FCollisionShape CollisionSphere;
	CollisionSphere.ShapeType = ECollisionShape::Sphere;
	CollisionSphere.SetSphere(BlastRadius);

	if (GetWorld()->SweepMultiByChannel(ExplodedActors, StartTrace, EndTrace, FQuat::FQuat(),ECC_Visibility, CollisionSphere))
	{
		for (auto Actors = ExplodedActors.CreateIterator(); Actors; Actors++)
		{
			UStaticMeshComponent* StaticMesh = Cast<UStaticMeshComponent>((*Actors).Actor->GetRootComponent());
			AEnemyClass* CubeEnemy = Cast<AEnemyClass>((*Actors).GetActor());
			if (CubeEnemy)
			{
				CubeEnemy->Health -= 30.f;
			}
			if (StaticMesh)
			{
				StaticMesh->AddRadialImpulse(GetActorLocation(), 500.f, 8000.f, ERadialImpulseFalloff::RIF_Linear, true);
			}
		}

	}
	Destroy();
}

void AWorksheetCProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		Explode();
	}
}