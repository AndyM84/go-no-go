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

private:
	FVector2D _stage1Load, _stage2Load, _stage1Pressure, _stage2Pressure;
	int32 _hours, _minutes, _seconds, _counter;
	float _windAngle;

public:
	UPlayerUI(const FObjectInitializer& ObjectInitializer);

	/*void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

	UFUNCTION(BlueprintNativeEvent, Category = "LaunchEvents")
	void TickFuelLoad(float &LOXLevel1, float &LOXLevel2, float &LH2Level1, float &LH2Level2);

	UFUNCTION(BlueprintNativeEvent, Category = "LaunchEvents")
	void TickFuelPressure(float &LOXLevel1, float &LOXLevel2, float &LH2Level1, float &LH2Level2);

	UFUNCTION(BlueprintNativeEvent, Category = "LaunchEvents")
	void TickWindGauge(float &DirectionAngle);

	UFUNCTION(BlueprintNativeEvent, Category = "LaunchEvents")
	void TickCountdownTimer(int32 &Hours, int32 &Minutes, int32 &Seconds);*/

	UFUNCTION(BlueprintCallable, Category = "GoNoGo|LaunchEvents")
	void ReceiveTick(FVector2D &Stage1FuelLoad, FVector2D &Stage2FuelLoad, FVector2D &Stage1FuelPressure, FVector2D &Stage2FuelPressure, float &WindDirection, int32 &Hours, int32 &Minutes, int32 &Seconds);
};
