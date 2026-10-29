// OEF 2026

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyNPC.generated.h"

class UStaticMeshComponent;

UCLASS()
class UEOBSERVER_API AMyNPC : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyNPC();

protected:
	virtual void BeginPlay() override;
	
	// Who do I listen to? This is set in the editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyNPC")
	class AMyPawn* MyPawnReference{nullptr};

	// The function that will be called by the delegate, needs to be a UFUNCTION
	UFUNCTION(BlueprintCallable, Category = "MyNPC")
	void GetLarger(AMyPawn* PawnThatSentThis);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> MeshComponent;
};
