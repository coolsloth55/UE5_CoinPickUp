// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
#include "CP_CoinPickupActor.generated.h"

class UNiagaraSystem;

UCLASS()
class COINPICKUP_API ACP_CoinPickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACP_CoinPickupActor();

	UFUNCTION()
	void OnBeginOverlapComponentEvent(
		UPrimitiveComponent* OverlappedComponent, 
		AActor* OtherActor, 
        UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult
	);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Coin Pickup")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Coin Pickup")
	TObjectPtr<URotatingMovementComponent> RotatingMovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Coin Pickup")
	TObjectPtr<USphereComponent> ColliderComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Coin Pickup")
	TObjectPtr<UNiagaraSystem> OnPickUpEffect;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Coin Pickup")
	float PickEffectSpawnOffset{ 90 };

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
