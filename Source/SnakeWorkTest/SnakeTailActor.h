// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperTileActor.h"
#include "SnakeTailActor.generated.h"

UCLASS()
class SNAKEWORKTEST_API ASnakeTailActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnakeTailActor();
	void Kill();
	void Eat();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Move(int x, int y);
	UPROPERTY(VisibleAnywhere)
	int XPos = -1;
	UPROPERTY(VisibleAnywhere)
	int YPos = -1;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
	ASnakeTailActor* NextSegment;
	UPROPERTY(VisibleAnywhere)
	APaperTileActor* Board;

};
