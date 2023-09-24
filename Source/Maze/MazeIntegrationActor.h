// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeWall.h"
#include <random>
#include <string>

//#include "Containers/Array.h"

#include "MazeIntegrationActor.generated.h"

UCLASS()
class MAZE_API AMazeIntegrationActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMazeIntegrationActor();
	UStaticMeshComponent* Cube;
	FString NewVariable;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ReadFile(std::string& fileName);
	void CreateMazeByStrings();

	UFUNCTION()
	void SpawnFunc(int i, int j);
	UFUNCTION()
	void ReadData();
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ACubeWall> CubeWall;
	ACubeWall* SpecialOne;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* CubeMeshComponent;


private:
	int mazeWidth = 4;
	int mazeHeight = 4;
	std::vector<bool> convertStringToArray(std::string& value);

};
