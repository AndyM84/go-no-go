#pragma once

#include "Blueprint/UserWidget.h"
#include "PlayerUI.generated.h"

/**
 * 
 */
UCLASS()
class GONOGO_API UPlayerUI : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

	UFUNCTION(BlueprintImplementableEvent, Category = "Go No Go|Launch Events")
	void TickFuelLoad(const FVector2D Stage1, const FVector2D Stage2, float &LOXLevel1, float &LOXLevel2, float &LH2Level1, float &LH2Level2);

	UFUNCTION(BlueprintImplementableEvent, Category = "Go No Go|Launch Events")
	void TickFuelPressure(float &LOXLevel1, float &LOXLevel2, float &LH2Level1, float &LH2Level2);

	UFUNCTION(BlueprintImplementableEvent, Category = "Go No Go|Launch Events")
	void TickWindGauge(float &DirectionAngle);

	UFUNCTION(BlueprintImplementableEvent, Category = "Go No Go|Launch Events")
	void TickCountdownTimer(int32 &Hours, int32 &Minutes, int32 &Seconds);
};
