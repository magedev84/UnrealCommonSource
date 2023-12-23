// Fill out your copyright notice in the Description page of Project Settings.


#include "CGameInstance.h"
#include "CDataTableManager.h"
#include "CGameInstanceSubsystem.h"
#include "CSingleton.h"


void UCGameInstance::Init()
{	
	Super::Init();

	// ������ ���̺� ���� ��ü ����
	if (nullptr != DataTableManagerClass) {
		DataTableManager = NewObject<UCDataTableManager>(this, DataTableManagerClass);
	}
	
	// ������ ����ý����� ����
	SubsystemList = GetSubsystemArray<UCGameInstanceSubsystem>();

	// ��ϵ� Ŭ������ �������鼭 ���� �� ���
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
	// ����ý��� ����
	SubsystemList.Empty();

	Super::Shutdown();
}

void UCGameInstance::Tick(float DeltaTime)
{
	// ����ý��� ����
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