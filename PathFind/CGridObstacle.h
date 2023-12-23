// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CGridObstacle.generated.h"

UCLASS(Blueprintable)
class PATH_FIND_TEST_API ACGridObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACGridObstacle();

protected:
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Mesh = nullptr;
};
