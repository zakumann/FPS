// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Interfaces/PlayerInterface.h"
#include "FPSCharacter.generated.h"

class UAnimBlueprint;
class UInputMappingContext;
class UInputAction;
class UInputComponent;
class UCameraComponent;
class USkeletalMeshComponent;
class UCombatComponent;

UCLASS()
class FPS_API AFPSCharacter : public ACharacter, public IPlayerInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

	// First Person animations
	UPROPERTY(EditAnywhere, Category = Animation)
	TObjectPtr<UAnimBlueprint> FirstPersonDefaultAnim;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FPS|Input")
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FPS|Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FPS|Input")
	TObjectPtr<UInputAction> JumpAction;

	// Look Input
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FPS|Input")
	TObjectPtr<UInputAction> LookAction;

	// Sprint Input
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FPS|Input")
	TObjectPtr<UInputAction> SprintAction;

	// Cycle Weapon Input
	UPROPERTY(EDitAnywhere, Category = "FPS|Input")
	TObjectPtr<UInputAction> CycleWeaponAction;

	// Fire Weapon Input
	UPROPERTY(EDitAnywhere, Category = "FPS|Input")
	TObjectPtr<UInputAction> FireWeaponAction;

	// Reload Weapon Input
	UPROPERTY(EDitAnywhere, Category = "FPS|Input")
	TObjectPtr<UInputAction> ReloadWeaponAction;

	// Aim Weapon Input
	UPROPERTY(EDitAnywhere, Category = "FPS|Input")
	TObjectPtr<UInputAction> AimWeaponAction;


	// 1st Person mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "1P Mesh")
	TObjectPtr<USkeletalMeshComponent> Mesh1PComponent;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UCameraComponent> CameraComponent;

	// Speed
	UPROPERTY(EditAnywhere, Category = "Movement")
	float WalkSpeed;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float RunSpeed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;

	/** PlayerInterface*/
	virtual FName GetWeaponAttachPoint_Implementation(const FGameplayTag& WeaponType) const override;
	virtual USkeletalMeshComponent* GetMesh1P_Implementation() const override;
	/** ~PlayerInterface */


	UFUNCTION()
	void Move(const FInputActionValue& Value);

	UFUNCTION()
	void Look(const FInputActionValue& Value);

	void StartSprint();
	void StopSprint();

private:

	void CycleWeapon();
	void ReloadWeapon();
	void StartFire();
	void StopFire();

	void StartAim();
	void StopAim();

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCombatComponent> Combat;
};
