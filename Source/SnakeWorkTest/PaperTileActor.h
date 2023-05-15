// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperTileMapActor.h"
#include "TileMapBoardActor.h"
#include "PaperTileActor.generated.h"

/**
 * 
 */
UCLASS()
class SNAKEWORKTEST_API APaperTileActor : public APaperTileMapActor
{
	APaperTileActor();
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UPaperTileMapComponent* TileMap; // reference to tilemap
	public:
	void PlaceFood();
	UPROPERTY(EditAnywhere)
	FPaperTileInfo BackgroundTile;
	UPROPERTY(EditAnywhere)
	FPaperTileInfo SnakeHeadTile;
	UPROPERTY(EditAnywhere)
	FPaperTileInfo SnakeBodyTile;
	UPROPERTY(EditAnywhere)
	FPaperTileInfo FoodTile;
	
	virtual void BeginPlay() override;

	int CheckTileStatus(int x, int y);
	void UpdateTile(int x, int y, int type);
	
	virtual void Tick(float DeltaTime) override;
};
