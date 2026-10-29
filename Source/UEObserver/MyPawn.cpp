// OEF 2026


#include "MyPawn.h"
#include "Camera/CameraComponent.h"

AMyPawn::AMyPawn()
{
    PrimaryActorTick.bCanEverTick = false;

    // Take control of the player automatically when the level starts
    AutoPossessPlayer = EAutoReceiveInput::Player0;

    // The camera follows the controller's look direction
    bUseControllerRotationYaw = true;
    bUseControllerRotationPitch = true;

    RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
    SetRootComponent(RootScene);

    FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    FirstPersonCamera->SetupAttachment(RootScene);
}

void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyPawn::DoSomeEvent()
{
	UE_LOG(LogTemp, Warning, TEXT("AMyPawn::DoSomeEvent called. Broadcasting event."));
    OnPawnSomeEventOne.Broadcast(this);
}

