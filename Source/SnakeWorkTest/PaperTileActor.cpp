// Fill out your copyright notice in the Description page of Project Settings.


#include "PaperTileActor.h"

APaperTileActor::APaperTileActor()
{
	//PrimaryActorTick.bCanEverTick = true;
		TArray<UObject*> ObjectArray;
	GetDefaultSubobjects(ObjectArray);
	for (UObject* tileMap : ObjectArray)
	{
		if (tileMap->GetName() == "RenderComponent")
		{
			TileMap = Cast<UPaperTileMapComponent>(tileMap);
		}
	}
}
void APaperTileActor::PlaceFood() // I recall there being a better way to do this
{
	int RandX = FMath::RandRange(0, 7);
	int RandY = FMath::RandRange(0, 7);
	if (CheckTileStatus(RandX,RandY) == 1)
	{
		UpdateTile(RandX,RandY,2);
	}
	else
	{
		PlaceFood();
	}
}

void APaperTileActor::BeginPlay()
{
	TileMap->CreateNewTileMap(8,8,32,32,1,true);// these could be variables, but I dont see the need
	for (int a = 0; a < 8; a++)
	{
		for (int b = 0; b < 8; b++)
		{
			TileMap->SetTile(a,b,0,BackgroundTile);
		}
	}
	PlaceFood();
}

int APaperTileActor::CheckTileStatus(int x, int y) // 0 snake body, 2 food, 3 head, 1 background,
{	//this could probably use a Dictionary for ease of use
	if(TileMap->GetTile(x,y,0) == FoodTile)
	{
		return 2;
	}
	if (TileMap->GetTile(x,y,0) == SnakeHeadTile)
	{
		return 3;
	}
	if (TileMap->GetTile(x,y,0) == SnakeBodyTile)
	{
		return 4;
	}
	return 1;
}

void APaperTileActor::UpdateTile(int x, int y, int type)
{
	switch (type)
	{
	case 1:
		TileMap->SetTile(x,y,0, BackgroundTile);
		break;
	case 2:
		TileMap->SetTile(x,y,0, FoodTile);
		break;
	case 3:
		TileMap->SetTile(x,y,0, SnakeHeadTile);
		break;
	case 4:
		TileMap->SetTile(x,y,0, SnakeBodyTile);
		break;
		default:
			TileMap->SetTile(x,y,0, BackgroundTile);
	}
}

void APaperTileActor::Tick(float DeltaTime)
{
	
}