// OEF 2026


#include "MyNPC.h"
#include "Components/StaticMeshComponent.h"
#include "MyPawn.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyNPC::AMyNPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

   MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	SetRootComponent(MeshComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMesh.Succeeded())
	{
		MeshComponent->SetStaticMesh(CubeMesh.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> BaseColorMaterial(TEXT("/Game/Materials/M_BaseColor.M_BaseColor"));
	if (BaseColorMaterial.Succeeded())
	{
		MeshComponent->SetMaterial(0, BaseColorMaterial.Object);
		//UE_LOG(LogTemp, Warning, TEXT("Constructor: M_BaseColor found and assigned"));
	}
}

// Called when the game starts or when spawned
void AMyNPC::BeginPlay()
{
	Super::BeginPlay();

	MyPawnReference = Cast<AMyPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	if (MyPawnReference)
		MyPawnReference->OnPawnSomeEventOne.AddDynamic(this, &AMyNPC::GetLarger);
	
}

void AMyNPC::GetLarger(AMyPawn* PawnThatSentThis)
{
	UE_LOG(LogTemp, Warning, TEXT("AMyNPC::GetLarger called by %s"), *PawnThatSentThis->GetName());
	SetActorScale3D(GetActorScale3D() * 1.05f);
}

// Called every frame
void AMyNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

