// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CGameInstanceSubsystem.h"
#include "CGridActorManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PATH_FIND_TEST_API UCGridActorManager : public UCGameInstanceSubsystem
{
	friend class ACGridActor;

	GENERATED_BODY()

public:
	// 경로 검색
	bool FindPath(TArray<FVector>& inList, const FVector& inStart, const FVector& inDest);

protected:
	// 그리드액터 추가/제거
	void AddGridActor(class ACGridActor* inGridActor);
	void RemoveGridActor(class ACGridActor* inGridActor);

protected:
	// 그리드 액터 관리
	//UPROPERTY()
	//TSet<class ACGridActor*> GridActorSet;

	// 우선 하나만 처리
	// 나중에는 여러개를 처리
	UPROPERTY()
	class ACGridActor* GridActor = nullptr;

	UPROPERTY(Editanywhere)
	int32 TestValue = 0;
};
