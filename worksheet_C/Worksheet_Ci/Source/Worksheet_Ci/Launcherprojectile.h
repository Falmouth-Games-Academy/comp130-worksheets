// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "GameFramework/Actor.h"
#include "LauncherProjectile.generated.h"

UCLASS(config = Game)
class ALauncherProjectile : public AActor
{
	GENERATED_BODY()

		UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		class USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		class UprojectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, Category = "FX")
		class UParticleSystem* ExplosionParticles;

	UPROPERTY(EditAnywhere, Category = "FX")
		class USoundCue* ExplosionSound;

	UPROPERTY(EditAnywhere, Category = "Projectile")
		float Radius = 500.f;

public:
	// Sets default values for this actor's properties
	ALauncherprojectile();
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
		void OnDetonate;


};
