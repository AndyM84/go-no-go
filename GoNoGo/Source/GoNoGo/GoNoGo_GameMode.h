// (c) 2015 Team GoNoGo

#pragma once

#include "GameFramework/GameMode.h"
#include "GoNoGo_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class GONOGO_API AGoNoGo_GameMode : public AGameMode
{
	GENERATED_BODY()

public:
	// AActor Interface
	//virtual void PreInitializeComponents() override;
	virtual void Reset() override;
	virtual void Tick(float DeltaSeconds) override;
};
