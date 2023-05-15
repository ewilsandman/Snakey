// Fill out your copyright notice in the Description page of Project Settings.

#include "SnakePawn.h"
#include "Engine/World.h"

// Sets default values
ASnakePawn::ASnakePawn()
{
	PrimaryActorTick.bCanEverTick = true;
}
void ASnakePawn::Kill()
{
	if (FirstSegment != nullptr)
	{
		FirstSegment->Kill();
	}
	Board->UpdateTile(XPos,YPos,1);
	Destroy();
}

void ASnakePawn::Eat()
{
	Length++;
	if (FirstSegment == nullptr)
	{
		FirstSegment = Cast<ASnakeTailActor>(GetWorld()->SpawnActor( ASnakeTailActor::StaticClass(),NULL, NULL));
		FirstSegment->Board = Board;
	}
	else
	{
		FirstSegment->Eat();
	}
	Board->PlaceFood();
	// update score
}
// Called when the game starts or when spawned
void ASnakePawn::BeginPlay()
{
	Board->UpdateTile(XPos,YPos,3);
	Super::BeginPlay();
	
}
void ASnakePawn::InputUp() // Can be done as a Axis
{
	Direction = 0;
}
void ASnakePawn::InputDown()
{
	Direction = 3;
}
void ASnakePawn::InputLeft()
{
	Direction = 1;
}
void ASnakePawn::InputRight()
{
	Direction = 2;
}
void ASnakePawn::Move() // not a great way of doing things. only kills player if longer than 2 tiles
{
	Board->UpdateTile(XPos,YPos,1);
	if (FirstSegment != nullptr)
	{
		FirstSegment->Move(XPos,YPos);
	}
	switch (Direction)
	{
	case 1:
		if (XPos - 1 < 0)
		{
			XPos = 7;
		}
		else
		{
			XPos--;
		}
		break;
	case 2:
		if (XPos + 1 > 7)
		{
			XPos = 0;
		}
		else
		{
			XPos++;
		}
		break;
	case 3:
		if (YPos + 1 > 7)
		{
			YPos = 0;
		}
		else
		{
			YPos++;
		}
		break;
	case 0:
		if (YPos - 1 < 0)
		{
			YPos = 7;
		}
		else
		{
			YPos--;
		}
		break;
		default:
			break;
	}
	if (Board->CheckTileStatus(XPos,YPos) == 1)
	{
		Board->UpdateTile(XPos,YPos,3);
	}
	else if (Board->CheckTileStatus(XPos,YPos) == 2)
	{
		Board->UpdateTile(XPos,YPos,3);
		Eat();
	}
	else
	{
		Kill();
	}
}

// Called every frame
void ASnakePawn::Tick(float DeltaTime)
{
	if (TimeSinceTurn > TimeBetweenTurns)
	{
		Move();
		TimeSinceTurn = 0;
	}
	else
	{
		TimeSinceTurn = TimeSinceTurn + DeltaTime;
	}
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASnakePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) // Feels icky
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Up", IE_Pressed, this, &ASnakePawn::InputUp);
	PlayerInputComponent->BindAction("Left", IE_Pressed, this, &ASnakePawn::InputLeft);
	PlayerInputComponent->BindAction("Down", IE_Pressed, this, &ASnakePawn::InputDown);
	PlayerInputComponent->BindAction("Right", IE_Pressed, this, &ASnakePawn::InputRight);
}

