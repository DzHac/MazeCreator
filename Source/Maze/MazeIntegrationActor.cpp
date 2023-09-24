// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeIntegrationActor.h"
#include "Kismet/GameplayStatics.h"
#include "GenericPlatform/GenericPlatformFile.h"


// Sets default values
AMazeIntegrationActor::AMazeIntegrationActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

}

// Called when the game starts or when spawned
void AMazeIntegrationActor::BeginPlay()
{
	Super::BeginPlay();

	CreateMazeByStrings();
	
}

// Called every frame
void AMazeIntegrationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMazeIntegrationActor::CreateMazeByStrings()
{
	std::vector<std::string> file;
	file.push_back("1111111111111");
	file.push_back("1000000000001");
	file.push_back("1010111110101");
	file.push_back("0000101000001");
	file.push_back("1011111111111");
	file.push_back("1000000010001");
	file.push_back("1110111010101");
	file.push_back("1000001010101");
	file.push_back("1111101110111");
	file.push_back("1010001000101");
	file.push_back("1010101110101");
	file.push_back("1000100000000");
	file.push_back("1111111111111");
	
	std::vector<std::vector<bool>> data;
	for (auto str : file)
	{
		data.push_back(convertStringToArray(str));
	}
	int i = 0;
	int j = 0;
	for (auto row : data)
	{		
		for (auto cell : row)
		{
			if (cell)
			{
				SpawnFunc(j, i);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void AMazeIntegrationActor::SpawnFunc(int i,int j)
{
	UWorld* const World = GetWorld();
	//FActorSpawnParameters=
	const FRotator SpawnRotation = FRotator(0, 0, 0);
	// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
	const FVector SpawnLocation = FVector(i * 100.0, j * 100.0, 0.0);

	UClass* CubeWallClass = ACubeWall::StaticClass();

	//Set Spawn Collision Handling Override
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	// Spawn the projectile at the muzzle
	ACubeWall* SpawnedCubeWall = World->SpawnActor<ACubeWall>(CubeWallClass, SpawnLocation, SpawnRotation, ActorSpawnParams);



}


void AMazeIntegrationActor::ReadData()
{
	//Test method. Should be deleted later
	bool walls[4][4];
	walls[0][0] = true;
	walls[0][1] = false;
	walls[0][2] = false;
	walls[0][3] = true;

	walls[1][0] = false;
	walls[1][1] = false;
	walls[1][2] = false;
	walls[1][3] = false;

	walls[2][0] = false;
	walls[2][1] = true;
	walls[2][2] = false;
	walls[2][3] = false;

	walls[3][0] = true;
	walls[3][1] = false;
	walls[3][2] = false;
	walls[3][3] = true;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (walls[i][j])
			{
				SpawnFunc(i, j);
			}

		}
	}
}

std::vector<bool> AMazeIntegrationActor::convertStringToArray(std::string& value)
{
	std::vector<bool> rslt;
	for (auto ch : value)
	{
		rslt.push_back(ch == '1');
	}
	return rslt;
}






