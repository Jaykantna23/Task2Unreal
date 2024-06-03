// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNewActor.h"

// Sets default values
AMyNewActor::AMyNewActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyNewActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation=GetActorLocation();

	
}


// Called every frame
void AMyNewActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ToFroMotion(DeltaTime);
	FRotator NewRotation=RotationSpeed*DeltaTime;
	AddActorLocalRotation(NewRotation);

}
void AMyNewActor::ToFroMotion(float DeltaTime)
{
	FVector CurrentLocation;
	CurrentLocation = GetActorLocation();
	CurrentLocation += MovementSpeed*DeltaTime;
	SetActorLocation(CurrentLocation);
	DistanceMoved = FVector::Dist(StartLocation,CurrentLocation);
	if(DistanceMoved>=MoveDistance){
		FVector MoveDirection= MovementSpeed.GetSafeNormal();
		StartLocation+=MoveDistance*MoveDirection;
		float offset =FVector::Dist(StartLocation,GetActorLocation());
		SetActorLocation(StartLocation);
		MovementSpeed= -MovementSpeed;
	} 
}
// bool AMyNewActor::DestinationReached(Fvector CurrentLocation) const
// {
// 	return FVector::Dist(CurrentLocation,StartLocation)>=MoveDistance;
// }
 
 

