// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperTileActor.h"
#include "ScoreWidgetComponent.h"
#include "SnakeTailActor.h"
#include "GameFramework/Pawn.h"
#include "SnakePawn.generated.h"

UCLASS()
class SNAKEWORKTEST_API ASnakePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASnakePawn();
	void Kill();
	void Eat();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void InputUp();
	void InputDown();
	void InputLeft();
	void InputRight();
	void Move();

public:
	UPROPERTY(EditAnywhere)
	APaperTileActor* Board;
	UPROPERTY(VisibleAnywhere)
	int XPos = 3;
	UPROPERTY(VisibleAnywhere)
	int YPos = 3;
	UPROPERTY(VisibleAnywhere)
	int Direction = 0; // 0 up, 1 left, 2 right, 3 down
	UPROPERTY(VisibleAnywhere)
	int Length; // used for score
	UPROPERTY(VisibleAnywhere)
	ASnakeTailActor* FirstSegment;
	UPROPERTY(EditAnywhere)
	float TimeBetweenTurns = 5;
	UPROPERTY(VisibleAnywhere)
	float TimeSinceTurn = 0;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
