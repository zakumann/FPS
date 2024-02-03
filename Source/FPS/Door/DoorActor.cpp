// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS/Door/DoorActor.h"
#include "FPS/Character/FPSCharacter.h"

// Sets default values
ADoorActor::ADoorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrame->SetupAttachment(RootComponent);

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(DoorFrame);
}

// Called when the game starts or when spawned
void ADoorActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (CurveFloat)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindDynamic(this, &ADoorActor::OpenDoor);
		Timeline.AddInterpFloat(CurveFloat, TimelineProgress);
	}
}

// Called every frame
void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timeline.TickTimeline(DeltaTime);
}

void ADoorActor::OnInteract()
{
	if (bIsDoorClosed) {
		Timeline.Play(); // Open the Door
	} else {
		Timeline.Reverse(); // Close the Door
	}

	bIsDoorClosed = !bIsDoorClosed; // Flip Flop
}

void ADoorActor::OpenDoor(float Value)
{

	FRotator Rot = FRotator(0.f, DoorRotateAngle * Value, 0.f);

	Door->SetRelativeRotation(Rot);
}