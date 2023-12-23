// Fill out your copyright notice in the Description page of Project Settings.


#include "CGameInstance.h"
#include "CDataTableManager.h"
#include "CGameInstanceSubsystem.h"
#include "CSingleton.h"


void UCGameInstance::Init()
{	
	Super::Init();

	// 데이터 테이블 관리 객체 생성
	if (nullptr != DataTableManagerClass) {
		DataTableManager = NewObject<UCDataTableManager>(this, DataTableManagerClass);
	}
	
	// 관리할 서브시스템을 설정
	SubsystemList = GetSubsystemArray<UCGameInstanceSubsystem>();

	// 등록된 클래스를 루프돌면서 생성 및 등록
	for (auto& pair : SingletonClassMap)
	{
		UCSingleton* singletonInstance = NewObject<UCSingleton>(this, pair.Value);
		if (nullptr == singletonInstance)
		{
			check(false);
			continue;
		}

		SingletonInstanceMap.Emplace(pair.Key, singletonInstance);
	}
}

void UCGameInstance::Shutdown()
{
	// 서브시스템 정리
	SubsystemList.Empty();

	Super::Shutdown();
}

void UCGameInstance::Tick(float DeltaTime)
{
	// 서브시스템 루프
	{
		const int32 count = SubsystemList.Num();
		for (int32 i = 0; i < count; ++i)
		{
			SubsystemList[i]->Update(DeltaTime);
		}
	}
}


class UCSingleton* UCGameInstance::GetSingletonByClass(UClass* inClass)
{
	if (UCSingleton** findInstance = SingletonInstanceMap.Find(inClass)) {
		return *findInstance;
	}

	return nullptr;
}