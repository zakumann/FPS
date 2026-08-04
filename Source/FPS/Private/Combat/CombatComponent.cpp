// Fill out your copyright notice in the Description page of Project Settings.


#include "Combat/CombatComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/Pawn.h"
#include "Weapon/Weapon.h"


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

void UCombatComponent::Equip(AWeapon* Weapon)
{
	CurrentWeapon = Weapon;
	CurrentWeapon->AttachToOwningPawn();
}

void UCombatComponent::SpawnInventory()
{
	if (GetOwner()->GetLocalRole() < ROLE_Authority) return;

	for (TSubclassOf<AWeapon> WeaponClass : DefaultWeaponClasses)
	{
		AWeapon* Weapon = SpawnWeapon(WeaponClass);
		Inventory.AddUnique(Weapon);
	}

	if (Inventory.Num() > 0)
	{
		Equip(Inventory[0]);
	}
}

void UCombatComponent::DestroyInventory()
{
	for (AWeapon* Weapon : Inventory)
	{
		if (IsValid(Weapon))
		{
			Weapon->Destroy();
		}
	}
}

void UCombatComponent::OnRep_CurrentWeapon(AWeapon* LastWeapon)
{
	if (!IsValid(CurrentWeapon)) return;
	CurrentWeapon->AttachToOwningPawn();
}

AWeapon* UCombatComponent::SpawnWeapon(TSubclassOf<AWeapon> WeaponClass) const
{
	AActor* OwningActor = GetOwner();
	if (!IsValid(OwningActor)) return nullptr;
	if (OwningActor->GetLocalRole() < ROLE_Authority) return nullptr;

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Instigator = Cast<APawn>(OwningActor);
	SpawnInfo.Owner = OwningActor;

	return GetWorld()->SpawnActor<AWeapon>(WeaponClass, SpawnInfo);
}