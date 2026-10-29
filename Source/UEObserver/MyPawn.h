// OEF 2026

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

class UCameraComponent;
class USceneComponent;

UCLASS()
class UEOBSERVER_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	AMyPawn();

	UDELEGATE(BlueprintCallable)
	//										   Delegate name, parameter type, optional parameter name
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPawnSomeEvent, AMyPawn*, PawnDidSomeEvent);
	
	// The delegate object
	UPROPERTY(BlueprintAssignable)
	FOnPawnSomeEvent OnPawnSomeEventOne;

	// Function called by SpaceBar - from PlayerController
	void DoSomeEvent();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FirstPersonCamera;

};
