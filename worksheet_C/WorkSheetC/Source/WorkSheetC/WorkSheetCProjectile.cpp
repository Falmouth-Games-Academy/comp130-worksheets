// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "WorkSheetC.h"
#include "WorkSheetCProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "EnemyClass.h"

AWorkSheetCProjectile::AWorkSheetCProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AWorkSheetCProjectile::OnHit);		// set up a notification for when this component hits something blocking

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

void AWorkSheetCProjectile::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, this, &AWorkSheetCProjectile::Detonate, 6.f, false);

}

void AWorkSheetCProjectile::Detonate()
{
	UParticleSystemComponent* Explosion = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionPar, GetActorTransform());
	Explosion->SetRelativeScale3D(FVector(2.f));

	TArray<FHitResult> HitActors;
	FVector StartTrace = GetActorLocation();
	FVector EndTrace = StartTrace;
	EndTrace.Z += 200.f;
	FCollisionShape CollisionShape;
	CollisionShape.ShapeType = ECollisionShape::Sphere;
	CollisionShape.SetSphere(Radius);
	if (GetWorld()->SweepMultiByChannel(HitActors, StartTrace, EndTrace, FQuat::FQuat(), ECC_WorldStatic, CollisionShape))
	{
		for (auto Actors = HitActors.CreateIterator(); Actors; Actors++)
		{
			UStaticMeshComponent* StaticMesh = Cast<UStaticMeshComponent>((*Actors).Actor->GetRootComponent());
			AEnemyClass* ScaryChair = Cast<AEnemyClass>((*Actors).GetActor());
			if (ScaryChair)
			{
				ScaryChair->Health -= 30;
				GEngine->AddOnScreenDebugMessage(-1, 10.0, FColor::Yellow, FString::FString("You Hit Scary Chair with a grenade!"));
			}
			if (StaticMesh)
			{
				StaticMesh->AddRadialImpulse(GetActorLocation(), 1000.f, 5000.f, ERadialImpulseFalloff::RIF_Linear, true);
			}
		}
	}
	Destroy();
}

void AWorkSheetCProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this)) 
	{
		
		Detonate();
	}
}