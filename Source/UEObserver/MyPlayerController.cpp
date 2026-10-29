// OEF 2026

#include "MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "MyPawn.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EIC->BindAction(SendEvent, ETriggerEvent::Started, this, &AMyPlayerController::OnSomeEvent);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("InputComponent is not an EnhancedInputComponent."));
	}
}

void AMyPlayerController::OnSomeEvent(const FInputActionValue& Value)
{
	if (AMyPawn* MyPawn = Cast<AMyPawn>(GetPawn()))
	{
		MyPawn->DoSomeEvent();
	}
}

