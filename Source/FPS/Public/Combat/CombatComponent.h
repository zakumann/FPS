// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCombatComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Cycle to the next weapon in the inventory
	void Initiate_CycleWeapon();
	void Initiate_StartFire();
	void Initiate_StopFire();
	void Initiate_Reload();
	void Initiate_StartAim();
	void Initiate_StopAim();

protected:

private:

};
