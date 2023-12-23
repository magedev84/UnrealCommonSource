// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealCommonSource/PathFind/CGridObstacle.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACGridObstacle::ACGridObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	// 루트메쉬 설정
	RootComponent = Mesh;
}



