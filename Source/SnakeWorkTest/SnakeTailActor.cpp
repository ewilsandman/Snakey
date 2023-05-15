// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeTailActor.h"

// Sets default values
ASnakeTailActor::ASnakeTailActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}
void ASnakeTailActor::Kill()
{
	if (NextSegment != nullptr)
	{
		NextSegment->Kill();
	}
	Board->UpdateTile(XPos,YPos,1);
	Destroy();
}

void ASnakeTailActor::Eat()
{
	
	if (NextSegment == nullptr)
	{
		NextSegment = Cast<ASnakeTailActor>(GetWorld()->SpawnActor( ASnakeTailActor::StaticClass(),NULL, NULL));
		NextSegment->Board = Board;
	}
	else
	{
		NextSegment->Eat();
	}
}

// Called when the game starts or when spawned
void ASnakeTailActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASnakeTailActor::Move(int x , int y)
{
	if (XPos != -1) // makes sure position is valid
	{
		Board->UpdateTile(XPos,YPos,1);
	}
	if (NextSegment != nullptr)
	{
		NextSegment->Move(XPos,YPos);
	}
	{
		XPos = x;
		YPos = y;
	}
	Board->UpdateTile(XPos,YPos, 4);
}

// Called every frame
void ASnakeTailActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

