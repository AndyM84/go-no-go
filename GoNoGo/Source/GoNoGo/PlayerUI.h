#pragma once

#include <Core.hpp>
#include "Blueprint/UserWidget.h"
#include "PlayerUI.generated.h"

// Declare all of our multicast events

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FUITClockTicked, float, Hours, float, Minutes, float, Seconds);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUIStage1FuelLoaded, float, LoxLoad, float, Lh2Load);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUIStage2FuelLoaded, float, LoxLoad, float, Lh2Load);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUIStage1FuelPressurized, float, LoxPressure, float, Lh2Pressure);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUIStage2FuelPressurized, float, LoxPressure, float, Lh2Pressure);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUIWindPulsed, float, WindAngle, float, WindVelocity);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class GONOGO_API UPlayerUI : public UUserWidget
{
	GENERATED_BODY()

private:
	FVector2D _stage1Load, _stage2Load, _stage1Pressure, _stage2Pressure;
	FSlateBrush _goButtonBrush, _nogoButtonBrush;
	std::map<const FString, bool> _buttonStates;
	int32 _hours, _minutes, _seconds, _counter;
	float _windAngle, _windVelocity;
	bool _isTicking;

public:
	UPlayerUI(const FObjectInitializer& ObjectInitializer);
	~UPlayerUI();

	UFUNCTION(BlueprintCallable, Category = "GoNoGo")
	void GetPSIAngle(const float PSI, float &Angle);

	UFUNCTION(BlueprintCallable, Category = "GoNoGo")
	void ToggleButton(const FString ButtonKey, FButtonStyle &ButtonStyle, FString &ButtonText);

	UFUNCTION(BlueprintCallable, Category = "GoNoGo")
	void ToggleTick();

	UFUNCTION(BlueprintCallable, Category = "GoNoGo|LaunchEvents")
	void DoTick();

	UPROPERTY(BlueprintAssignable, Category = "GoNoGo|LaunchEvents")
	FUITClockTicked TClockTicked;

	UPROPERTY(BlueprintAssignable, Category = "GoNoGo|LaunchEvents")
	FUIStage1FuelLoaded Stage1FuelLoaded;

	UPROPERTY(BlueprintAssignable, Category = "GoNoGo|LaunchEvents")
	FUIStage2FuelLoaded Stage2FuelLoaded;

	UPROPERTY(BlueprintAssignable, Category = "GoNoGo|LaunchEvents")
	FUIStage1FuelPressurized Stage1FuelPressurized;

	UPROPERTY(BlueprintAssignable, Category = "GoNoGo|LaunchEvents")
	FUIStage2FuelPressurized Stage2FuelPressurized;

	UPROPERTY(BlueprintAssignable, Category = "GoNoGo|LaunchEvents")
	FUIWindPulsed WindPulsed;
};
