// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "ScoreWidgetComponent.generated.h"

/**
 * 
 */
UCLASS()
class SNAKEWORKTEST_API UScoreWidgetComponent : public UWidgetComponent // unused
{
	UScoreWidgetComponent();
	void UpdateScore(int delta);
	GENERATED_BODY()
/*	UPROPERTY(EditAnywhere)
	ASnakePawn* PlayerPawn;
	UWidgetComponent* SelfReference;*/
};
