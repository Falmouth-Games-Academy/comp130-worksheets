// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Actor.h"
#include "WorksheetCProjectile.generated.h"

UCLASS(config=Game)
class AWorksheetCProjectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	class USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, Category = "FX")
	class UParticleSystem* ExplosionParticles;

	UPROPERTY(EditAnywhere, Category = "FX")
	class USoundCue* ExplosionSound;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	float radius = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Tag")
	FName EnemyTag = FName(TEXT("Enemy"));

public:
	AWorksheetCProjectile();

	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ExplosionDamage = 55.0f;

	// For the area of effect grenade weapon - FireInTheHole()
	UFUNCTION()
	void OnDetonate();

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	FORCEINLINE class UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

