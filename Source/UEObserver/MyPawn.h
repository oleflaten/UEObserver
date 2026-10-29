// OEF 2026

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

class UCameraComponent;
class USceneComponent;

UDELEGATE(BlueprintCallable)
//										   Delegate name, parameter type, parameter name
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPawnSomeEvent, AMyPawn*, PawnDidSomeEvent);

UCLASS()
class UEOBSERVER_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	AMyPawn();

	FOnPawnSomeEvent OnPawnSomeEventOne;

	void DoSomeEvent();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FirstPersonCamera;

};
