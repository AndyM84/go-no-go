#pragma once

#include "Blueprint/UserWidget.h"
#include "PlayerUI.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUITickReceived, float, testing);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class GONOGO_API UPlayerUI : public UUserWidget
{
	GENERATED_BODY()

private:
	FVector2D _stage1Load, _stage2Load, _stage1Pressure, _stage2Pressure;
	int32 _hours, _minutes, _seconds, _counter;
	float _windAngle;

public:
	UPlayerUI(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintAssignable)
	FUITickReceived OnTickReceived;

	void NativeTick(const FGeometry &MyGeometry, float InDeltaTime);

	UFUNCTION(BlueprintNativeEvent, Category = "GoNoGo|LaunchEvents")
	void DidTick(float &DeltaTime);
	virtual void DidTick_Implementation(float &DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "GoNoGo|LaunchEvents")
	void ReceiveTick(FVector2D &Stage1FuelLoad, FVector2D &Stage2FuelLoad, FVector2D &Stage1FuelPressure, FVector2D &Stage2FuelPressure, float &WindDirection, int32 &Hours, int32 &Minutes, int32 &Seconds);
};
