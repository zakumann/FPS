// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Weapon.h"
#include "GameplayTagContainer.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh1P");
	Mesh1P->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	Mesh1P->bReceivesDecals = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetHiddenInGame(true);
	SetRootComponent(Mesh1P);
}

USkeletalMeshComponent* AWeapon::GetMesh1P() const
{
	return Mesh1P;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

