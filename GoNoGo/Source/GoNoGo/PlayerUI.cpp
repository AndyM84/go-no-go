// Fill out your copyright notice in the Description page of Project Settings.

#include "GoNoGo.h"
#include "PlayerUI.h"

UPlayerUI::UPlayerUI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	this->_stage1Load = this->_stage1Pressure = this->_stage2Load = this->_stage2Pressure = FVector2D(0.0, 0.0);
	this->_hours = 0;
	this->_minutes = 0;
	this->_seconds = 56;
	this->_windAngle = 23;
	this->_counter = 0;

	return;
}

void UPlayerUI::NativeTick(const FGeometry &MyGeometry, float InDeltaTime)
{
	DidTick(InDeltaTime);
}

void UPlayerUI::DidTick_Implementation(float &DeltaTime)
{
	return;
}

void UPlayerUI::ReceiveTick(FVector2D &Stage1FuelLoad, FVector2D &Stage2FuelLoad, FVector2D &Stage1FuelPressure, FVector2D &Stage2FuelPressure, float &WindDirection, int32 &Hours, int32 &Minutes, int32 &Seconds)
{
	if (this->_seconds > 0 && this->_counter == 30)
	{
		this->_seconds -= 1;
		this->_counter = 0;
	}
	else
	{
		if (this->_minutes > 0)
		{
			this->_minutes--;
			this->_seconds = 60;
		}

		this->_counter++;
	}

	this->_stage1Load.X += 0.0023;
	this->_stage1Load.Y += 0.032;
	this->_stage2Load.X += 0.1;
	this->_stage2Load.Y += 0.0005;

	this->_stage1Pressure.X = 0.12;
	this->_stage1Pressure.Y = 0.34;
	this->_stage2Pressure.X = 0.73;
	this->_stage2Pressure.Y = 0.44;

	Stage1FuelLoad = this->_stage1Load;
	Stage2FuelLoad = this->_stage2Load;
	Stage1FuelPressure = this->_stage1Pressure;
	Stage2FuelPressure = this->_stage2Pressure;
	WindDirection = this->_windAngle;
	Hours = this->_hours;
	Minutes = this->_minutes;
	Seconds = this->_seconds;

	this->OnTickReceived.Broadcast(12.0);

	return;
}
