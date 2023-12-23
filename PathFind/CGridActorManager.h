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
	// ��� �˻�
	bool FindPath(TArray<FVector>& inList, const FVector& inStart, const FVector& inDest);

protected:
	// �׸������ �߰�/����
	void AddGridActor(class ACGridActor* inGridActor);
	void RemoveGridActor(class ACGridActor* inGridActor);

protected:
	// �׸��� ���� ����
	//UPROPERTY()
	//TSet<class ACGridActor*> GridActorSet;

	// �켱 �ϳ��� ó��
	// ���߿��� �������� ó��
	UPROPERTY()
	class ACGridActor* GridActor = nullptr;

	UPROPERTY(Editanywhere)
	int32 TestValue = 0;
};
