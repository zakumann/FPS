// Fill out your copyright notice in the Description page of Project Settings.


#include "Combat/CombatComponent.h"


UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCombatComponent::Initiate_CycleWeapon()
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		5.0f,
		FColor::Cyan,
		TEXT("Initiate_CycleWeapon"),
		false
	);
}
void UCombatComponent::Initiate_StartFire()
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		5.0f,
		FColor::Cyan,
		TEXT("Initiate_StartFire"),
		false
	);
}
void UCombatComponent::Initiate_StopFire()
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		5.0f,
		FColor::Cyan,
		TEXT("Initiate_StopFire"),
		false
	);
}
void UCombatComponent::Initiate_Reload()
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		5.0f,
		FColor::Cyan,
		TEXT("Initiate_Reload"),
		false
	);
}
void UCombatComponent::Initiate_StartAim()
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		5.0f,
		FColor::Cyan,
		TEXT("Initiate_StartAim"),
		false
	);
}
void UCombatComponent::Initiate_StopAim()
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		5.0f,
		FColor::Cyan,
		TEXT("Initiate_StopAim"),
		false
	);
}