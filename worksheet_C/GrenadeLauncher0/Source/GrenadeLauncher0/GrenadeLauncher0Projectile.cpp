// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "GrenadeLauncher0.h"
#include "GrenadeLauncher0Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PhysicsEngine/DestructibleActor.h"

AGrenadeLauncher0Projectile::AGrenadeLauncher0Projectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AGrenadeLauncher0Projectile::OnHit);		// set up a notification for when this component hits something blocking

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

void AGrenadeLauncher0Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this))
	{
		OnDetonate();
	}
}void AGrenadeLauncher0Projectile::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle, this, &AGrenadeLauncher0Projectile::OnDetonate, 3.f, false);

}


void AGrenadeLauncher0Projectile::OnDetonate()
{
	UParticleSystemComponent* Explosion = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticles, GetActorTransform());
	Explosion->SetRelativeScale3D(FVector(4.f));

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, GetActorLocation());

	TArray<FHitResult> HitActors;

	FVector StartTrace = GetActorLocation();
	FVector EndTrace = StartTrace;
	EndTrace.Z += 300.f;

	FCollisionShape CollisionShape;
	CollisionShape.ShapeType = ECollisionShape::Sphere;
	CollisionShape.SetSphere(Radius);

	if (GetWorld()->SweepMultiByChannel(HitActors, StartTrace, EndTrace, FQuat::FQuat(), ECC_WorldStatic, CollisionShape))
	{

		for (auto Actors = HitActors.CreateIterator(); Actors; Actors++)
		{

			UStaticMeshComponent* SM = Cast<UStaticMeshComponent>((*Actors).Actor->GetRootComponent());
			ADestructibleActor* DA = Cast<ADestructibleActor>((*Actors).GetActor());

			if (SM)
			{
				SM->AddRadialImpulse(GetActorLocation(), 1000.f, 5000.f, ERadialImpulseFalloff::RIF_Linear, true);
			}
			else if (DA)
			{
				DA->GetDestructibleComponent()->ApplyRadiusDamage(10.f, Actors->ImpactPoint, 900.f, 8000.f, false);
			}
		}

	}

	Destroy();

}