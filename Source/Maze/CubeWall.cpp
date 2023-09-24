// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeWall.h"

// Sets default values
ACubeWall::ACubeWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//bool Special = false;

	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyCubeMesh"));
	WallMesh->SetupAttachment(RootComponent);
	UStaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (CubeMesh)
	{
		WallMesh->SetStaticMesh(CubeMesh);
	}
	WallMesh->SetSimulatePhysics(true);
	WallMesh->SetMassScale(NAME_None, 100.0f);
	WallMesh->SetLinearDamping(10.2f);
	WallMesh->SetAngularDamping(10.2f);

}

// Called when the game starts or when spawned
void ACubeWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACubeWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

