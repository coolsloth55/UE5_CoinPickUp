// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_CoinPickupActor.h"

// Sets default values
ACP_CoinPickupActor::ACP_CoinPickupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	ColliderComponent = CreateDefaultSubobject<USphereComponent>("ColliderComponent");
	SetRootComponent(ColliderComponent);
	ColliderComponent->SetGenerateOverlapEvents(true);
	ColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	ColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);


	ColliderComponent->OnComponentBeginOverlap.AddDynamic(
		this, &ACP_CoinPickupActor::OnBeginOverlapComponentEvent
	);


	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	//SetRootComponent(MeshComponent);
	MeshComponent->SetupAttachment(ColliderComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComponent->SetGenerateOverlapEvents(false);

	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingMovementComponent");
}

//
void ACP_CoinPickupActor::OnBeginOverlapComponentEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!Cast<ACharacter>(OtherActor)) return;

	Destroy();
}

// Called when the game starts or when spawned
void ACP_CoinPickupActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACP_CoinPickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

