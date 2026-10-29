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
	// Sets default values for this actor's properties
	AMyNPC();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "MyNPC")
	void GetLarger(AMyPawn* PawnThatSentThis);

	// Who do I listen to? This is set in the editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyNPC")
	class AMyPawn* MyPawnReference{nullptr};


  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> MeshComponent;
};
